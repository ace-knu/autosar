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

/*!
 *  \file
 *  \brief Specification of radar activity.
 *
 *  \details Contains specification of radar activity.
 *  Stub for an activity, can be completely generated from the model. It includes the generic API of an activity and the
 * activity specific data access points (event sender/receiver, ...).
 */

#ifndef CM_PROVIDERSUBSCRIBERSCENARIO_RADAR_INC_RADAR_ACTIVITY_HPP_
#define CM_PROVIDERSUBSCRIBERSCENARIO_RADAR_INC_RADAR_ACTIVITY_HPP_

#include <string>
#include <random>
#include <vector>

#include "ara/log/logging.h"
#include "ara/core/future.h"
#include "ara/core/promise.h"

// includes for used services
#include "ara/com/sample/radar_skeleton.h"

// TP data sample test case
//#define TP_TEST

namespace radar
{
// Header of Methods Output Messages.
constexpr auto METHODS_HEADER = "METHODS: ";
constexpr auto FIELDS_HEADER = "FIELDS: ";
constexpr auto ERROR_HEADER = "APPLICATION_ERROR: ";

static std::vector<std::string> App_Test_Result;
/*!
 *  \brief Class implementing skeleton methods.
 *
 *  Radar's implementation.
 *
 *  \uptrace{SWS_CM_00191}
 */
class radarImp : public ara::com::sample::skeleton::radarSkeleton
{
    using Skeleton = ara::com::sample::skeleton::radarSkeleton;

public:
    radarImp(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode)
        : Skeleton(std::move(instanceSpec), mode)
        , m_worker(&radarImp::ProcessRequests, this)
        , m_adjust_count(0)
        , m_calibrate_count(0)
        , m_rand_eng(m_rd())
        , m_ud_0_100(0, 100)
    {}

   radarImp(ara::com::InstanceIdentifier instanceIdent, ara::com::MethodCallProcessingMode mode)
        : Skeleton(instanceIdent, mode)
        , m_worker(&radarImp::ProcessRequests, this)
        , m_adjust_count(0)
        , m_calibrate_count(0)
        , m_rand_eng(m_rd())
        , m_ud_0_100(0, 100)
    {}

    virtual ~radarImp()
    {
        m_finished = true;
        m_worker.join();
    }

    virtual auto Adjust(const ara::com::sample::Position& target_position)
        -> decltype(Skeleton::Adjust(target_position)) override;
    virtual auto Calibrate(const String& configuration, const ara::com::sample::FusionVariant& variant)
        -> decltype(Skeleton::Calibrate(configuration, variant)) override;
    /// @uptrace{SWS_CM_90435}
    virtual void Echo(const String& text) override;
    virtual auto testFloat(const float& in1) -> decltype(Skeleton::testFloat(in1)) override;
    virtual auto testDouble(const double& in1) -> decltype(Skeleton::testDouble(in1)) override;

private:
    /*!
     * \brief Defines how the incoming service method invocations are processed.
     *
     * \uptrace{SWS_CM_00198}
     * \uptrace{SWS_CM_00199}
     */
    void ProcessRequests();

    std::atomic<bool> m_finished{false};
    std::thread m_worker;
    std::uint32_t m_adjust_count;
    std::uint32_t m_calibrate_count;
    std::random_device m_rd;
    std::default_random_engine m_rand_eng;
    std::uniform_int_distribution<std::uint16_t> m_ud_0_100;

    //ara::log::Logger& m_logger_ctx1{ara::log::CreateLogger("CTX1", "context for adjustment", ara::log::LogLevel::kVerbose)};
    //ara::log::Logger& m_logger_ctx2{ara::log::CreateLogger("CTX2", "context for calibration", ara::log::LogLevel::kVerbose)};
    //ara::log::Logger& m_logger_ctx5{ara::log::CreateLogger("CTX5", "context for echo", ara::log::LogLevel::kVerbose)};
    ara::log::Logger& m_logger_ctx1{ara::log::CreateLogger("CTX1", "context for adjustment")};
    ara::log::Logger& m_logger_ctx2{ara::log::CreateLogger("CTX2", "context for calibration")};
    ara::log::Logger& m_logger_ctx5{ara::log::CreateLogger("CTX5", "context for echo")};
};

/*!
 *  \brief Class implementing radar activity.
 *
 *  Radar activity implementing function of radar.
 */
class RadarActivity
{
public:
    RadarActivity();
    ~RadarActivity();

    /*!
     *  \brief Initializes radar activity.
     *
     *  Initializes radar activity. This is called during initialization of the runtime.
     */
    void init();

    /*!
     *  \brief Runs radar activity.
     *
     *  Executable unit triggered to perform radar activity.
     */
    void act();

protected:
    /*!
     * Override the field Update Rate Getter, to be registered by RegisterGet.
     * {SWS_CM_00114}
     * ara::core::Future<ara::com::sample::skeleton::fields::UpdateRate::value_type> getUpdateRate();
     */
    ara::core::Future<ara::com::sample::skeleton::radar::fields::UpdateRate::value_type> getUpdateRate();

    /*!
     * Override the field RearObjectDistance Getter, to be registered by RegisterGet.
     * {SWS_CM_00114}
     * ara::com::Future<ara::com::sample::skeleton::fields::RearObjectDistance::value_type> getUpdateRate();
     */
    ara::core::Future<ara::com::sample::skeleton::radar::fields::RearObjectDistance::value_type> getRearObjectDistance();

    /*!
     * Override the field Update Rate Setter, to be registered by RegisterSet.
     * ara::com::Future<std::uint32_t> setUpdateRate(std::uint32_t field);
     */
    ara::core::Future<std::uint32_t> setUpdateRate(std::uint32_t field);

    /*!
     * Override the field RearObjectDistance Setter, to be registered by RegisterSet.
     * ara::com::Future<std::uint16_t> setUpdateRate(std::uint16_t field);
     */
    ara::core::Future<std::uint16_t> setObjectDetectionLimit(std::uint16_t field);

    /*!
     * \brief A pointer to the skeleton object.
     */
    ara::com::sample::skeleton::radarSkeleton* m_skeleton;
    std::uint32_t m_update_rate;
    std::uint16_t m_object_limit;
    std::random_device m_rd;
    std::default_random_engine m_rand_eng;
    std::uniform_int_distribution<std::uint16_t> m_ud_0_100;
    std::uniform_int_distribution<std::uint16_t> m_ud_0_50;

    enum class internalStates {READY, NOT_READY, RETURN_ERROR};
    internalStates m_internal_state_for_update_rate_set_handler = internalStates::READY;
    internalStates m_internal_state_for_update_rate_get_handler = internalStates::READY;

    ara::log::Logger& m_logger_ctx3{ara::log::CreateLogger("CTX3", "context for update rate", ara::log::LogLevel::kVerbose)};
};
}  // namespace radar

#endif  // CM_PROVIDERSUBSCRIBERSCENARIO_RADAR_INC_RADAR_ACTIVITY_HPP_
