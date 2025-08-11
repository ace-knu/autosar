// ---------------------------------------------------------------------------
// |                                                                         |
// |       888    888                                 888          d8b       |
// |       888    888                                 888          Y8P       |
// |       888    888                                 888                    |
// |       8888888888 888  888 888  888 88888b.   .d88888  8888b.  888       |
// |       888    888 888  888 888  888 888 "88b d88" 888     "88b 888       |
// |       888    888 888  888 888  888 888  888 888  888 .d888888 888       |
// |       888    888 Y88b 888 Y88b 888 888  888 Y88b 888 888  888 888       |
// |       888    888  "Y88888  "Y88888 888  888  "Y88888 "Y888888 888       |
// |                       888                                               |
// |                  Y8b d88P                                               |
// |                   "Y88P"                                                |
// |       d8888          888                                                | 
// |      d88888          888                                                | 
// |     d88P888          888                                                | 
// |    d88P 888 888  888 888888  .d88b.   .d88b.  888  888  .d88b.  888d888 | 
// |   d88P  888 888  888 888    d88""88b d8P  Y8b 888  888 d8P  Y8b 888P"   | 
// |  d88P   888 888  888 888    888  888 88888888 Y88  88P 88888888 888     | 
// | d8888888888 Y88b 888 Y88b.  Y88..88P Y8b.      Y8bd8P  Y8b.     888     | 
// |d88P     888  "Y88888  "Y888  "Y88P"   "Y8888    Y88P    "Y8888  888     |
// |                                                                         |
// ---------------------------------------------------------------------------
// |                                                                         |
// |  (C) 2019 HYUNDAI AUTOEVER Co., Ltd.                                    |
// |  Confidential Proprietary Information. Distribution Limited.            |
// |  Do Not Copy Without Prior Permission                                   |
// |                                                                         |
// ---------------------------------------------------------------------------

#include "per_kvs_proc.h"
#include "ara/per/key_value_storage.h"
#include "ara/per/kvstype/kvs_type.h"
#include "utility/debug.h"

#include <unistd.h>
#include "ara/core/instance_specifier.h"

//Per Root Improvement
#include "ara/per/manifestaccess/manifest_helper.h"
using ara::per::ManifestHelper;

namespace{

constexpr auto kKVSName = "MobilgeneMofNKVS";
constexpr auto kPathSeparator = "/";

constexpr auto kStringName1 = "KeyOfStringElement1";
constexpr auto kStringName2 = "KeyOfStringElement2";
constexpr auto kStringName3 = "KeyOfStringElement3";
const String kStringValue1 = "Hello World!!";
const String kStringValue2 = "Hello Mobilgene!!";
const String kStringValue3 = "Hello SWP!!";
const String kStringChangedValue1 = "Hello World!!@@@";
const String kStringChangedValue2 = "Hello Mobilgene!!@@@";
const String kStringChangedValue3 = "Hello SWP!!@@@";

constexpr auto kUInt64Name = "KeyOfUint64";
const uint64_t kUInt64Value = static_cast<uint64_t>(240000000000);
const uint64_t kUInt64ChangedValue = static_cast<uint64_t>(111111111111);

constexpr auto kInt64Name = "KeyOfInt64";
const int64_t kInt64Value = static_cast<int64_t>(-240000000000);
const int64_t kInt64ChangedValue = static_cast<int64_t>(-111111111111);

constexpr auto kBoolName = "KeyOfBool";
const bool kBoolValue = true;
const bool kBoolChangedValue = false;

constexpr auto kFloatName = "KeyOfFloat";
const float kFloatValue = 1.234567f;
const float kFloatChangedValue = 1111.111111f;

constexpr auto kDoubleName = "KeyOfDouble";
const double kDoubleValue = 1.234567;
const double kDoubleChangedValue = 1111.111111;

constexpr auto kDoubleVectorName = "KeyOfDoubleVector";
const std::vector<double> kDoubleVectorValue = {0.0, 0.1, 100.0, 40000.0, 12345678910112.0};
const std::vector<double> kDoubleVectorChangedValue = {1.1, 11.1, 111.1, 1111.1, 11111111111111.0};

String kRedundantRoot = "/etc/mobilgene/redundant/red1";
String kProcessRoot = ManifestHelper::GetRootPath();

String kFromPath0 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/reset/MobilgeneMofNKVS.json");
String kToPath0 = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNKVS.json");

#ifdef FEATURE_SUPPORT_RESOURCE_MANAGEMENT
String kToPathExtra = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNKVS.json_extra"); 
#endif 

String kFromPath1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS%1.json");
String kToPath1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%1.json");

String kFromPath2 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS%2.json");
String kToPath2 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%2.json");

String kFromPath3 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS%3.json");
String kToPath3 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%3.json");

String kFromPath4 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS%4.json");
String kToPath4 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%4.json");

String kFromTotPath = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS_one_two_one.json");
String kToTotPath1 = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNKVS.json");
String kToTotPath2 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%1.json");
String kFromTotDummy = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/demo/MobilgeneMofNKVS_dummy.json");
String kToTotPath3 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleKvs/MobilgeneMofNKVS/redundant/MobilgeneMofNKVS%2.json");

}

namespace mobilgene {
namespace adaptiveautosarperapplication {

PerKVSProc::PerKVSProc(): shortName(kKVSName)
  , kvs(nullptr)
{

}

bool PerKVSProc::CheckAllExpectedKey(bool isStr3ExpectedKey)
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    auto result = kvs->HasKey(kStringName1);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName1 << ") is not existed");
        return false;
    }   

    result = kvs->HasKey(kStringName2);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName2 << ") is not existed");
        return false;
    }

    result = kvs->HasKey(kStringName3);
    /* Since changing logic for MoutofN in #IMS_4331,
     * PER can recover all of elements even N not matched */
#if 0
    if((isStr3ExpectedKey && result == false) || (isStr3ExpectedKey == false && result == true)) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName3 << ") is not expected result");
        return false;
    }
#else 
    if(result == false){ 
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName3 << ") is not expected result");
        return false;
    }
#endif 

    result = kvs->HasKey(kUInt64Name);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kUInt64Name << ") is not existed");
        return false;
    }

    result = kvs->HasKey(kInt64Name);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kInt64Name << ") is not existed");
        return false;
    }

    result = kvs->HasKey(kBoolName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kBoolName << ") is not existed");
        return false;
    }

    result = kvs->HasKey(kFloatName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kFloatName << ") is not existed");
        return false;
    }

    result = kvs->HasKey(kDoubleName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kDoubleName << ") is not existed");
        return false;
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::CreateKVS()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(!kvs) {
        //auto result = ara::per::OpenKeyValueStorage(shortName);
        auto result = ara::per::OpenKeyValueStorage(ara::core::InstanceSpecifier(shortName));
        kvs = std::move(result).Value();
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "success to open KVS(" << shortName << ")");
    } else {
        // If KVS is not created, return false because this result is not expected in this demo scenario.
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to open KVS(" << shortName << ")");
        return false;
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::ClearKVS()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    kvs = std::move(ara::per::SharedHandle<KeyValueStorage>(nullptr));
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::SyncKVSToStorage()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // sync the changed value to a file in NVMemory.
    auto result1 = kvs->SyncToStorage();
    if(result1.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to sync changed value in short name(" << shortName << ").");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "success to sync changed value in short name(" << shortName << ").");
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::GetValueFunc1()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // Get value of Key value pairs by calling 'ara::core::Result<void> GetValue (std::string key, T &value)'.
    // string example
    auto result = kvs->HasKey(kStringName1);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName1 << ") is not existed");
        return false;
    }
    String strValue = "";
    auto result1 = kvs->GetValue(kStringName1, strValue);
    if(result1.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName1  << ")'s value is not existed. Error(" << result1.Error().Value() << ")");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kStringName1 << ")'s value is (" << strValue << ").");
    }

    result = kvs->HasKey(kStringName2);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName2 << ") is not existed");
        return false;
    }
    strValue = "";
    auto result2 = kvs->GetValue(kStringName2, strValue);
    if (result2.HasValue() == false)
    {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName2  << ")'s value is not existed. Error(" << result2.Error().Value() << ")");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kStringName2 << ")'s value is (" << strValue << ").");
    }

    result = kvs->HasKey(kStringName3);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kStringName3 << ") is not existed");
        return false;
    }
    strValue = "";
    auto result3 = kvs->GetValue(kStringName3, strValue);
    if(result3.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName3  << ")'s value is not existed. Error(" << result3.Error().Value() << ")");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kStringName3 << ")'s value is (" << strValue << ").");
    }

    // unsigned int type example
    result = kvs->HasKey(kUInt64Name);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kUInt64Name << ") is not existed");
        return false;
    }
    uint64_t uint64Value = 0;
    auto result4 = kvs->GetValue(kUInt64Name, uint64Value);
    if(result4.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kUInt64Name << ")'s value is not existed. Error(" << result4.Error().Value() << ")");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kUInt64Name << ")'s value is (" << uint64Value << ").");
    }

    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::GetValueFunc2()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // Get value of Key value pairs by calling 'ara::per::KeyValueStorage::GetValue(std::string key)'.
    // int type example
    auto result = kvs->HasKey(kInt64Name);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kInt64Name << ") is not existed");
        return false;
    }
    int64_t int64Value = 0;
    auto result5 = kvs->GetValue<int64_t>(kInt64Name);
    if(result5.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kInt64Name << ")'s value is not existed. Error(" << result5.Error().Value()  << ")");
        return false;
    } else {
        int64Value = std::move(result5).Value();
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kInt64Name << ")'s value is (" << int64Value << ").");
    }

    // bool example
    result = kvs->HasKey(kBoolName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kBoolName << ") is not existed");
        return false;
    }
    int64_t boolValue = false;
    auto result6 = kvs->GetValue<bool>(kBoolName);
    if(result6.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kBoolName << ")'s value is not existed. Error(" << result6.Error().Value()  << ")");
        return false;
    } else {
        boolValue = std::move(result6).Value();
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kBoolName << ")'s value is (" << boolValue << ").");
    }

    // float example
    result = kvs->HasKey(kFloatName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kFloatName << ") is not existed");
        return false;
    }
    float floatValue = 0;
    auto result7 = kvs->GetValue<float>(kFloatName);
    if(result7.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kFloatName  << ")'s value is not existed. Error(" << result7.Error().Value()  << ")");
        return false;
    } else {
        floatValue = std::move(result7).Value();
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kFloatName << ")'s value is (" << floatValue << ").");
    }

    // double example
    result = kvs->HasKey(kDoubleName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kDoubleName << ") is not existed");
        return false;
    }
    double doubleValue = 0;
    auto result8 = kvs->GetValue<double>(kDoubleName);
    if(result8.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleName << ")'s value is not existed. Error(" << result8.Error().Value()  << ")");
        return false;
    } else {
        doubleValue = std::move(result8).Value();
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleName << ")'s value is (" << doubleValue << ").");
    }

    // vector type example
    result = kvs->HasKey(kDoubleVectorName);
    if(result == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "expected key(" << kDoubleVectorName << ") is not existed");
        return false;
    }
    std::vector<double> doubleVectorValue;
    auto result9 = kvs->GetValue<std::vector<double>>(kDoubleVectorName);
    if(result9.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleVectorName << ")'s value is not existed. Error(" << result9.Error().Value()  << ")");
        return false;
    } else {
        doubleVectorValue = std::move(result9).Value();
        for(auto element : doubleVectorValue) {
           TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleVectorName << ")'s value is (" << element << ").");
        }
    }

    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::SetValue()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // change key's value.
    auto result = kvs->SetValue(kStringName1, kStringChangedValue1);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName1 << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kStringName1 << ")'s value().");
    }

    result = kvs->SetValue(kStringName2, kStringChangedValue2);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName2 << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kStringName2 << ")'s value().");
    }

    result = kvs->SetValue(kStringName3, kStringChangedValue3);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName3 << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kStringName3 << ")'s value().");
    }

    result = kvs->SetValue(kUInt64Name, kUInt64ChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kUInt64Name << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kUInt64Name << ")'s value().");
    }

    result = kvs->SetValue(kInt64Name, kInt64ChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kInt64Name << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kInt64Name << ")'s value().");
    }

    result = kvs->SetValue(kBoolName, kBoolChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kBoolName << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kBoolName << ")'s value().");
    }

    result = kvs->SetValue(kFloatName, kFloatChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kFloatName << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kFloatName << ")'s value().");
    }

    result = kvs->SetValue(kDoubleName, kDoubleChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleName << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kDoubleName << ")'s value().");
    }

    result = kvs->SetValue(kDoubleVectorName, kDoubleVectorChangedValue);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kDoubleVectorName << ")'s setValue() is failed.");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "set key(" << kDoubleVectorName << ")'s value().");
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::RemoveValueAndCheckValue()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // remove specific key's key-value pair in KVS.
    auto result = kvs->RemoveKey(kStringName1);
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to remove key(" << kStringName1 << ").");
        return false;
    } else {
        TRACE_INFO("PerKVSProc : " << __func__ << " : " << "success to remove key(" << kStringName1 << ").");
    }

//     // check specific key's key-value pair is removed in KVS.
//     if(kvs->HasKey(kStringName1) == false) {
//         TRACE_INFO("PerKVSProc : " << __func__ << " : " << "key(" << kStringName1 << ") is not existed");
//     } else {
//         TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "key(" << kStringName1 << ") is existed");
//         return false;
//     }

//     // Before removing all keys, get list of all keys in KVS by using GetAllKeys() to check KVS has some key-value pairs
//     auto keys = kvs->GetAllKeys();
//     for(auto key : keys.Value()) {
//         TRACE_INFO("PerKVSProc : " << __func__ << " : " << "short name(" << shortName << ")'s  key(" << key << ")");
//     }

//     //remove all key's key-value pair in KVS.
//     result = kvs->RemoveAllKeys();
//     if(result.HasValue() == false) {
//         TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to remove all key.");
//         return false;
//     } else {
//         TRACE_INFO("PerKVSProc : " << __func__ << " : " << "success to remove all key.");
//     }

//     // After removing all keys, get list of all keys in KVS by using GetAllKeys() to check KVS doesn't have any key.
//     auto keys1 = kvs->GetAllKeys();
//     if(keys1.Value().size() == 0) {
//         TRACE_INFO("PerKVSProc : " << __func__ << " : " << "all keys is not existed in the KVS(" << shortName << ").");
//     } else {
//         TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "Some key are existed in the KVS(" << shortName << "). It is error.");
//         for(auto key : keys1.Value()) {
//             TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "short name(" << shortName << ")'s  key(" << key << "). It is error.");
//         }
//         return false;
//     }
//     TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::ResetKVS()
{
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    if(&kvs == nullptr) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "kvs is not opened. So return false.");
        return false;
    }

    // To success to reset, KVS to open MUST not be opened. So, close KVS to open at first.
    if(ClearKVS() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to clear KVS(" << shortName << ")");
        return false;
    }

    TRACE_INFO("PerKVSProc : " << __func__ << " :  start ResetKeyValueStorage of " << shortName);
    //auto result = ara::per::ResetKeyValueStorage(shortName);
    auto result = ara::per::ResetKeyValueStorage(ara::core::InstanceSpecifier(shortName));
    if(result.HasValue() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to reset KVS(" << shortName << ")");
        return false;
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end ResetKeyValueStorage of " << shortName);

    if(CreateKVS() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to open KVS(" << shortName << ")");
        return false;
    }

    // Check All Expected Keys is existed. If reset is success, all expected keys is existed because removed keys are recovered.
    // KeyOfStringElemten3's key-value pair is also reset. So CheckAllExpectedKey's aregument is true.
    bool isAllKeyExisted = CheckAllExpectedKey(true);

    // If KVS doesn't have All Expected Keys, return false because this result is not expected in this  demo scenario.
    if(isAllKeyExisted == false) {
        return false;
    }
    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

bool PerKVSProc::CopyFile(const String &fromPath, const String &toPath) {
    TRACE_INFO("PerKVSProc : " << __func__ << " :  start");
    TRACE_INFO("PerKVSProc : " << __func__ << " :  fromPath : "  + fromPath);
    TRACE_INFO("PerKVSProc : " << __func__ << " :  toPath : " + toPath);
    if(fromPath.empty() || toPath.empty()) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "return false because fromPath or toPath is empty.");
        return false;
    }

    if (access(fromPath.c_str(), F_OK) !=0) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "return false because fromPath doesn't exist(" << fromPath);
        return false;
    }

    FILE* fromStream = fopen(fromPath.c_str(), "rb");
    if (!fromStream) {
        // I/O error: check errno
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to open fromPath : " << fromPath);
        return false;
    }

    FILE* toStream = fopen(toPath.c_str(), "wb");
    if (!toStream) {
        // I/O error: check errno
        fclose(fromStream);
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to open toPath : " << toPath);
        return false;
    }

    char buf[1024];

    do {
        size_t readBytes = fread(buf, 1, sizeof(buf), fromStream);
        if (readBytes) {
            size_t writeBytes = fwrite(buf, 1, readBytes, toStream);
            if (writeBytes != readBytes) {
                if (ferror(toStream)) {
                    // writing file error: check errno
                    fclose(fromStream);
                    fclose(toStream);
                    TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "ferror 1");
                    return false;
                }
            }
        }

        if (readBytes != sizeof(buf)) {
            if (ferror(fromStream)) {
                // reading file error: check errno
                fclose(fromStream);
                fclose(toStream);
                TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "ferror 2");
                return false;
            }
        }
    } while (!feof(fromStream));

    fclose(fromStream);
    fclose(toStream);

    TRACE_INFO("PerKVSProc : " << __func__ << " :  end");
    return true;
}

}
}
