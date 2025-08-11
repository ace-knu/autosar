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

/// @brief Implementation of the interface for machine state client adapter.
/// @note Project: Adaptive Platform Test Applications
/// @ingroup MachineStateManager

#ifndef INC_MSCLIENTADAPTER_H_
#define INC_MSCLIENTADAPTER_H_

#include <ara/exec/state_client.h>
#include <string>

#include "i_ms_client_adapter.h"
#if defined(EM_ARA_LOG_MODE)
#include "ara/log/logging.h"
#endif

/// Files included in state_client.h as no interface files before a new version
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

namespace mga {
namespace autoever {
namespace sample {


/** Implementation of the interface for machine state client adapter. */
class MsClientAdapter : public IMsClientAdapter
{
private:
    /** Machine State Client that facilitates machine state related queries to the Execution Manager. */
    ara::exec::StateClient msClient;

    /// @brief Reference to logger instance.
#if !defined(EM_ARA_LOG_MODE)
    std::ostream& log_;
#else
    ara::log::Logger& log_;
#endif
public:
    /** Constructor
     *
     */
    MsClientAdapter();

    /** Destructor
     *
     */
    ~MsClientAdapter();

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     * \param[in]   requestedMachineState   See interface declaration for comments.
     */
    void SetMachineState(std::string requestedMachineState);

    /** Implementation of method declared in interface. Please see interface declaration for further comments.
     *
     * \return    See interface declaration for comments.
     */
    std::string GetMachineState();
};

}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_MSCLIENTADAPTER_H_ */
