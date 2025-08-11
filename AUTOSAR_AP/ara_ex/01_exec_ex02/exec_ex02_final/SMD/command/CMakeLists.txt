#  --------------------------------------------------------------------------
#  |              _    _ _______     .----.      _____         _____        |
#  |         /\  | |  | |__   __|  .  ____ .    / ____|  /\   |  __ \       |
#  |        /  \ | |  | |  | |    .  / __ \ .  | (___   /  \  | |__) |      |
#  |       / /\ \| |  | |  | |   .  / / / / v   \___ \ / /\ \ |  _  /       |
#  |      / /__\ \ |__| |  | |   . / /_/ /  .   ____) / /__\ \| | \ \       |
#  |     /________\____/   |_|   ^ \____/  .   |_____/________\_|  \_\      |
#  |                              . _ _  .                                  |
#  --------------------------------------------------------------------------
#
#  All Rights Reserved.
#  Any use of this source code is subject to a license agreement with the
#  AUTOSAR development cooperation.
#  More information is available at www.autosar.org.
#
#  Disclaimer
#
#  This work (specification and/or software implementation) and the material
#  contained in it, as released by AUTOSAR, is for the purpose of information
#  only. AUTOSAR and the companies that have contributed to it shall not be
#  liable for any use of the work.
#
#  The material contained in this work is protected by copyright and other
#  types of intellectual property rights. The commercial exploitation of the
#  material contained in this work requires a license to such intellectual
#  property rights.
#
#  This work may be utilized or reproduced without any modification, in any
#  form or by any means, for informational purposes only. For any other
#  purpose, no part of the work may be utilized or reproduced, in any form
#  or by any means, without permission in writing from the publisher.
#
#  The work has been developed for automotive applications only. It has
#  neither been developed, nor tested for non-automotive applications.
#
#  The word AUTOSAR and the AUTOSAR logo are registered trademarks.
#  --------------------------------------------------------------------------

######## Build and include settings ########
# Find required packages
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")
find_package(ara_logging REQUIRED)

# Find library for log
find_library(ARA_LOG_LIB ara_logging)

# Find library for dlt
find_library(DLT_LIB dlt)

# Found library lists
set(EXT_LIBS ${ARA_LOG_LIB} ${DLT_LIB})
else()
find_package(ara_logging REQUIRED)

# Find library for log
find_library(ARA_LOG_LIB ara_logging)

# Find library for dlt
find_library(DLT_LIB dlt)

# Found library lists
set(EXT_LIBS ${ARA_LOG_LIB} ${DLT_LIB})
endif()

set(ARA_INCLUDE_DIRS "${MBG_GEN_DIR}/includes")

# Include platform header files
include_directories(${MGA_INSTALL_INC_DIR} ${ARA_INCLUDE_DIRS})
link_directories(${MGA_INSTALL_LIB_DIR})

if (${CMAKE_SYSTEM_NAME} MATCHES "VxWorks")#not checked
add_compile_options(-g -O0 -Wall -DDEFAULT_LOG_LVL=6)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "QNX")
add_compile_options(-g -O0 -Werror -DDEFAULT_LOG_LVL=6)
else()
#issue in Werror in s32g : Warning _FORTIFY_SOURCE requires compiling with optimization
#add_compile_options(-g -O0 -Werror -DDEFAULT_LOG_LVL=6)
add_compile_options(-g -Werror -DDEFAULT_LOG_LVL=6)
endif()

add_executable(
    ara-state-change
    main.cpp
)

# target_link_libraries
target_link_libraries(ara-state-change ${EXT_LIBS})

set(ARA_ROOT_PATH "${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME}")

######## Install targets ########
install(TARGETS ara-state-change
    RUNTIME DESTINATION ${ARA_ROOT_PATH}
)
