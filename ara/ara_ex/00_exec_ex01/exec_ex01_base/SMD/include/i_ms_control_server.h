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

/// @brief Interface for classes, that handle queries for the current machine state as well as requests to change the
/// machine state.
/// @note Project: Adaptive Platform Test Applications
/// @ingroup MachineStateManager

#ifndef INC_IMSCONTROLSERVER_H_
#define INC_IMSCONTROLSERVER_H_

#include <string>
#include <functional>

#include "ms_client_adapter.h"

namespace mga {
namespace autoever {
namespace sample {

/** Interface for classes, that handle queries for the current machine state
 * as well as requests to change the machine state. */

const std::string kSelectIsNotWorking("SelectIsNotWorking");

class IMsControlServer
{
public:
    /** Destructor
     *
     */
    virtual ~IMsControlServer()
    {}

    /** Initialize object.
     *
     */
    virtual void Init() = 0;

    /** Uninitialize object.
     * NOTE: This function needs to trigger ReceiveMachineStateChangeRequest to return.
     *
     */
    virtual void DeInit() = 0;

    /** Receive request for a change of the machine state. Returns once a request is received or if control server
     * is deinitialized (see method DeInit).
     *
     * \return    Requested machine state.
     */
    virtual std::string ReceiveMachineStateChangeRequest() = 0;

    /** Register a getter function for the machine state, that is used to answer queries for
     * the current machine state.
     *
     * \param[in]   machineStateGetter    Getter function for the machine state.
     */
    virtual void SetMachineStateGetter(std::function<std::string()> machineStateGetter) = 0;
};

}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_IMSCONTROLSERVER_H_ */
