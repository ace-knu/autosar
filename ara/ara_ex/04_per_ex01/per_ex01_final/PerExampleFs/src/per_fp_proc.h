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

#ifndef PER_FP_PROC_H
#define PER_FP_PROC_H
#include "ara/per/file_storage.h"
#include "ara/per/read_write_accessor.h"
#include "ara/per/read_accessor.h"
#include "ara/per/unique_handle.h"
#include "ara/per/shared_handle.h"
#include "ara/core/string.h"

#include <ara/log/logger.h>

#ifdef FEATURE_SUPPORT_RESOURCE_MANAGEMENT
#include "ara/per/manifestaccess/manifest_helper.h"
#include <sys/stat.h>
using ara::per::ManifestHelper; 
#endif 

using ara::core::String;
using ara::per::UniqueHandle;
using ara::per::SharedHandle;

namespace mobilgene {
namespace adaptiveautosarperapplication {

class PerFPProc
{
public:
    PerFPProc();
    virtual ~PerFPProc() = default;

    bool CreateFileAccessorFactoryAndRecoveryFileProxy();

    bool OperationsInReadAccessor();
    bool OperationsInWriteAccessor();
    bool OperationsInReadWriteAccessor();

    bool GetAllFiles();

private:
    String shortName;

    SharedHandle<ara::per::FileStorage> fp;
    UniqueHandle<ara::per::ReadAccessor> readOnlyfile = UniqueHandle<ara::per::ReadAccessor>(nullptr);
    UniqueHandle<ara::per::ReadWriteAccessor> writeOnlyfile = UniqueHandle<ara::per::ReadWriteAccessor>(nullptr);
    UniqueHandle<ara::per::ReadWriteAccessor> readwritefile = UniqueHandle<ara::per::ReadWriteAccessor>(nullptr);

    bool CreateReadAccessor(const String &filename);
    bool CreateReadWriteAccessor(const String &filename);
    bool CreateWriteAccessor(const String &filename);

    bool SettingForRecoveryCorruptedFileStorage();
    bool CopyFile(const String &fromPath, const String &toPath);
};

}
}
#endif // PER_FP_PROC_H
