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

/// @brief Exceptions used in Machine State Manager.
/// @note Project: Adaptive Platform Test Applications
/// @ingroup MachineStateManager

#ifndef INC_MSMEXCEPTIONS_H_
#define INC_MSMEXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace mga {
namespace autoever {
namespace sample {


/** Generic exception to derive exceptions for specific contexts. */
class CustomMsException : public std::runtime_error
{
private:
    /** Message of exception. */
    std::string message;

public:
    /** Constructor
     *
     * \param[in]   messageArg    Message of exception.
     */
    CustomMsException(const std::string& messageArg)
        : std::runtime_error(messageArg)
        , message(messageArg)
    {}

    /** Returns message of the exception.
     *
     * \return  The message.
     */
    virtual const char* what() const throw()
    {
        return message.c_str();
    }
};

/** Exception for errors while trying to set a new machine state. */
class MsSetterException : public CustomMsException
{
public:
    /** Constructor
     *
     * \param[in]   messageArg    Message of exception.
     */
    MsSetterException(const std::string& messageArg)
        : CustomMsException(messageArg)
    {}
};

/** Exception for errors while trying to query the current machine state. */
class MsGetterException : public CustomMsException
{
public:
    /** Constructor
     *
     * \param[in]   messageArg    Message of exception.
     */
    MsGetterException(const std::string& messageArg)
        : CustomMsException(messageArg)
    {}
};

/** Exception for errors while trying to establish handling of posix signals. */
class SigactionRegistrationException : public CustomMsException
{
public:
    /** Constructor
     *
     * \param[in]   messageArg    Message of exception.
     */
    SigactionRegistrationException(const std::string& messageArg)
        : CustomMsException(messageArg)
    {}
};


}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif /* INC_MSMEXCEPTIONS_H_ */
