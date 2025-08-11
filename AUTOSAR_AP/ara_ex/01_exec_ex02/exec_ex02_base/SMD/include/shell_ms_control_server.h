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
 * requests for machine state changes via a shell command.
 * \note     Project: Adaptive Platform Test Applications
 * \ingroup MachineStateManager
 */

#ifndef INC_SHELLMSCONTROLSERVER_H_
#define INC_SHELLMSCONTROLSERVER_H_

#include <memory>
#include <string>

#include "i_ms_control_server.h"

namespace mga {
namespace autoever {
namespace sample {

const std::string kMachineStatControlPath(MGA_CONFIG_MGA_VOLATILE_DIR"/mga_emd/SMD/exec/machine-state-control");

constexpr uint32_t kWiatTimeoutSec = 0U;
constexpr uint32_t kWaitTimeoutUSec = 100000U; /* 100 ms */

/** Implementation of machine state control server interface, that handles
 * requests for machine state changes. */
class ShellMsControlServer : public mga::autoever::sample::IMsControlServer
{
private:
    /** Getter function to forward query for the current machine state to the execution management API. */
    std::function<std::string()> machineStateGetter;
    /** Flag, that indicates, that program is terminating. */
    std::atomic<bool> terminate;

    /**
     * \brief The Filedescriptor where the named pipe is opened.
     */
    int fifo_;

public:
    /** Constructor
     *
     */
    ShellMsControlServer();

    /** Destructor
     *
     */
    ~ShellMsControlServer();

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     */
    void Init();

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     */
    void DeInit();

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     * \return    See interface declaration for comments.
     */
    std::string ReceiveMachineStateChangeRequest();

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     * \param[in]   machineStateGetter    See interface declaration for comments.
     */
    void SetMachineStateGetter(std::function<std::string()> machineStateGetter);
};


}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_DIAGNOSTICSMSCONTROLSERVER_H_ */
