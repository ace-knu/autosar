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

///////////////////////////////////////////////////////////////////////
// This is just a test main to test the communication API
// The different components radar, video, tester, ... are used in one
// application. This could be also different applications but we
// currently have no mechanism implemeted for inter-process-communication
// between applications. We also have no execution environment in use here
// I.e. this code as nothing to do with the communication or execution API
///////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include <stdint.h>
#include <thread>
#include <chrono>
#include <csignal>

#include <ara/exec/execution_client.h>
#define ARALOGSTYLE_1803
#ifndef ARALOGSTYLE_1803
#include <ara/log/logmanager.h>
#endif
#include <ara/log/logging.h>

#include "radar_activity.h"

using namespace ara::log;  // 'using' is OK for ara::log

ara::exec::ExecutionClient exec_client;
std::atomic<bool>quit(false);
#ifdef ARALOGSTYLE_1803
    ara::log::Logger& logger{CreateLogger("CTX", "defaultLogContext")};
#else
    ara::log::Logger& logger = ara::log::LogManager::defaultLogContext();
#endif

void ThreadAct1()
{
    radar::RadarActivity actRadar;
    actRadar.init();

    while (1) {
        actRadar.act();
        // sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        if(quit.load()) {
            break;
        }
    }
}

void handle_signal(int _signal) {
    if(!quit.load() && (_signal == SIGINT || _signal == SIGTERM)) {
        logger.LogInfo() << "================ Radar Terminate ================";
        exec_client.ReportExecutionState(ara::exec::ExecutionState::kTerminating);
        quit.store(true);
    }
}

int main(int argc, char* argv[])
{
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kRunning);
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    ara::log::InitLogging("ACRA", "example app. radar", LogLevel::kVerbose, (LogMode::kRemote | LogMode::kConsole));

    logger.LogInfo() << "@@@ Radar start ###";

    logger.LogInfo() << "Ok, let's produce some radar data...";
    std::thread act1(ThreadAct1);

    act1.join();

    logger.LogInfo() << "done.";
    return 0;
}
