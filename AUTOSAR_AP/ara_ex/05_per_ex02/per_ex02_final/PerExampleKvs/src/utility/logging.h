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

#ifndef MOBILGENE_ADAPTIVEAUTOSARAPPLICATION_UTILITY_LOGGING_H_
#define MOBILGENE_ADAPTIVEAUTOSARAPPLICATION_UTILITY_LOGGING_H_

#include "ara/core/string_view.h"
#include "ara/log/logging.h"
#include "ara/log/logger.h"

namespace mobilgene
{
namespace adaptiveautosarperapplication
{
namespace utility
{

ara::log::Logger& logger();

} /* namespace utility */
} /* namespace adaptiveautosarperapplication */
} /* namespace mobilgene */

#endif  // MOBILGENE_ADAPTIVEAUTOSARAPPLICATION_UTILITY_LOGGING_H_
