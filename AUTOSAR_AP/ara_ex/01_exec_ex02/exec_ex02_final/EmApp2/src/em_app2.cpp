
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "em_app2.h"


/**********************************************************************************************************************
 *  VARIABLES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

namespace mga {
namespace autoever {
namespace sample {

EmApp2::EmApp2(int32_t num)
    : app_num(num),
      em_app2_logger{ara::log::CreateLogger("CTX2", "EM APP2", ara::log::LogLevel::kVerbose)} {}

EmApp2::~EmApp2() {}

void EmApp2::Init()
{
    if(app_num == 1)    em_app2_logger.LogInfo() << "APP2 Instance 1 Init Function start.";
    else                em_app2_logger.LogInfo() << "APP2 Instance 2 Init Function start.";
}

void EmApp2::Act()
{
    // em_app2_logger.LogInfo() << "APP2 Act Function start.";
}

}  // namespace sample
}  // namespace autoever
}  // namespace mga



