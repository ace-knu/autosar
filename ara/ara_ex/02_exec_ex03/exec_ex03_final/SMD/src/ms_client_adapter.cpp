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

#include <sstream>

#include "ms_client_adapter.h"

#include "msm_exceptions.h"
#include "log.h"

#include "ara/core/string.h"
#if defined(EM_ARA_LOG_MODE)
#include "ara/log/logging.h"
#endif

using ara::exec::FunctionGroup;
using ara::exec::FunctionGroupState;

namespace
{
/** Number of trys to call a mstate API before the function is aborted */
constexpr uint8_t noOfMStateCallsBeforeAbort = 5u;
/** Number of milliseconds before timeout of StateClient::SetState */
constexpr uint32_t setStateTimeout = 10000u;
/** Number of milliseconds before timeout of StateClient::Register */
constexpr uint32_t registerTimeout = 500u;
/** Number of milliseconds before timeout of StateClient::GetState */
constexpr uint32_t getStateTimeout = 1000u;
/** Directory, where the machine state manager is installed */
//constexpr auto msmRootDirectory = "/opt/machine_state_manager";
/** Standard name for Machine State Function Group */
constexpr char kMachineFunctionGroupName[] = "MachineState";
}  // namespace

namespace mga {
namespace autoever {
namespace sample {

/*___________________________________________________________________________________________________________
 * Private function definitions
 */

/*___________________________________________________________________________________________________________
 * Public function definitions
 */

MsClientAdapter::MsClientAdapter()
    : msClient()
#if !defined(EM_ARA_LOG_MODE)
    , log_{std::cout}
#else
    , log_{ara::log::CreateLogger("SMD1", "SMD1 log", ara::log::LogLevel::kVerbose)}
#endif

{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Object created.";
#else
    TRACE_DEBUG("Object created.");
#endif
}

MsClientAdapter::~MsClientAdapter()
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Object deleted.";
#else
    TRACE_DEBUG("Object deleted.");
#endif
}

void MsClientAdapter::SetMachineState(std::string requestedMachineState)
{
#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "Request Machine State change to " << requestedMachineState;
#else
    TRACE_DEBUG("Request Machine State change to " << requestedMachineState);
#endif
    //ara::exec::FunctionGroupState state{ara::exec::kMachineFunctionGroupName, requestedMachineState};
    Result<FunctionGroup::CtorToken> groupTokenResult = FunctionGroup::Preconstruct(kMachineFunctionGroupName);
    FunctionGroup::CtorToken groupToken(groupTokenResult.ValueOrThrow());
    FunctionGroup group(std::move(groupToken));
    
    Result<FunctionGroupState::CtorToken> stateTokenResult
        = FunctionGroupState::Preconstruct(group, ara::core::StringView{requestedMachineState.c_str()});
    FunctionGroupState::CtorToken stateToken(stateTokenResult.ValueOrThrow());
    FunctionGroupState state(std::move(stateToken));

#if defined(EM_ARA_LOG_MODE)
    log_.LogInfo() << "@@@ SMD : change state(" << requestedMachineState << ") ###";
#else
    TRACE_INFO( "@@@ SMD : change state(" << requestedMachineState << ") ###");
#endif
    ara::core::Future<void> setStateFuture = msClient.SetState(state);
    ara::core::Result<void> setStateResult = setStateFuture.GetResult();
    if (setStateResult.HasValue()) {
#if defined(EM_ARA_LOG_MODE)
        log_.LogDebug() << "Request successful.";
#else
        TRACE_DEBUG("Request successful.");
#endif
#if defined(EM_ARA_LOG_MODE)
        log_.LogInfo() << "@@@ SMD : SetState(" << requestedMachineState << ") pass ###";
#else
        TRACE_INFO( "@@@ SMD : SetState(" << requestedMachineState << ") pass ###");
#endif
    } else {
#if defined(EM_ARA_LOG_MODE)
        log_.LogInfo() << "@@@ SMD : (" << requestedMachineState << ") fail ###";
#else
        TRACE_INFO( "@@@ SMD : (" << requestedMachineState << ") fail ###");
#endif
        std::stringstream strstr;
        strstr << "Failed to request machine state change to: " << requestedMachineState << ".\n"
               << "Error message: " << setStateResult.Error().Message();
        throw MsSetterException(strstr.str());
    }
}

std::string MsClientAdapter::GetMachineState()
{
    // This method should be removed and the whole app logic is reworked
    // because API "GetState()" was removed from the standard.

#if defined(EM_ARA_LOG_MODE)
    log_.LogDebug() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GetMachineState()";
#else
    TRACE_DEBUG("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GetMachineState()");
#endif

    while (true) {
        auto getMachineStateFuture = msClient.GetInitialMachineStateTransitionResult();
        auto getMachineStateResult = getMachineStateFuture.GetResult();
        if (getMachineStateResult.HasValue()) {
            return "Driving";
        }
    }

    throw MsGetterException("Failed to get current machine state from execution manager.");
}

}  // namespace sample
}  // namespace autoever
}  // namespace mga
