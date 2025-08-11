/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <csignal>

#include <ara/exec/execution_client.h>
#include <ara/log/logging.h>

#include "em_app2.h"

/**********************************************************************************************************************
 *  VARIABLES
 *********************************************************************************************************************/
ara::exec::ExecutionClient exec_client;
std::atomic<bool>exit_requested(false);
ara::log::Logger& logger{CreateLogger("CTX2", "EM APP2", ara::log::LogLevel::kVerbose)};
int32_t app_num;

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/
void ThreadAct1()
{
    logger.LogInfo() << "======================================= APP2 is running.";
    mga::autoever::sample::EmApp2 app2(app_num);
    app2.Init();

    while (1) {
        app2.Act();

        // sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

        if(exit_requested.load()) {
            break;
        }
    }
    logger.LogInfo() << "Application is Run exit.";
}

void handle_signal(int _signal) {
    if(!exit_requested.load() && (_signal == SIGINT || _signal == SIGTERM)) {
        logger.LogInfo() << "received signal:" << _signal;
        exit_requested.store(true);
    }
}

int main(int argc, char* argv[])
{
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kRunning);

    logger.LogInfo() << "WAIT signal:";
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    logger.LogInfo() << "Application will be initialized.";
    if (argc > 1) {
        if (strncmp (argv[1],"--POS=FL", strlen(argv[1])) == 0) {
            //instance1 is executed
            app_num = 1;
        }
        else {
            //instance2 is executed
            app_num = 2;
        }
    }

    std::thread act1(ThreadAct1);

    act1.join();

    logger.LogInfo() << "APP2:Application shutdown initiated.";

    exec_client.ReportExecutionState(ara::exec::ExecutionState::kTerminating);

    logger.LogInfo() << "Application shutdown is done.";

    return 0;
}
