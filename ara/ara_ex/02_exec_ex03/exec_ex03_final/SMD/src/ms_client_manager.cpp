
// --------------------------------------------------------------------------
// |              _    _ _______     .----.      _____         _____        |
// |         /\  | |  | |__   __|  .  ____ .    / ____|  /\   |  __ \       |
// |        /  \ | |  | |  | |    .  / __ \ .  | (___   /  \  | |__) |      |
// |       / /\ \| |  | |  | |   .  / / / / v   \___ \ / /\ \ |  _  /       |
// |      / /__\ \ |__| |  | |   . / /_/ /  .   ____) / /__\ \| | \ \       |
// |     /________\____/   |_|   ^ \____/  .   |_____/________\_|  \_\      |
// |                              . _ _  .                                  |
// --------------------------------------------------------------------------
//
// All Rights Reserved.
// Any use of this source code is subject to a license agreement with the
// AUTOSAR development cooperation.
// More information is available at www.autosar.org.
//
// Disclaimer
//
// This work (specification and/or software implementation) and the material
// contained in it, as released by AUTOSAR, is for the purpose of information
// only. AUTOSAR and the companies that have contributed to it shall not be
// liable for any use of the work.
//
// The material contained in this work is protected by copyright and other
// types of intellectual property rights. The commercial exploitation of the
// material contained in this work requires a license to such intellectual
// property rights.
//
// This work may be utilized or reproduced without any modification, in any
// form or by any means, for informational purposes only. For any other
// purpose, no part of the work may be utilized or reproduced, in any form
// or by any means, without permission in writing from the publisher.
//
// The work has been developed for automotive applications only. It has
// neither been developed, nor tested for non-automotive applications.
//
// The word AUTOSAR and the AUTOSAR logo are registered trademarks.
// --------------------------------------------------------------------------

/// @brief Class to set up machine state client and control server and orchestrate their communication.
/// @note Project: Adaptive Platform Test Applications
/// @ingroup MachineStateManager

#include "ms_client_manager.h"

#include <chrono>
#include <mutex>
#include <string>
#include <thread>

#if defined(EM_ARA_LOG_MODE)
#include <ara/log/logging.h>
#endif  // EM_ARA_LOG_MODE

#include "msm_exceptions.h"
#include "log.h"

namespace
{
/** Period for checking the value of the terminate flag
in the loop for receiving machine-state-change requests. */
constexpr auto terminateCheckPeriod = std::chrono::milliseconds(1000);

constexpr auto kDrivingState  {"Driving"};
//constexpr auto kParkingState  {"Parking"};
//constexpr auto kShutDownState {"Shutdown"};
//constexpr auto kStartupState  {"Startup"};
//constexpr auto kRestartState  {"Restart"};

}  // namespace

namespace mga {
namespace autoever {
namespace sample {


/*___________________________________________________________________________________________________________
 * Private function definitions
 */

void MsClientManager::SetUpControlServer()
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Setting up machine state client control server";
#else
    TRACE_DEBUG("Setting up machine state client control server");
#endif
    for (std::vector<IMsControlServer>::size_type i = 0; i < msControlServerVector.size(); i++) {
        msControlServerVector[i]->Init();
        msControlServerVector[i]->SetMachineStateGetter([this]() { return msClientAdapter->GetMachineState(); });
    }
}

void MsClientManager::ReceiveRequestsOfServer(const uint32_t controlServerIndex)
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Thread for receiving of requests for machine state changes spawned. thread :: " << controlServerIndex;
#else
    TRACE_DEBUG("Thread for receiving of requests for machine state changes spawned. thread :: " << controlServerIndex);
#endif
    while (false == terminate) {
        std::string requestedMachineState
            = msControlServerVector.at(controlServerIndex)->ReceiveMachineStateChangeRequest();

        std::unique_lock<std::mutex> queueLock(queueMutex);
        stateRequestQueue.push(requestedMachineState);

        stateRequestCondVar.notify_all();
#if defined(EM_ARA_LOG_MODE)
        log_.LogDebug() << "MsClientManager::ReceiveRequestsOfServer while thread : " << controlServerIndex;
#else
        TRACE_DEBUG("MsClientManager::ReceiveRequestsOfServer while thread : " << controlServerIndex);
#endif
    }
}

void MsClientManager::ProcessRequestsInQueue()
{
    while (false == stateRequestQueue.empty()) {
        std::string requestedMachineState = stateRequestQueue.front();
        stateRequestQueue.pop();

        if(requestedMachineState.compare(kSelectIsNotWorking) == 0){
#if !defined(EM_ARA_LOG_MODE)
            TRACE_DEBUG("Break because of : " << kSelectIsNotWorking);
#endif
            break;
        }
        try {
            msClientAdapter->SetMachineState(requestedMachineState);
        } catch (const MsSetterException& exception) {
#if defined(EM_ARA_LOG_MODE)
            log_.LogDebug() << "Caught exception: " << exception.what();
#else
            TRACE_DEBUG("Caught exception: " << exception.what());
#endif
        } catch (const MsGetterException& exception) {
#if defined(EM_ARA_LOG_MODE)
            log_.LogDebug() << "Caught exception: " << exception.what();
#else
            TRACE_DEBUG("Caught exception: " << exception.what());
#endif
        }
    }
}

/*___________________________________________________________________________________________________________
 * Public function definitions
 */

MsClientManager::MsClientManager(std::vector<std::unique_ptr<IMsControlServer>>&& controlServerVector,
    std::unique_ptr<IMsClientAdapter>&& clientAdapter)
    : msControlServerVector(std::move(controlServerVector))
    , serverThreads(msControlServerVector.size())
    , msClientAdapter(std::move(clientAdapter))
    , terminate(false)
#if !defined(EM_ARA_LOG_MODE)
    , log_{std::cout}
#else
    , log_{ara::log::CreateLogger("SMD", "SMD log", ara::log::LogLevel::kVerbose)}
#endif

{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Object created.";
#else
    TRACE_DEBUG("Object created.");
#endif
}

MsClientManager::~MsClientManager()
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Object deleted.";
#else
    TRACE_DEBUG("Object deleted.");
#endif
}

void MsClientManager::Init()
{
    SetUpControlServer();
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kRunning);
#if defined(EM_ARA_LOG_MODE)
    log_.LogInfo() << "@@@ SMD start ###";
#else
    TRACE_INFO( "@@@ SMD start ###");
#endif
}

void MsClientManager::SetMachineStateToDriving()
{
    msClientAdapter->SetMachineState(kDrivingState);
}

void MsClientManager::Run()
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Run()";
#else
    TRACE_DEBUG("Run()");
#endif

    /* Start the threads in which requests for machine state changes are received. */
    for (std::vector<IMsControlServer>::size_type i = 0; i < serverThreads.size(); i++) {
        serverThreads[i] = std::thread(&MsClientManager::ReceiveRequestsOfServer, this, i);
#if defined(EM_ARA_LOG_MODE)
        log_.LogDebug() << "serverThreads " << i;
#else
        TRACE_DEBUG("serverThreads " << i);
#endif
    }

    while (false == terminate) {
        /* Wait until requests for machine state changes are received or waiting period has expired.
        The latter is necessary, so the value of the terminate flag is checked periodically. */
        std::unique_lock<std::mutex> queueLock(queueMutex);
        stateRequestCondVar.wait_for(
            queueLock, terminateCheckPeriod, [this]() { return ((false == stateRequestQueue.empty()) || terminate); });
        ProcessRequestsInQueue();
    }

    Terminate();
}

void MsClientManager::Terminate()
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Terminating";
#else
    TRACE_DEBUG("Terminating");
#endif
#if defined(EM_ARA_LOG_MODE)
    log_.LogInfo() << "@@@ SMD end ###";
#else
    TRACE_INFO( "@@@ SMD end ###");
#endif

    terminate = true;
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kTerminating);

    for (std::vector<IMsControlServer>::size_type i = 0; i < msControlServerVector.size(); i++) {
        msControlServerVector.at(i)->DeInit();
        if (true == serverThreads.at(i).joinable()) {
#if defined(EM_ARA_LOG_MODE)
            log_.LogDebug() << "Trying to join thread " + std::to_string(i);
#else
            TRACE_DEBUG("Trying to join thread " + std::to_string(i));
#endif
            serverThreads.at(i).join();
#if defined(EM_ARA_LOG_MODE)
            log_.LogDebug() << "Thread joined.";
#else
            TRACE_DEBUG("Thread joined.");
#endif
        }
    }

    stateRequestCondVar.notify_all();
}

void MsClientManager::SetTerminate(const bool terminateArg)
{
    terminate = terminateArg;
}


}  // namespace sample
}  // namespace autoever
}  // namespace mga
