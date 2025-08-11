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
 * \brief Implementation of machine state control server interface, that handles
 * state change requests from a shell command.
 * \note     Project: Adaptive Platform Test Applications
 * \ingroup MachineStateManager
 */

#if defined(EM_ARA_LOG_MODE)
#include <ara/log/logging.h>
#endif  // EM_ARA_LOG_MODE

#include <memory>
#include <mutex>
#include <thread>
#include <sstream>
#include <functional>
#include <unistd.h>
#ifdef QNX
#include <sys/select.h>
#endif

#include "shell_ms_control_server.h"

#include "log.h"

namespace mga {
namespace autoever {
namespace sample {

ShellMsControlServer::ShellMsControlServer()
    : terminate(false)
{
#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("Shell MS object created.");
#endif
}

ShellMsControlServer::~ShellMsControlServer()
{
#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("Object deleted.");
#endif
}

void ShellMsControlServer::Init()
{

#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("ShellMsControlServer Init()");
#endif

    /// fifo creation
    if (::mkfifo(kMachineStatControlPath.c_str(),  S_IRUSR | S_IWUSR | S_IWGRP) == -1
            && errno != EEXIST) {
#if !defined(EM_ARA_LOG_MODE)
        TRACE_FATAL("Failure of FIFO creation");
#endif
        return;
    }

    /// fifo open
    fifo_ = ::open(kMachineStatControlPath.c_str(), O_RDONLY|O_NONBLOCK);
    if (fifo_ == -1) {
#if !defined(EM_ARA_LOG_MODE)
        TRACE_DEBUG("Not possible to open pipe in ShellMsControlServer.");
#endif
    }

}

void ShellMsControlServer::DeInit()
{
#if !defined(EM_ARA_LOG_MODE)
    TRACE_DEBUG("ShellMsControlServer DeInit()");
#endif

    // Close fifo here
    if (fifo_ > 0) {
        ::close(fifo_);
    }

    unlink(kMachineStatControlPath.c_str());
    terminate = true;
}
std::string ShellMsControlServer::ReceiveMachineStateChangeRequest()

{
    std::string rv = "ThisIsNotAValidMachineState";
    char fifo_buffer[100] = {};

    /// select rfds
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(fifo_, &rfds);

    /// __nfds argument
    int32_t fdMax = 0;
    fdMax = std::max(fdMax, fifo_);

    while(!terminate){
        /// timeval argument
        struct timeval timeVal = {kWiatTimeoutSec, kWaitTimeoutUSec};

        /// select for fifo reading, now timeout but need to change to nonblock
        int32_t ret = select(fdMax + 1, &rfds, nullptr, nullptr, &timeVal);
        if (ret == -1) {
#if !defined(EM_ARA_LOG_MODE)
            TRACE_FATAL("fd select is not working");
#endif
            rv = kSelectIsNotWorking;
            break;
        }

        memset(fifo_buffer, 0x00, sizeof (fifo_buffer));
        int32_t read_byte = read(fifo_, &fifo_buffer, sizeof (fifo_buffer));

        if (read_byte > 0) {
#if !defined(EM_ARA_LOG_MODE)
            TRACE_DEBUG("received data : " << fifo_buffer);
#endif
            return fifo_buffer;
        }
    }
    return rv;
}

void ShellMsControlServer::SetMachineStateGetter(std::function<std::string()> machineStateGetterArg)
{
    machineStateGetter = machineStateGetterArg;
}


}  // namespace sample
}  // namespace autoever
}  // namespace mga
