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
// Activity specific implementation, skeleton can be generated from the model
// Discovery of services and sending/receiving of data according
// to the communication API
///////////////////////////////////////////////////////////////////////

#include "fusion_activity.h"

#include <stdint.h>

#include <iomanip>
#include <cstdlib>
#include <exception>
#include <cassert>
#include <iostream>

// includes for used services
#include "ara/com/sample/radar_proxy.h"
using ara::com::sample::Position;
using ara::com::sample::FusionVariant;

#include "ara/log/logging.h"
using namespace ara::log;  // 'using' ara::log should be OK

// <<operator implementation for logging custom types
// just another variant as also available in radar sources.
inline LogStream& operator<<(LogStream& out, const Position& value)
{
    std::ostringstream stream;
    stream << "x, y, z (" << value.x << "," << value.y << "," << value.z << ")";
    return (out << stream.str().c_str());
}
inline LogStream& operator<<(LogStream& out, const ara::com::SubscriptionState& state)
{
    std::ostringstream stream;
    if(state == ara::com::SubscriptionState::kSubscribed){
        stream << "\nSubscription state : kSubscribed\n";
    }else if(state == ara::com::SubscriptionState::kNotSubscribed){
        stream << "\nSubscription state : kNotSubscribed\n";
    }else{
        stream << "\nSubscription state : kSubscriptionPending\n";
    }
    return (out << stream.str().c_str());
}
namespace fusion
{
FusionActivity::FusionActivity()
    : m_proxy(nullptr)
    , m_sync_count(0)
    , m_async_count(0)
    , m_rand_eng(m_rd())
    , m_ud_min_500_500(-500, 500)
    , m_ud_5_30(5, 30)
{
    m_logger.LogDebug() << "object address" << this;
}

void FusionActivity::init()
{
    m_logger.LogDebug() << "enter init()";

    ara::core::InstanceSpecifier portSpecifier{"fusionExe/RootSwComponent/radar_RPort"};
    m_logger.LogInfo() << "Port In Executable Ref:" << portSpecifier.ToString();
    auto instanceIDs = ara::com::runtime::ResolveInstanceIDs(portSpecifier);

    if (instanceIDs.empty()) {
        throw std::runtime_error{"No InstanceIdentifiers resolved from provided InstanceSpecifier"};
        m_logger.LogFatal() << "@@@ Fusion fail ###";
    }
    m_logger.LogInfo() << "Searching for Service Instance:" << instanceIDs[0].ToString();

    Proxy::StartFindService(
        [this](ara::com::ServiceHandleContainer<Proxy::HandleType> handles, ara::com::FindServiceHandle handler) {
            FusionActivity::serviceAvailabilityCallback(std::move(handles), handler);
        },  instanceIDs[0]);

    m_logger.LogDebug() << "exit init()";
}

void FusionActivity::asyncMethodCall()
{
    // Calling "Adjust" method asynchronously (get() should not be used unless results are ready).
    // Set random target position from -500 to 500.
    Position target_position;
    target_position.x = m_ud_min_500_500(m_rand_eng);
    target_position.y = m_ud_min_500_500(m_rand_eng);
    target_position.z = m_ud_min_500_500(m_rand_eng);

    // Increment the counter.
    m_async_count++;

    // Get future.
    auto adjust_future = m_proxy->Adjust(target_position);

    // Every 14 calls set a callback to the async call, no need to poll the results.
    bool poll_mode = (m_async_count % 14 == 0) ? false : true;

    // Polling the results is enabled.
    if (poll_mode) {
        // Polling the results.
        while (!adjust_future.is_ready()) {
            // Results are not ready yet.
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            m_logger.LogInfo() << METHODS_HEADER << "Radar is adjusting position, please wait ...";
        }

        // Get Adjustment's result.
        // Get will return immediately.
        try {
            auto adjust_output = adjust_future.get();

            if (adjust_output.success) {
                m_logger.LogInfo() << METHODS_HEADER << "Adjusting position was successful, effective position is ("
                                   << adjust_output.effective_position;

                if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Adjust_Done") == App_Test_Result.end()){
                    App_Test_Result.push_back("Adjust_Done");
                    m_logger.LogVerbose() << "Adjust_First_Done";}
            } else {
                m_logger.LogWarn() << METHODS_HEADER
                                   << "Adjusting position was not successful, deviation from the target position is ("
                                   << adjust_output.effective_position.x - target_position.x << ","
                                   << adjust_output.effective_position.y - target_position.y << ","
                                   << adjust_output.effective_position.z - target_position.z << ")";
            }
        }
        catch(std::exception &e) {
            m_logger.LogWarn() << METHODS_HEADER << " Can't get adjust";
            m_logger.LogFatal() << "@@@ Fusion fail ###";
        }
    } else {
        // Registering a notification callback.
        // TODO: Current ara::com::future.then() doesn't support arguments to be passed to the Lambda
        // TODO: then output can't be retrieved. According to the explanatory, the use example is
        // TODO: then([] (Future<Calibrate::Output> f) { f.get()}.
        m_logger.LogInfo() << METHODS_HEADER << "Radar is adjusting position, you will be notified when done ...";

        adjust_future.then([&]() {
            // it's safe to access the logger instance even if it's parent goes out of scope,
            // as long as the application process is alive, the reference is valid, because of
            // strong ownership inside the logging framework.
            m_logger.LogInfo() << METHODS_HEADER << "Notification! Adjusting position has finished";
        });
    }
}

void FusionActivity::syncMethodCall()
{
    // Increment the counter.
    m_sync_count++;

    // Prepare the fusion variant.
    FusionVariant variant;

    if ((m_sync_count % 3) == 0) {
        variant = FusionVariant::FV_CHINA;
    } else if ((m_sync_count % 5) == 0) {
        variant = FusionVariant::FV_USA;
    } else if ((m_sync_count % 7) == 0) {
        variant = FusionVariant::FV_RUSSIA;
    } else {
        variant = FusionVariant::FV_EUROPE;
    }

    // Prepare the calibration configuration string.
    String configuration = "calibration_config_" + std::to_string(m_sync_count);

    // Calling "Calibrate" method synchronously (get() should be used).
    auto calibrate_future = m_proxy->Calibrate(configuration, variant);

    m_logger.LogInfo() << METHODS_HEADER << "Radar is calibrating, please wait ...";

    auto r = calibrate_future.GetResult();
    if (r.HasValue())
    {
        auto calibrate_output = r.Value();
        (void)calibrate_output;
        m_logger.LogInfo() << METHODS_HEADER << "Calibration was successful";

        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Calibration_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("Calibration_Done");
            m_logger.LogVerbose() << "Calibration_First_Done";}
    }
    else
    {
        auto err = r.Error();
        m_logger.LogWarn() << ERROR_HEADER << "Code: "        << err.Value();
        m_logger.LogWarn() << ERROR_HEADER << "Message: "     << err.Message();
        // reset the count and continue
        m_sync_count = 0;
    }

    float in = 1.1f;
    auto testFloat_future = m_proxy->testFloat(in);

    m_logger.LogInfo() << METHODS_HEADER << "Radar is testFloat, please wait ...";

    auto rtf = testFloat_future.GetResult();

    if (rtf.HasValue())
    {
        auto testFloat_output = rtf.Value();
        m_logger.LogInfo() << METHODS_HEADER << "testFloat is " << testFloat_output.out;
    } else {
        m_logger.LogInfo() << METHODS_HEADER << "testFloat is none";
    }

    double ind = 1.1;
    auto testDouble_future = m_proxy->testDouble(ind);

    m_logger.LogInfo() << METHODS_HEADER << "Radar is testDouble, please wait ...";

    auto rtd = testDouble_future.GetResult();

    if (rtd.HasValue())
    {
        auto testFloat_output = rtd.Value();
        m_logger.LogInfo() << METHODS_HEADER << "testDouble is " << testFloat_output.out;
    } else {
        m_logger.LogInfo() << METHODS_HEADER << "testDouble is none";
    }
}

void FusionActivity::fireAndForgetMethodCall()
{
    String text = "Echo has been called.";

    m_proxy->Echo(text);
    m_logger.LogInfo() << METHODS_HEADER << text;

    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Echo_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Echo_Done");
        m_logger.LogVerbose() << "Echo_First_Done";}
}

void FusionActivity::updateRateSubscription()
{
    if (!m_proxy->UpdateRate.IsSubscribed()) {
        // m_proxy got initialized via callback.
        LogStream logMsg{m_logger.LogVerbose()};

        // Register event receive callback
        m_proxy->UpdateRate.SetReceiveHandler([this]() { FusionActivity::updateRateReceived(); });

        // subscribe to event
        m_proxy->UpdateRate.Subscribe(1);
    }
}

void FusionActivity::frontObjectDistanceSubscription()
{
    if (!m_proxy->FrontObjectDistance.IsSubscribed()) {
        // m_proxy got initialized via callback.
        LogStream logMsg{m_logger.LogVerbose()};

        // Register event receive callback
        m_proxy->FrontObjectDistance.SetReceiveHandler([this]() { FusionActivity::frontObjectDistanceReceived(); });

        // subscribe to event
        m_proxy->FrontObjectDistance.Subscribe(1);
    }
}

void FusionActivity::fieldGetter()
{
    LogStream logMsgUpdate{m_logger.LogVerbose()};

    // Use Getter to get the Field value.
    auto getUpdateRateFuture = m_proxy->UpdateRate.Get();
    try {
        auto rUpdateRate = getUpdateRateFuture.GetResult();
        if (rUpdateRate.HasValue()) {
            auto value = rUpdateRate.Value();
            logMsgUpdate << FIELDS_HEADER << " Current Update Rate is " << value;
            if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "UpdateRate_get_Done") == App_Test_Result.end()){
                    App_Test_Result.push_back("UpdateRate_get_Done");
                    logMsgUpdate << FIELDS_HEADER << "UpdateRate_get_First_Done";}
        }
    }
    catch(std::exception &e) {
        logMsgUpdate << FIELDS_HEADER << " Can't get Update Rate";
        m_logger.LogFatal() << "@@@ Fusion fail ###";
    }

    LogStream logMsgDistance{m_logger.LogVerbose()};
    // Use Getter to get the Field value.
    try {
        auto getRearObjectDistanceFuture = m_proxy->RearObjectDistance.Get();
        auto rRearObjectDistance = getRearObjectDistanceFuture.GetResult();
        if (rRearObjectDistance.HasValue()) {
            auto value = rRearObjectDistance.Value();
            logMsgDistance << FIELDS_HEADER << " Current Rear Object Distance is " << value;
            if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "RearObjectDistance_Done") == App_Test_Result.end()){
                App_Test_Result.push_back("RearObjectDistance_Done");
                logMsgDistance << FIELDS_HEADER << "RearObjectDistance_First_Done";}
        }
    }
    catch(std::exception &e) {
        logMsgDistance << FIELDS_HEADER << " Can't get Rear Object Distance";
        m_logger.LogFatal() << "@@@ Fusion fail ###";
    }
}

void FusionActivity::fieldSetter()
{
    LogStream logMsg{m_logger.LogInfo()};
    if (m_act_count % 7 == 0) {
        // Use Setter to reset the Field value.
        // XXX: According to the explanatory the returned object should be
        // ara::com::Future<FieldType> but with the current implementation ofdhk 
        // ara::com it's void(const_reference).
    try{
        uint32_t set_value = 0;
        auto UpdateRate_set_result = m_proxy->UpdateRate.Set(set_value);
        logMsg << FIELDS_HEADER <<"set UpdateRate value : " << set_value;
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "UpdateRate_set_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("UpdateRate_set_Done");
            logMsg << FIELDS_HEADER << "UpdateRate_set_Done";}
    }
    catch(std::exception &e) {
        logMsg << FIELDS_HEADER << " Can't set UpdateRate";
        m_logger.LogFatal() << "@@@ Fusion fail ###";
    }
        /*
        try {
            fut.wait();
        }
        catch (std::exception &e) {
            logMsg << e.what();
        }*/
    }
    if (m_act_count % 5 == 0) {
        std::uint16_t distance = m_ud_5_30(m_rand_eng);
        // Use Setter to reset the Field value.
        // XXX: According to the explanatory the returned object should be
        // ara::com::Future<FieldType> but with the current implementation of
        // ara::com it's void(const_reference).
    try{
        auto ObjectDetectionLimit_set_result = m_proxy->ObjectDetectionLimit.Set(distance);
        logMsg << FIELDS_HEADER << "set ObjectDetectionLimit value : " << distance;
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "ObjectDetectionLimit_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("ObjectDetectionLimit_Done");
            logMsg << FIELDS_HEADER << "ObjectDetectionLimit_First_Done";}

    }
    catch(std::exception &e) {
        logMsg << FIELDS_HEADER << " Can't set ObjectDetectionLimit";
        m_logger.LogFatal() << "@@@ Fusion fail ###";
    }
        /*
        try {
            fut.wait();
        }
        catch (std::exception &e) {
            logMsg << e.what();
        }*/
    }
}

void FusionActivity::act()
{
    m_logger.LogInfo() << "fusion";

    if (nullptr != m_proxy) {
        if (m_proxy->brakeEvent.IsSubscribed()) {
            // execute callback for every samples in the context of GetNewSamples
            m_proxy->brakeEvent.GetNewSamples([this](auto sample) {
                LogStream logMsg{m_logger.LogInfo()};
                logMsg << "Polling: Radar ";

                if (!sample->active) {
                    logMsg << "NOT ";
                }else{
                    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "brakeEvent_Done") == App_Test_Result.end()){
                        App_Test_Result.push_back("brakeEvent_Done");
                        logMsg << "brakeEvent_Done";}
                }
                logMsg << "active";

                auto l_dataVector = sample->objectVector;

                if (!l_dataVector.empty()) {
                    logMsg << " data: ";

                    for (auto b : l_dataVector) {
                        //logMsg << RawBuffer(+b) << " "; // Need to use dlt viewer
                        logMsg << static_cast<uint16_t>(b) << " ";
                    }
                }

                logMsg << m_proxy->brakeEvent.GetSubscriptionState();
            });
        } else {
            LogStream logMsg{m_logger.LogVerbose()};
            // m_proxy got initialized via callback.
            logMsg << m_proxy->brakeEvent.GetSubscriptionState();
            // subscribe to event
            m_proxy->brakeEvent.Subscribe(3);
            logMsg << m_proxy->brakeEvent.GetSubscriptionState();

            // Register event receive callback
            m_proxy->parkingBrakeEvent.SetReceiveHandler([this]() { FusionActivity::parkingBrakeEventReceived(); });
            // subscribe to event
            // kNewN -> kNewestN
            m_proxy->parkingBrakeEvent.Subscribe(1);
        }

        // Subscribe to Update Rate Field.
        this->updateRateSubscription();

        // Subscribe to Front Object Distance Field.
        this->frontObjectDistanceSubscription();

        /************************************/
        // Testing Field Getter.
        /************************************/
        this->fieldGetter();

        /************************************/
        // Testing Field Setter.
        /************************************/
        this->fieldSetter();

        /************************************/
        // Testing Synchronous Method Call.
        /************************************/
        this->syncMethodCall();

        /************************************/
        // Testing Asynchronous Methods Call.
        /************************************/
        this->asyncMethodCall();

        /************************************/
        // Testing Fire And Forget Method Call.
        /************************************/
        this->fireAndForgetMethodCall();

        if(App_Test_Result.size()>=11)
            m_logger.LogInfo() << "@@@ Fusion pass ###";
    }
    m_act_count++;
}
}  // namespace fusion
