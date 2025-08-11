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
#include "ara/per/key_value_storage.h"
#include "ara/per/kvstype/kvs_type.h"
#include "utility/debug.h"
#include "ara/core/instance_specifier.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#include <algorithm>

#include <unistd.h>


//Per Root Improvement
#include "ara/per/manifestaccess/manifest_helper.h"
using ara::per::ManifestHelper;

namespace{

constexpr auto kFPName = "MobilgeneMofNFP";
constexpr auto kFPName1 = "MobilgeneCRCMofNFP";
constexpr auto kPathSeparator = "/";

const String kReadOnlyFileName1 = "ReadOnlyFile1.txt";
const String kWriteOnlyFileName1 = "WriteOnlyFile1.txt";
const String kReadWriteFileName1 = "ReadWriteFile1.txt";
const String kReadWriteCRCMofNFileName1 = "ReadWriteCRCMofNFile1.txt";

const String kStringReadOnlyFileValue1 = "Hello World!! It is ReadOnlyFile1!!";
const String kStringWriteOnlyFileValue1 = "Hello Mobilgene!! It is WriteOnlyFile1!!";
const String kStringReadWriteFileValue1 = "Hello SWP!! It is ReadWriteFile1!!";

const String kStringWriteOnlyFileChangedValue1 = "Hello Mobilgene!! It is changed WriteOnlyFile1!!!!!!";
const String kStringReadWriteFileChangedValue1 = "Hello SWP!! It is changed ReadWriteFile1!!!!!!";
const String kStringReadWriteCRCMofNFileValue1 = "Hello SWP!! It is ReadWriteFile1!! It uses both CRC and MoutofN!!";

const String kProcessRoot = ManifestHelper::GetRootPath();
String kRedundantRoot = "/etc/mobilgene/redundant/red1/";
#ifdef FEATURE_SUPPORT_RESOURCE_MANAGEMENT
String kToPath = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNFP");
#endif
String kFromPath0OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadWriteFile1.txt");
String kToPath0OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNFP/ReadWriteFile1.txt");

String kFromPath1OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadWriteFile1%1.txt");
String kToPath1OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadWriteFile1%1.txt");

String kFromPath2OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadWriteFile1%2.txt");
String kToPath2OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadWriteFile1%2.txt");

String kFromPath3OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadWriteFile1%3.txt");
String kToPath3OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadWriteFile1%3.txt");

String kFromPath4OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadWriteFile1%4.txt");
String kToPath4OfReadWriteFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadWriteFile1%4.txt");

String kFromPath0OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/WriteOnlyFile1.txt");
String kToPath0OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNFP/WriteOnlyFile1.txt");

String kFromPath1OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/WriteOnlyFile1%1.txt");
String kToPath1OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/WriteOnlyFile1%1.txt");

String kFromPath2OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/WriteOnlyFile1%2.txt");
String kToPath2OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/WriteOnlyFile1%2.txt");

String kFromPath3OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/WriteOnlyFile1%3.txt");
String kToPath3OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/WriteOnlyFile1%3.txt");

String kFromPath4OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/WriteOnlyFile1%4.txt");
String kToPath4OfWriteOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/WriteOnlyFile1%4.txt");


String kFromPath0OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadOnlyFile1.txt");
String kToPath0OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kProcessRoot, "var/MobilgeneMofNFP/ReadOnlyFile1.txt");

String kFromPath1OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadOnlyFile1%1.txt");
String kToPath1OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadOnlyFile1%1.txt");

String kFromPath2OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadOnlyFile1%2.txt");
String kToPath2OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadOnlyFile1%2.txt");

String kFromPath3OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadOnlyFile1%3.txt");
String kToPath3OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadOnlyFile1%3.txt");

String kFromPath4OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/demo/ReadOnlyFile1%4.txt");
String kToPath4OfReadOnlyFile1 = ManifestHelper::SumPathWithSeperator(kRedundantRoot, "/PerExampleFs/MobilgeneMofNFP/redundant/ReadOnlyFile1%4.txt");

}


namespace mobilgene {
namespace adaptiveautosarperapplication {

PerFPProc::PerFPProc() : shortName(kFPName), fp(nullptr)
{
}

bool PerFPProc::CreateFileAccessorFactoryAndRecoveryFileProxy()
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");

    //set setting to test RecoverFileProxy.
    if(SettingForRecoveryCorruptedFileStorage() == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "Fail to set corrupted file proxy to set Recovery demo scenario for File Proxy.");
        return false;
    }

    //auto result = ara::per::OpenFileStorage(shortName);
    auto result = ara::per::OpenFileStorage(ara::core::InstanceSpecifier(shortName));
    if(result.HasValue()) {
        fp = std::move(result).Value();
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open FileProxy(" << shortName << ")");
    } else {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open FileProxy(" << shortName << ")");
        return false;
    }

    // Check to set setting to test RecoverFileProxy.
    // All files MUST return false.
    if(CreateReadAccessor(kReadOnlyFileName1) || CreateWriteAccessor(kWriteOnlyFileName1) || CreateReadWriteAccessor(kReadWriteFileName1)) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set setting to test RecoverFileProxy(" << shortName << ").");
        return false;
    }

    // To success to recover, File Proxy to open MUST not be opened. So, close File Proxy to open at first.
    if(&fp != nullptr) {
        fp = SharedHandle<ara::per::FileStorage>(nullptr);
    }

    //auto result1 = ara::per::RecoverAllFiles(shortName);
    auto result1 = ara::per::RecoverAllFiles(ara::core::InstanceSpecifier(shortName));
    if(result1.HasValue() == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << __LINE__ << " : " << "fail to recover File Proxy(" << shortName << ")");
        return false;
    }

    // After Recovery, Check File Proxy is created.
    //result = ara::per::OpenFileStorage(shortName);
    result = ara::per::OpenFileStorage(ara::core::InstanceSpecifier(shortName));
    if(result.HasValue()) {
        fp = std::move(result).Value();
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open FileProxy(" << shortName << ")");
    } else {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open FileProxy(" << shortName << ")");
        return false;
    }

    // After Recovery, Check File Proxy is recovered well.
    // All files MUST return true.

    if(CreateReadAccessor(kReadOnlyFileName1) == false && CreateWriteAccessor(kWriteOnlyFileName1) == false && CreateReadWriteAccessor(kReadWriteFileName1) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << __LINE__ << " : " << "fail to Recover FileProxy(" << shortName << ").");
        return false;
    }

    // Check file's list in the proxy using FileProxyAccessorFactory::etAllKeys().
    if(GetAllFiles() == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "expected files are not existed in GetAllKey()'s return.");
        return false;
    }

    readOnlyfile = std::move(UniqueHandle<ara::per::ReadAccessor>(nullptr));
    writeOnlyfile = std::move(UniqueHandle<ara::per::ReadWriteAccessor>(nullptr));
    readwritefile = std::move(UniqueHandle<ara::per::ReadWriteAccessor>(nullptr));

    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    // After Recovery, All Expected files is existed.
    return true;
}

bool PerFPProc::CreateReadAccessor(const String &filename)
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        return false;
    }

    if(!readOnlyfile) {
        auto result = fp->OpenFileReadOnly(filename);
        if(result.HasValue()) {
            readOnlyfile = std::move(result).Value();
            TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateReadAccess()");
        } else {
            TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateReadAccess()");
            return false;
        }
    } else {
        // If file is not created, return false because this result is not expected in this demo scenario.
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "readOnlyfile(" << filename << ") is null");
        return false;
    }
    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::CreateReadWriteAccessor(const String &filename)
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        return false;
    }

    if(!readwritefile) {
        auto result = fp->OpenFileReadWrite(filename);
        if(result.HasValue()) {
            readwritefile = std::move(result).Value();
            TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateRWAccess()");
        } else {
            TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateRWAccess()");
            return false;
        }
    } else {
        // If file is not created, return false because this result is not expected in this demo scenario.
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "readwritefile(" << filename << ") is null");
        return false;
    }
    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::CreateWriteAccessor(const String &filename)
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        return false;
    }

    if(!writeOnlyfile) {
        auto result = fp->OpenFileWriteOnly(filename);
        if(result.HasValue()) {
            writeOnlyfile = std::move(result).Value();
            TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateWriteAccess()");
        } else {
            TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateWriteAccess()");
            return false;
        }
    } else {
        // If file is not created, return false because this result is not expected in this demo scenario.
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "writeOnlyfile(" << filename << ") is null");
        return false;
    }
    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::OperationsInReadAccessor()
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file proxy is not opened. So return false.");
        return false;
    }

    String filename = kReadOnlyFileName1;
    auto result = fp->OpenFileReadOnly(filename);
    if(result.HasValue()) {
        readOnlyfile = std::move(result).Value();
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateReadAccess()");
    } else {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateReadAccess()");
        return false;
    }

    TRACE_INFO("PerFPProc : " << __func__ << " : " << "read file(" << filename << ")'s content(" << kStringReadOnlyFileValue1 << ")");

    // ReadAccessor Class's functions
    // 1. pos_type read (ara::core::Span< char > s) noexcept
    // 2. pos_type getline (ara::core::Span< char > s, char const delim= ’\n’) noexcept

    // pos_type read (ara::core::Span< char > s) noexcept
    // Reads a number of characters into a char pointer, advancing the current position. Returns the actual number of characters that were read.
    {
        char buf[1024];
        ara::core::Span<char> span(buf, 1024);
        ara::per::pos_type pos = readOnlyfile->read(span);
        ara::core::String retval(span.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "Using read(), read file(" << filename << ")'s content(" << retval << ")");

        if(readOnlyfile->eof()) {
            readOnlyfile->clear();
            readOnlyfile->seek(0);
        }
    }

    // pos_type getline (ara::core::Span< char > s, char const delim= ’\n’) noexcept
    {
        ara::core::Array<char, 1024> arr;
        ara::per::pos_type pos = readOnlyfile->getline(arr, '\n');
        ara::core::String retval(arr.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "Using getline(), read file(" << filename << ")'s content(" << retval << ")");

        if(readOnlyfile->eof()) {
            readOnlyfile->clear();
            readOnlyfile->seek(0);
        }
    }

    // reset readOnlyfile
    readOnlyfile = std::move(UniqueHandle<ara::per::ReadAccessor>(nullptr));

    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::OperationsInWriteAccessor()
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file proxy is not opened. So return false.");
        return false;
    }

    String filename = kWriteOnlyFileName1;
    auto result = fp->OpenFileWriteOnly(filename);
    if(result.HasValue()) {
        writeOnlyfile = std::move(result).Value();
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateWriteAccess()");
    } else {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateWriteAccess()");
        return false;
    }
    TRACE_INFO("PerFPProc : " << __func__ << " : " << "write file(" << filename << ")'s content(" << kStringWriteOnlyFileValue1 << ")");

    // ReadWriteAccessor Class's functions
    // 1. pos_type write (ara::core::Span< char > s) noexcept
    // 2. ReadWriteAccessor& operator<< (ara::core::StringView s) noexcept
    // 3. ara::per::ReadWriteAccessor::fsync()

    // pos_type write (ara::core::Span< char > s) noexcept
    // Writes a number of characters from a char pointer. Returns the actual number of characters that were written.
    {
        char buf[] = "AppendText using write()!";
        ara::core::Span<char> span(buf, sizeof(buf));
        writeOnlyfile->write(span);
    }

    // ReadWriteAccessor& operator<< (ara::core::StringView s) noexcept
    {
        writeOnlyfile->seek(-1, ara::per::BasicOperations::SeekOrigin::kEnd);
        *writeOnlyfile << ", AppendText using << operator!";
    }

    // ara::per::ReadWriteAccessor::fsync()
    auto result1 = writeOnlyfile->fsync();
    if(result1.HasValue() == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to sync writeOnlyfile");
        return false;
    }

    // reset readOnlyfile
    writeOnlyfile = std::move(UniqueHandle<ara::per::ReadWriteAccessor>(nullptr));

    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::OperationsInReadWriteAccessor()
{
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    if(&fp == nullptr) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file proxy is not opened. So return false.");
        return false;
    }

    String filename = kReadWriteFileName1;
    auto result = fp->OpenFileReadWrite(filename);
    if(result.HasValue()) {
        readwritefile = std::move(result).Value();
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "success to open file(" << filename << ") by CreateRWAccess()");
    } else {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open file(" << filename << ") by CreateRWAccess()");
        return false;
    }

    TRACE_INFO("PerFPProc : " << __func__ << " : " << "read file(" << filename << ")'s content(" << kStringReadWriteFileValue1 << ")");

    // ReadAccessor Class's functions
    // 1. pos_type read (ara::core::Span< char > s) noexcept
    // 2. pos_type getline (ara::core::Span< char > s, char const delim= ’\n’) noexcept

    // pos_type read (ara::core::Span< char > s) noexcept
    {
        char buf[1024];
        ara::core::Span<char> span(buf, 1024);
        ara::per::pos_type pos = readwritefile->read(span);
        ara::core::String retval(span.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "Using read(), read file(" << filename << ")'s content(" << retval << ")");

        if(readwritefile->eof()) {
            readwritefile->clear();
            readwritefile->seek(0);
        }
    }

    // pos_type getline (ara::core::Span< char > s, char const delim= ’\n’) noexcept
    {
        ara::core::Array<char, 1024> arr;
        ara::per::pos_type pos = readwritefile->getline(arr, '\n');
        ara::core::String retval(arr.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "Using getline(), read file(" << filename << ")'s content(" << retval << ")");

        if(readwritefile->eof()) {
            readwritefile->clear();
            readwritefile->seek(0);
        }
    }

    // ReadWriteAccessor Class's functions
    // 1. pos_type write (ara::core::Span< char > s) noexcept
    // 2. ReadWriteAccessor& operator<< (ara::core::StringView s) noexcept
    // 3. ara::per::ReadWriteAccessor::fsync()

    // pos_type write (ara::core::Span< char > s) noexcept
    // Writes a number of characters from a char pointer. Returns the actual number of characters that were written.
    {
        char buf[] = "AppendText using write()!";
        readwritefile->seek(-1, ara::per::BasicOperations::SeekOrigin::kEnd);
        ara::core::Span<char> span(buf, sizeof(buf));
        readwritefile->write(span);
    }

    // Check file's content after writing using write().
    {
        ara::core::Array<char, 1024> arr;
        readwritefile->seek(0);
        ara::per::pos_type pos = readwritefile->getline(arr, '\n');
        ara::core::String retval(arr.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "After writing using write(), read file(" << filename << ")'s content(" << retval << ")");

        if(readwritefile->eof()) {
            readwritefile->clear();
            readwritefile->seek(0);
        }
    }

    // ReadWriteAccessor& operator<< (ara::core::StringView s) noexcept
    {
        readwritefile->seek(-1, ara::per::BasicOperations::SeekOrigin::kEnd);
        *readwritefile << ", AppendText using << operator!";
    }

    // Check file's content after writing using << operator.
    {
        ara::core::Array<char, 1024> arr;
        readwritefile->seek(0);
        ara::per::pos_type pos = readwritefile->getline(arr, '\n');
        ara::core::String retval(arr.data(), static_cast<std::streamoff>(pos));
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "After writing using << operator, read file(" << filename << ")'s content(" << retval << ")");

        if(readwritefile->eof()) {
            readwritefile->clear();
            readwritefile->seek(0);
        }
    }

    // ara::per::ReadWriteAccessor::fsync()
    auto result1 = readwritefile->fsync();
    if(result1.HasValue() == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to sync readwritefile");
        return false;
    }

    // reset readwritefile
    readwritefile = std::move(UniqueHandle<ara::per::ReadWriteAccessor>(nullptr));

    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

bool PerFPProc::GetAllFiles() {
    if(&fp == nullptr) {
        // If File Proxy is not created, return false because this result is not expected in this demo scenario.
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fp(" << shortName << ") is null");
        return false;
    }

    auto res = fp->GetAllFileNames();
    auto files = res.Value();
    for(auto file : files) {
        TRACE_INFO("PerFPProc : " << __func__ << " : " << "file name(" << file << ")");
    }

    if(std::find(files.begin(), files.end(), kReadOnlyFileName1) == files.end()) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file(" << kReadOnlyFileName1 << ") is not included in the file list.");
        return false;
    }
    if(std::find(files.begin(), files.end(), kWriteOnlyFileName1) == files.end()) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file(" << kWriteOnlyFileName1 << ") is not included in the file list.");
        return false;
    }
    if(std::find(files.begin(), files.end(), kReadWriteFileName1) == files.end()) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "file(" << kReadWriteFileName1 << ") is not included in the file list.");
        return false;
    }

    return true;
}

bool PerFPProc::SettingForRecoveryCorruptedFileStorage() {
    // setting all files in file proxy's redundant folder.
    if(CopyFile(kFromPath2OfReadOnlyFile1.c_str(), kToPath2OfReadOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath2OfReadOnlyFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath3OfReadOnlyFile1.c_str(), kToPath3OfReadOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath3OfReadOnlyFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath4OfReadOnlyFile1.c_str(), kToPath4OfReadOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath4OfReadOnlyFile1 << ").");
        return false;
    }

    if(CopyFile(kFromPath2OfWriteOnlyFile1.c_str(), kToPath2OfWriteOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath2OfWriteOnlyFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath3OfWriteOnlyFile1.c_str(), kToPath3OfWriteOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath3OfWriteOnlyFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath4OfWriteOnlyFile1.c_str(), kToPath4OfWriteOnlyFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath4OfWriteOnlyFile1 << ").");
        return false;
    }

    if(CopyFile(kFromPath2OfReadWriteFile1.c_str(), kToPath2OfReadWriteFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath2OfReadWriteFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath3OfReadWriteFile1.c_str(), kToPath3OfReadWriteFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath3OfReadWriteFile1 << ").");
        return false;
    }
    if(CopyFile(kFromPath4OfReadWriteFile1.c_str(), kToPath4OfReadWriteFile1.c_str()) == false) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to set recovery file setting(" << kToPath4OfReadWriteFile1 << ").");
        return false;
    }

    return true;
}

bool PerFPProc::CopyFile(const String &fromPath, const String &toPath) {
    TRACE_INFO("PerFPProc : " << __func__ << " :  start");
    TRACE_INFO("PerFPProc : " << __func__ << " :  fromPath(" << fromPath << ")");
    TRACE_INFO("PerFPProc : " << __func__ << " :  toPath(" << toPath << ")");
    if(fromPath.empty() || toPath.empty()) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "return false because fromPath or toPath is empty.");
        return false;
    }

    if (access(fromPath.c_str(), F_OK) !=0) {
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "return false because fromPath doesn't exist(" << fromPath << ")");
        return false;
    }

    FILE* fromStream = fopen(fromPath.c_str(), "rb");
    if (!fromStream) {
        // I/O error: check errno
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open fromPath(" << fromPath << ")");
        return false;
    }

    FILE* toStream = fopen(toPath.c_str(), "wb");
    if (!toStream) {
        // I/O error: check errno
        fclose(fromStream);
        TRACE_ERROR("PerFPProc : " << __func__ << " : " << "fail to open toPath(" << toPath << ")");
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
                    TRACE_ERROR("PerFPProc : " << __func__ << " : " << "ferror 1");
                    return false;
                }
            }
        }

        if (readBytes != sizeof(buf)) {
            if (ferror(fromStream)) {
                // reading file error: check errno
                fclose(fromStream);
                fclose(toStream);
                TRACE_ERROR("PerFPProc : " << __func__ << " : " << "ferror 2");
                return false;
            }
        }
    } while (!feof(fromStream));

    fclose(fromStream);
    fclose(toStream);

    TRACE_INFO("PerFPProc : " << __func__ << " :  end");
    return true;
}

}
}
