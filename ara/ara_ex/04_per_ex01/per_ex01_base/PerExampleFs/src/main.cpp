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

#include "per_fp_proc.h"
#include "utility/debug.h"

#include "ara/log/logging.h"
#include <ara/exec/execution_client.h>

ara::exec::ExecutionClient exec_client;


int main()
{
    exec_client.ReportExecutionState(ara::exec::ExecutionState::kRunning);

    // ara::log::InitLogging("PFDM", "PER File Storage Demo App", ara::log::LogLevel::kInfo, ara::log::LogMode::kConsole);
    
    TRACE_INFO("@@@ PerDemoFs start ###");
    mobilgene::adaptiveautosarperapplication::PerFPProc perFPProc;

    TRACE_INFO("persistencyFileStorageDemo : Demo about RecoverFileProxy() for file storage.");
    if(perFPProc.CreateFileAccessorFactoryAndRecoveryFileProxy() == false) {
        TRACE_ERROR("persistencyFileStorageDemo : Fail CreateFileAccessorFactoryAndRecoveryFileProxy()");
        TRACE_INFO("@@@ PerDemoFs fail ###");
        return 0;
    }

    TRACE_INFO("persistencyFileStorageDemo : Demo about read operations in an accessor for reading a file of the file storage.");
    if(perFPProc.OperationsInReadAccessor() == false) {
        TRACE_ERROR("persistencyFileStorageDemo : Fail OperationsInReadAccessor()");
        TRACE_INFO("@@@ PerDemoFs fail ###");
        return 0;
    }

    TRACE_INFO("persistencyFileStorageDemo : Demo about write operations in an accessor for writing a file of the file storage.");
    if(perFPProc.OperationsInWriteAccessor() == false) {
        TRACE_ERROR("persistencyFileStorageDemo : Fail OperationsInWriteAccessor()");
        TRACE_INFO("@@@ PerDemoFs fail ###");
        return 0;
    }

    TRACE_INFO("persistencyFileStorageDemo : Demo about read and write operations in an accessor for reading and writing a file of the file storage.");
    if(perFPProc.OperationsInReadWriteAccessor() == false) {
        TRACE_ERROR("persistencyFileStorageDemo : Fail OperationsInReadWriteAccessor()");
        TRACE_INFO("@@@ PerDemoFs fail ###");
        return 0;
    }

    TRACE_INFO("persistencyFileStorageDemo : Success to Pass All tests");
    TRACE_INFO("@@@ PerDemoFs pass ###");

    exec_client.ReportExecutionState(ara::exec::ExecutionState::kTerminating);
    return 0;
}
