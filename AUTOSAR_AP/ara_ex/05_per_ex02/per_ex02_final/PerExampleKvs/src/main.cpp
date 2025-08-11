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
#include "utility/debug.h"

#include "ara/log/logging.h"
#include <ara/exec/execution_client.h>

ara::exec::ExecutionClient exec_client;


int main()
{
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kRunning);

    mobilgene::adaptiveautosarperapplication::PerKVSProc PerKVSProc;
    // ara::log::InitLogging("PKDM", "PER KVS Example App", ara::log::LogLevel::kInfo, ara::log::LogMode::kConsole);
    TRACE_INFO("@@@ PerExampleKvs start ###");

    if(PerKVSProc.CreateKVS() == false) {
        TRACE_ERROR("PerKVSProc : " << __func__ << " : " << "fail to open KVS(MobilgeneMofNKVS)");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to get Key-Value pairs using 'ara::core::Result<void> GetValue (std::string key, T &value)'");
    if(PerKVSProc.GetValueFunc1() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail GetValueFunc1()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to get Key-Value pairs using 'ara::per::KeyValueStorage::GetValue(std::string key)'");
    if(PerKVSProc.GetValueFunc2() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail GetValueFunc2()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to set Key-Value pairs.");
    if(PerKVSProc.SetValue() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail SetValue()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to get Key-Value pairs using 'ara::core::Result<void> GetValue (std::string key, T &value)'");
    if(PerKVSProc.GetValueFunc1() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail GetValueFunc1()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to get Key-Value pairs using 'ara::per::KeyValueStorage::GetValue(std::string key)'");
    if(PerKVSProc.GetValueFunc2() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail GetValueFunc2()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : Example to delete Key-Value pairs using 'RemoveKey()' and 'RemoveAllKeys()'");
    if(PerKVSProc.RemoveValueAndCheckValue() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail RemoveValueAndCheckValue()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }

    TRACE_INFO("PerKVSExampleForEar : After save changed files in NVMemory, Example to reset Key-Value pairs using 'ResetKeyValueStorage()'");
    if(PerKVSProc.SyncKVSToStorage() == false) {
        TRACE_ERROR("PerKVSExampleForEar : Fail SyncKVSToStorage()");
        TRACE_INFO("@@@ PerExampleKvs fail ###");
        return 0;
    }    

    // if(PerKVSProc.ResetKVS() == false) {
    //     TRACE_ERROR("PerKVSExampleForEar : Fail ResetKVS()");
    //     TRACE_INFO("@@@ PerExampleKvs fail ###");
    //     return 0;
    // }

    TRACE_INFO("PerKVSExampleForEar : Success to Example All case");
    TRACE_INFO("@@@ PerExampleKvs pass ###");

    exec_client.ReportExecutionState(ara::exec::ExecutionState::kTerminating);
    return 1;
}
