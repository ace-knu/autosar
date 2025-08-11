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

#include "radar_activity.h"

#include <stdint.h>
#include <cstdlib>
#include <cstring>

#include "ara/com/sample/radar_skeleton.h"
#include "ara/com/com_error_domain.h"

using ara::com::sample::Position;
using ara::com::sample::FusionVariant;

using namespace ara::log;

using ara::com::sample::SpecificErrorsErrc;
using ara::com::ComErrorDomainErrc;
using ara::com::sample::skeleton::radar::fields::UpdateRate;
using ara::com::sample::skeleton::radar::fields::RearObjectDistance;

// <<operator implementation for logging custom types
// similar handler is also available in fusion sources, so for real projects it make sense to
// have some common place where custom type log-handlers are provided.
inline LogStream& operator<<(LogStream& out, const Position& value)
{
    return (out << "x, y, z (" << value.x << "," << value.y << "," << value.z << ")");
}

namespace radar
{
auto radarImp::Adjust(const Position& target_position) -> decltype(Skeleton::Adjust(target_position))
{
    radarImp::AdjustOutput output;

    // Increment the counter.
    m_adjust_count++;

    // Show the target position.
    m_logger_ctx1.LogInfo() << METHODS_HEADER << "Target position is" << target_position << ", adjusting position ...";

    // Introduce a delay.
    if ((m_adjust_count % 7) == 0) {
        // Sleep for 10 secs.
        std::this_thread::sleep_for(std::chrono::seconds(10));

        // Adjusting position took too long, set success to false & deviate the effective position.
        output.effective_position.x = target_position.x + m_ud_0_100(m_rand_eng);
        output.effective_position.y = target_position.y + m_ud_0_100(m_rand_eng);
        output.effective_position.z = target_position.z + m_ud_0_100(m_rand_eng);

        m_logger_ctx1.LogWarn() << METHODS_HEADER << "Adjusting position took too long time, there is something wrong";
        m_logger_ctx1.LogWarn() << METHODS_HEADER << "Effective position is" << output.effective_position;

        output.success = false;
    } else {
        // Adjusting position was successful, set success to true and show the effective position.
        output.effective_position = target_position;

        m_logger_ctx1.LogInfo() << METHODS_HEADER
                                << "Adjusting position was successful, effective position equals target position";
        m_logger_ctx1.LogWarn() << METHODS_HEADER << "Effective position is" << output.effective_position;

        output.success = true;
    }

    // Set the promise value.
    decltype(Skeleton::Adjust(target_position))::PromiseType promise;
    promise.set_value(std::move(output));
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Adjust_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Adjust_Done");
        m_logger_ctx1.LogVerbose() << "Adjust_First_Done";}
    return promise.get_future();
}

auto radarImp::Calibrate(const String& configuration, const FusionVariant& variant)
    -> decltype(Skeleton::Calibrate(configuration, variant))
{
    radarImp::CalibrateOutput output;

    // Increment the counter.
    m_calibrate_count++;

    m_logger_ctx2.LogInfo() << METHODS_HEADER << "Calibration configuration string is " << configuration
                            << ", Fusion variant is " << (std::uint16_t)variant << ", calibrating ...";

    // Introduce a delay.
    if ((m_calibrate_count % 8) == 0) {
        // Sleep for 10 secs.
        std::this_thread::sleep_for(std::chrono::seconds(10));

        // Calibration took too long, set result to false.
        output.result = false;
        m_logger_ctx2.LogWarn() << METHODS_HEADER << "Calibration took very long time, there is something wrong";
    } else {
        // Calibration was successful, set result to true.
        output.result = true;
        m_logger_ctx2.LogInfo() << METHODS_HEADER << "Calibration was successful";
    }

    // Set the promise value (or error in case calibration went wrong).
    decltype(Skeleton::Calibrate(configuration, variant))::PromiseType promise;
    if (!output.result) {
        m_logger_ctx2.LogWarn() << ERROR_HEADER << "Configuration string was invalid.";
        promise.SetError(ara::core::ErrorCode(SpecificErrorsErrc::kInvalidConfigString));
    } else{
        promise.set_value(std::move(output));
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Calibrate_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("Calibrate_Done");
            m_logger_ctx2.LogVerbose() << "Calibrate_First_Done";}
    }
    return promise.get_future();
}

void radarImp::Echo(const String& text)
{
    m_logger_ctx5.LogInfo() << METHODS_HEADER << text;
    
    if(&text){
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Echo_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Echo_Done");
        m_logger_ctx5.LogVerbose() << "Echo_First_Done";}
    }
}

auto radarImp::testFloat(const float& in1) -> decltype(Skeleton::testFloat(in1))
{
    radarImp::testFloatOutput output;
    output.out = in1*2;

    decltype(Skeleton::testFloat(in1))::PromiseType promise;
    promise.set_value(std::move(output));

    return promise.get_future();
}

auto radarImp::testDouble(const double& in1) -> decltype(Skeleton::testDouble(in1))
{
    radarImp::testDoubleOutput output;
    output.out = in1*3;

    decltype(Skeleton::testDouble(in1))::PromiseType promise;
    promise.set_value(std::move(output));

    return promise.get_future();
}

void radarImp::ProcessRequests()
{
    while (!m_finished) {
        std::chrono::time_point<std::chrono::system_clock> deadline
            = std::chrono::system_clock::now() + std::chrono::milliseconds(500);
        auto request_finished = ProcessNextMethodCall();
        if (request_finished.wait_until(deadline) != decltype(request_finished)::Status::kReady) {
            m_logger_ctx1.LogFatal() << "Request took too long :S";
        } else {
            if (!m_finished) {
                std::this_thread::sleep_until(deadline);
            }
        }
    }
}

RadarActivity::RadarActivity()
    : m_rand_eng(m_rd())
    , m_ud_0_100(0, 100)
    , m_ud_0_50(0, 50)
{
    // 1) ara::core::InstanceSpecifier
    ara::core::InstanceSpecifier instanceSpec{"radarServiceExe/RootSwComponent/radar_PPort"};
    m_logger_ctx3.LogInfo() << "Port In Executable Ref:" << instanceSpec.ToString();
    m_skeleton = new radarImp(instanceSpec, ara::com::MethodCallProcessingMode::kPoll);
    // The instance id resolution is not mandatory for service creation (but could be an option)
    // here it's intended to list ids for the offered service instances
    auto instanceIDs = ara::com::runtime::ResolveInstanceIDs(instanceSpec);
    for (auto const& instanceId : instanceIDs) {
        m_logger_ctx3.LogInfo() << "Service Instance offered:" << instanceId.ToString();
    }

    // 2) ara::com::InstanceIdentifier
    // ara::com::InstanceIdentifier instanceIdent{"SOME/IP:19"};
    // m_skeleton = new radarImp(instanceIdent, ara::com::MethodCallProcessingMode::kPoll);

    m_logger_ctx3.LogDebug() << "object address" << this;
}

RadarActivity::~RadarActivity()
{
    delete m_skeleton;
}

ara::core::Future<ara::com::sample::skeleton::radar::fields::UpdateRate::value_type> RadarActivity::getUpdateRate()
{
    m_update_rate = m_ud_0_100(m_rand_eng);
    m_logger_ctx3.LogInfo() << FIELDS_HEADER << "Getting the field Update Rate value :" << m_update_rate;
    ara::core::Promise<ara::com::sample::skeleton::radar::fields::UpdateRate::value_type> promise;
    promise.set_value(std::move(m_update_rate));    
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Get_UpdateRate_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Get_UpdateRate_Done");
        m_logger_ctx3.LogVerbose() << "Get_UpdateRate_First_Done";}

    return promise.get_future();
}

ara::core::Future<ara::com::sample::skeleton::radar::fields::RearObjectDistance::value_type>
RadarActivity::getRearObjectDistance()
{
    std::uint16_t distance = m_ud_0_50(m_rand_eng);

    if (distance > m_object_limit) {
        distance = -1;
    }

    m_logger_ctx3.LogInfo() << FIELDS_HEADER << "Getting the Rear Object Distance Distance :" << (std::int16_t)distance;

    ara::core::Promise<ara::com::sample::skeleton::radar::fields::RearObjectDistance::value_type> promise;
    promise.set_value(std::move(distance));
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Get_RearObjectDistance_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Get_RearObjectDistance_Done");
        m_logger_ctx3.LogVerbose() << "Get_RearObjectDistance_First_Done";}

    return promise.get_future();
}

ara::core::Future<uint32_t> RadarActivity::setUpdateRate(uint32_t field)
{
    m_update_rate = field;
    m_logger_ctx3.LogInfo() << FIELDS_HEADER << "Setting the field Update Rate value to " << m_update_rate;
    ara::core::Promise<uint32_t> promise;
    promise.set_value(std::move(m_update_rate));
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Set_UpdateRate_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Set_UpdateRate_Done");
        m_logger_ctx3.LogVerbose() << "Set_UpdateRate_First_Done";}

    return promise.get_future();
}

ara::core::Future<uint16_t> RadarActivity::setObjectDetectionLimit(uint16_t field)
{
    m_object_limit = field;
    m_logger_ctx3.LogInfo() << FIELDS_HEADER << "Setting the Object Detection Distance Limit to " << m_object_limit;
    ara::core::Promise<uint16_t> promise;
    promise.set_value(std::move(m_object_limit));
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "Set_RearObjectDistance_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("Set_RearObjectDistance_Done");
        m_logger_ctx3.LogVerbose() << "Set_RearObjectDistance_First_Done";}

    return promise.get_future();
}

void RadarActivity::init()
{
    m_logger_ctx3.LogDebug() << "enter init()";

    // Init cached version of the Update Rate field.
    this->m_update_rate = 0;

    // Register Field Getters.
    m_skeleton->UpdateRate.RegisterGetHandler(std::bind(&RadarActivity::getUpdateRate, this));
    m_skeleton->RearObjectDistance.RegisterGetHandler(std::bind(&RadarActivity::getRearObjectDistance, this));

    // Register Field Setters.
    m_skeleton->UpdateRate.RegisterSetHandler(std::bind(&RadarActivity::setUpdateRate, this, std::placeholders::_1));

    m_skeleton->ObjectDetectionLimit.RegisterSetHandler(
        std::bind(&RadarActivity::setObjectDetectionLimit, this, std::placeholders::_1));

    // Initialize Fields Values before Offering Service.
    m_skeleton->UpdateRate.Update(0);
    m_skeleton->FrontObjectDistance.Update(0);
    m_skeleton->RearObjectDistance.Update(0);
    m_skeleton->ObjectDetectionLimit.Update(0);
    m_skeleton->OfferService();
}

void RadarActivity::act()
{
    m_logger_ctx3.LogInfo() << "radar";

    static uint8_t i = 0;

    // allocate sample
    auto l_sampleRadar = m_skeleton->brakeEvent.Allocate();

    // write data
    if (i % 5 == 0) {
        l_sampleRadar->active = true;
    }
    l_sampleRadar->objectVector.push_back(0x10);
    l_sampleRadar->objectVector.push_back(0x20);
    l_sampleRadar->objectVector.push_back(0x30);
    l_sampleRadar->objectVector.push_back(0x40);
    l_sampleRadar->objectVector.push_back(i);

    // send sample
    m_skeleton->brakeEvent.Send(std::move(l_sampleRadar));

    // same for parking brake
    auto l_sampleParkingBrake = m_skeleton->parkingBrakeEvent.Allocate();

    if (i % 5 != 0) {
        l_sampleParkingBrake->active = true;
    }
    l_sampleParkingBrake->objectVector.push_back(255 - i);

#ifdef TP_TEST
    uint16_t xxx =0;
   
    if (i % 5 ==0)
    {
       for (xxx=0; xxx<1600; xxx++)
       {    
          l_sampleParkingBrake->objectVector.push_back(xxx % 0xff);
       }   
    }
    else if (i % 5 ==1)
    {
       for (xxx=0; xxx<20000; xxx++)
       {    
          l_sampleParkingBrake->objectVector.push_back(xxx % 0xff);
       }   
    }
    else if (i % 5 ==2)
    {
       for (xxx=0; xxx<10000; xxx++)
       {    
          l_sampleParkingBrake->objectVector.push_back(xxx % 0xff);
       }   
    }
    else if (i % 5 ==3)
    {
       for (xxx=0; xxx<3000; xxx++)
       {    
          l_sampleParkingBrake->objectVector.push_back(xxx % 0xff);
       }   
    }
    else
    {
       for (xxx=0; xxx<25000; xxx++)
       {    
          l_sampleParkingBrake->objectVector.push_back(xxx % 0xff);
       }   
    }
    m_logger_ctx3.LogInfo() << "Radar send TP data to Fusion: ";
    m_logger_ctx3.LogInfo() << (uint16_t)(l_sampleParkingBrake->objectVector.size());
#endif




    // FIX for possible threading problem in vSomeIP which led to SEGFAULT
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // send sample
    m_skeleton->parkingBrakeEvent.Send(std::move(l_sampleParkingBrake));
    if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "parkingBrakeEvent_Done") == App_Test_Result.end()){
        App_Test_Result.push_back("parkingBrakeEvent_Done");
        m_logger_ctx3.LogVerbose() << "parkingBrakeEvent_First_Done";}

    // Update Field Value and send notification.
    if (i % 5 == 0) {
        m_update_rate = i * 1000;
        m_skeleton->UpdateRate.Update(m_update_rate);
    }

    std::uint16_t distance = m_ud_0_50(m_rand_eng);
    if (distance < m_object_limit) {
        m_skeleton->FrontObjectDistance.Update(distance);
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "FrontObjectDistance_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("FrontObjectDistance_Done");
            m_logger_ctx3.LogVerbose() << "FrontObjectDistance_First_Done";}
    } else {
        m_skeleton->FrontObjectDistance.Update(-1);
        if(std::find(App_Test_Result.begin(), App_Test_Result.end(), "FrontObjectDistance_Done") == App_Test_Result.end()){
            App_Test_Result.push_back("FrontObjectDistance_Done");
            m_logger_ctx3.LogVerbose() << "FrontObjectDistance_First_Done";}
    }

    if(App_Test_Result.size()>=9)
        m_logger_ctx3.LogInfo() << "@@@ Radar pass ###";

    i++;
}
}  // namespace radar
