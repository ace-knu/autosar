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

#ifndef INC_MSCLIENTMANAGER_H_
#define INC_MSCLIENTMANAGER_H_

#include <ara/exec/execution_client.h>
#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include "i_ms_control_server.h"
#include "ms_client_adapter.h"
#if defined(EM_ARA_LOG_MODE)
#include "ara/log/logging.h"
#endif

namespace mga {
namespace autoever {
namespace sample {

/** Class to set up machine state client and control server and orchestrate their communication. */
class MsClientManager
{
private:
    /** Machine state control server, that receive requests for state changes or the current machine state. */
    std::vector<std::unique_ptr<IMsControlServer>> msControlServerVector;
    /** Threads in which the machine state control servers receive requests. */
    std::vector<std::thread> serverThreads;
    /** Client, that reports the application state to the Execution Manager. */
    ara::exec::ExecutionClient exec_client;
    /** Adapter to the ARA machine state client class. */
    std::unique_ptr<IMsClientAdapter> msClientAdapter;
    /** Flag indicating that application is shutting down. */
    std::atomic<bool> terminate;
    /** Mutex to protect queue from race conditions. */
    std::mutex queueMutex;
    /** Queue of pending requests for machine state changes. */
    std::queue<std::string> stateRequestQueue;
    /** Condition variable to facilitate notification of new requests from server threads. */
    std::condition_variable stateRequestCondVar;

    /// @brief Reference to logger instance.
#if !defined(EM_ARA_LOG_MODE)
    std::ostream& log_;
#else
    ara::log::Logger& log_;
#endif

    /** Make control servers ready for use.
     *
     */
    void SetUpControlServer();

    /** Handle requests received by server in infinite loop by putting them into the queue.
     *
     * \param[in]   controlServerIndex   Vector index of control server which receives requests.
     */
    void ReceiveRequestsOfServer(const uint32_t controlServerIndex);

    /** Process all pending state change requests in the queue.
     *
     */
    void ProcessRequestsInQueue();

public:
    /** Constructor
     *
     * \param[in]       controlServer   Vector of (multiple) control server which receive requests.
     * \param[in]       clientAdapter   Adapter to the machine state client, connecting us to the Execution Manager.
     */
    MsClientManager(std::vector<std::unique_ptr<IMsControlServer>>&& controlServer,
        std::unique_ptr<IMsClientAdapter>&& clientAdapter);

    /** Destructor
     *
     */
    ~MsClientManager();

    /** Initialize object.
     *
     */
    void Init();

    /** Send request to change machine state to "Driving" to the Execution Manager.
     *
     */
    void SetMachineStateToDriving();

    /** Start normal operation mode in which requests and queries are received and forwarded.
     * Won't return until Terminate() is called.
     *
     */
    void Run();

    /** Shut down all objects to terminate application.
     *
     */
    void Terminate();

    /** Set terminate flag.
     *
     * \param[in]       terminateArg    Value to which member variable terminate will be set.
     */
    void SetTerminate(const bool terminateArg);
};


}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_MSCLIENTMANAGER_H_ */
