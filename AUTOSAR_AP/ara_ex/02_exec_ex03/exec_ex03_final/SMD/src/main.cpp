
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <signal.h>

#include <cstdlib>
#include <exception>
#include <memory>
#include <stdexcept>

#if defined(EM_ARA_LOG_MODE)
#include <ara/log/logging.h>
#endif  // EM_ARA_LOG_MODE

#include "shell_ms_control_server.h"
#include "i_ms_control_server.h"
#include "ms_client_adapter.h"
#include "ms_client_manager.h"
#include "msm_exceptions.h"

#include "log.h"

/** MsClientManager instance. */
std::unique_ptr<mga::autoever::sample::MsClientManager> msClientManager;

void DismantleMsm()
{
    if (nullptr != msClientManager) {
        msClientManager->Terminate();
        msClientManager.reset();
    }
}

/** Function takes over if exception handling is abandoned. */
void HandleTerminate()
{
#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("Exception handling abandoned. Terminate handler called.");
#endif
    DismantleMsm();
    std::abort();
}

/** Handle a POSIX signal from the OS. */
void HandlePosixSignal(int32_t sigNum)
{
#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("Received signal: " << sigNum << " --> terminating.");
#endif
    if (nullptr != msClientManager) {
        msClientManager->SetTerminate(true);
    }
}

/** Register handler for POSIX signals from the OS. */
void RegisterSignalHandler()
{
    struct sigaction act;

    /* Register a signal handler */
    memset(&act, '\0', sizeof(act));
    act.sa_handler = &HandlePosixSignal;

    if (sigaction(SIGINT, &act, NULL) < 0) {
        throw mga::autoever::sample::SigactionRegistrationException("Error: sigaction");
    } else if (sigaction(SIGTERM, &act, NULL) < 0) {
        throw mga::autoever::sample::SigactionRegistrationException("Error: sigaction");
    }
}

/*___________________________________________________________________________________________________________
 * main
 */
int main()
{

    // Register application for logging.
   //ara::log::InitLogging ("SMD", "SMD dlt log",
   //                        ara::log::LogLevel::kDebug, (ara::log::LogMode::kConsole | ara::log::LogMode::kRemote) , "/tmp/smd.log");

    std::set_terminate(HandleTerminate);
    RegisterSignalHandler();

    try {
        std::vector<std::unique_ptr<mga::autoever::sample::IMsControlServer>> msControlServerVector;

        auto shellMsControlServer = std::make_unique<mga::autoever::sample::ShellMsControlServer>();
        msControlServerVector.push_back(std::move(shellMsControlServer));

        auto msClientAdapter = std::make_unique<mga::autoever::sample::MsClientAdapter>();

        msClientManager = std::make_unique<mga::autoever::sample::MsClientManager>(
            std::move(msControlServerVector), std::move(msClientAdapter));
        msClientManager->Init();
        msClientManager->Run();
        msClientManager.reset();
    } catch (const std::exception& exception) {
#if !defined(EM_ARA_LOG_MODE)
        TRACE_DEBUG("Caught exception. Message: " << exception.what());
#endif
        DismantleMsm();
    } catch (...) {
#if !defined(EM_ARA_LOG_MODE)
        TRACE_DEBUG("Caught unknown exception.");
#endif
        DismantleMsm();
    }

#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("Main ending.");
#endif
    return 0;
}
