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

/// @brief Interface for adapter class which abstracts the ARA API of machine state client.
/// @note Project: Adaptive Platform Test Applications
/// @ingroup MachineStateManager

#ifndef INC_IMSCLIENTADAPTER_H_
#define INC_IMSCLIENTADAPTER_H_

#include <string>

namespace mga {
namespace autoever {
namespace sample {


/** Interface for adapter class which abstracts the ARA API of
 * machine state client. */
class IMsClientAdapter
{
public:
    /** Destructor
     *
     */
    virtual ~IMsClientAdapter()
    {}

    /** Send request to change machine state to Execution Manager.
     *
     * \param[in]   requestedMachineState   Requested machine state.
     */
    virtual void SetMachineState(std::string requestedMachineState) = 0;

    /** Query current machine state from Execution Manager.
     *
     * \return        Current machine state.
     */
    virtual std::string GetMachineState() = 0;
};


}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_IMSCLIENTADAPTER_H_ */
