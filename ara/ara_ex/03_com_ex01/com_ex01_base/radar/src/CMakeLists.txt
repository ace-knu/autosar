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

set(APP_NAME radar)
set(PROCESS_NAME radarService_Process)
string(TOLOWER ${PROCESS_NAME} PROCESS_NAME_LOWER)
set(APP_EXECUTABLE ${APP_NAME})
set(BINARY_MAKE_TARGET ${APP_NAME}Generated)

message(STATUS "---------------------------------------------------")
message(STATUS "${APP_EXECUTABLE} - Importing dependencies -------------------")
set(GEN_DEST ${PROJECT_BINARY_DIR}/gen/${APP_NAME})
set(ARA_INCLUDE_DIRS "${GEN_DEST}/includes" "${CMAKE_SOURCE_DIR}/ara-api/com/inc")

message(STATUS "ARAGEN_PATH: ${ARAGEN_PATH}")

file(GLOB PLATFORM_ARXMLS ${MGA_PLATFORM_ARXML_DIR}/machine/mga_iamd_PMM.arxml ${MGA_PLATFORM_ARXML_DIR}/mga_localipcd/*.arxml ${MGA_PLATFORM_ARXML_DIR}/mga_iamd/*.arxml)
file(GLOB COMMON_ARXMLS ${PROJECT_SOURCE_DIR}/common/model/*.arxml ${MGA_ARXML_PLATFORM_DIR}/Common/*.arxml)
file(GLOB APP_ARXMLS ${PROJECT_SOURCE_DIR}/${APP_NAME}/manifest/*.arxml)

set(ARXMLS ${PLATFORM_ARXMLS} ${COMMON_ARXMLS} ${APP_ARXMLS})

if(DEFINED SCHEMA)
add_aragen(
        DESTINATION ${GEN_DEST}
        TARGET ${BINARY_MAKE_TARGET}
        SCHEMA ${SCHEMA}
        ARXMLS ${ARXMLS}
        GENERATE "CODE,CONFIG,RECURSIVE"
        USER_DEFINED_LIBS "ipc"
)
else(DEFINED SCHEMA)
add_aragen(
        DESTINATION ${GEN_DEST}
        TARGET ${BINARY_MAKE_TARGET}
        ARXMLS ${ARXMLS}
        GENERATE "CODE,CONFIG,RECURSIVE"
        USER_DEFINED_LIBS "ipc"
)
endif(DEFINED SCHEMA)

# Application
set(ADAPTIVEAUTOSARAPPLICATION_src
        main_${APP_NAME}.cpp
        ${APP_NAME}_activity.cpp
        ../inc/${APP_NAME}_activity.h
        ${${BINARY_MAKE_TARGET}_SOURCES}
)
include(../../common/cmake/CMakeLists_post.txt)
