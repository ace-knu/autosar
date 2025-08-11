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

/**
 * \brief Implementation of console command that can request state changes of the
 * execution manager. Shoul only be used for debugging purposes
 * \note     Project: Adaptive Platform Test Applications
 */

#include <atomic>
#include <sstream>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "shell_ms_control_server.h"
#if defined(EM_ARA_LOG_MODE)
#include "ara/log/logging.h"
#endif
#include "log.h"

/*___________________________________________________________________________________________________________
 * main
 */
int main()
{
    int32_t flags(O_WRONLY | O_NONBLOCK);
    int32_t pipe_ = open(mga::autoever::sample::kMachineStatControlPath.c_str(), flags, S_IRUSR | S_IWUSR | S_IWGRP);
    std::string req_state;

#if !defined(EM_ARA_LOG_MODE)
    std::ostream& log_{std::cout};
#else
    ara::log::InitLogging ("state", "state dlt log",
                            ara::log::LogLevel::kDebug, (ara::log::LogMode::kConsole | ara::log::LogMode::kRemote) , "/tmp/state.log");
    ara::log::Logger& log_{ara::log::CreateLogger("state", "state log")};
#endif

#if defined(EM_ARA_LOG_MODE)
    log_.LogInfo() << "@@@ ara-state-change start ###";
#else
    TRACE_INFO( "@@@ ara-state-change start ###");
#endif

    if (-1 == pipe_) {
        std::cerr << "Cannot open commuincation to machine state server." << std::endl;
        return -1;
    }
    while(1) {
        std::cout << "Please input machine state : ";
        std::cin >> req_state ;

        if (req_state.size() == 0)
            continue;

        if ( req_state.compare("exit") == 0
             || req_state.compare("quit") == 0
             || req_state.compare("q") == 0
             ) {
            std::cout << "exit program" << std::endl;
            break;
        }

        std::cout << "Requesting state " << req_state << std::endl;
        auto result = ::write(pipe_, req_state.c_str(), req_state.size() + 1);
        if(result == -1) {
#if defined(EM_ARA_LOG_MODE)
            log_.LogWarn() << "fail to write, errno " << errno;
#else
            TRACE_WARNING( "fail to write, errno " << errno);
#endif
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000U));

        if ( req_state.compare("Shutdown") == 0
             || req_state.compare("Restart") == 0
             ) {
            std::cout << "exit" << std::endl;
            break;
        }
    }

    if (pipe_ > 0) {
        ::close(pipe_);
    }
#if defined(EM_ARA_LOG_MODE)
    log_.LogInfo() << "@@@ ara-state-change end ###";
#else
    TRACE_INFO( "@@@ ara-state-change end ###");
#endif

    return 0;
}
