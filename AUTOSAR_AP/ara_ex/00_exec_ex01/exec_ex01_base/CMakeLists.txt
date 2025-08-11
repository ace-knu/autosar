#######################################################################################################################
#  REVISION HISTORY
#  -------------------------------------------------------------------------------------------------------------------
#  Refer to the module's ChangeHistory.txt
#
#
#  FILE VERSION
#  -------------------------------------------------------------------------------------------------------------------
#  The file version is identical to the component version. To determine the actual version of the component,
#  see the user manual.
#
#######################################################################################################################
# --------------------------------------------------------------------------------------
# |                                                                                    |
# |      888    888                                 888          d8b                   |
# |      888    888                                 888          Y8P                   |
# |      888    888                                 888                                |
# |      8888888888 888  888 888  888 88888b.   .d88888  8888b.  888                   |
# |      888    888 888  888 888  888 888 "88b d88" 888     "88b 888                   |
# |      888    888 888  888 888  888 888  888 888  888 .d888888 888                   |
# |      888    888 Y88b 888 Y88b 888 888  888 Y88b 888 888  888 888                   |
# |      888    888  "Y88888  "Y88888 888  888  "Y88888 "Y888888 888                   |
# |                      888                                                           |
# |                 Y8b d88P                                                           |
# |                  "Y88P"                                                            |
# |             d8888          888                                                     |
# |            d88888          888                                                     |
# |           d88P888          888                                                     |
# |          d88P 888 888  888 888888  .d88b.   .d88b.  888  888  .d88b.  888d888      |
# |         d88P  888 888  888 888    d88""88b d8P  Y8b 888  888 d8P  Y8b 888P"        |
# |        d88P   888 888  888 888    888  888 88888888 Y88  88P 88888888 888          |
# |       d8888888888 Y88b 888 Y88b.  Y88..88P Y8b.      Y8bd8P  Y8b.     888          |
# |      d88P     888  "Y88888  "Y888  "Y88P"   "Y8888    Y88P    "Y8888  888          |
# |                                                                                    |
# --------------------------------------------------------------------------------------
# |                                                                                    |
# |  (C) 2019 HYUNDAI AUTOEVER Co., Ltd.                                               |
# |  Confidential Proprietary Information. Distribution Limited.                       |
# |  Do Not Copy Without Prior Permission                                              |
# |                                                                                    |
# --------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.5)

project(EXEC_EX01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type (can be overridden by user)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
        "Choose the type of build: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif()

if(NOT MGA_INSTALL_SAMPLE_APP_DIR)
    set(MGA_INSTALL_SAMPLE_APP_DIR ${CMAKE_INSTALL_PREFIX}/sampleApp)

    # add cmake prefix variable
    list(APPEND CMAKE_PREFIX_PATH ${MGA_INSTALL_CMAKE_CFG_DIR})

    # internal variabl predefine
    add_definitions(-DMGA_CONFIG_STATE_PIPE_MAX_BUFF_SIZE=128)
endif()

add_definitions(-DHAS_HASOMEIP_BINDING)
add_definitions(-DEM_ARA_LOG_MODE)#qnx ara_logging, cout

if (${CMAKE_SYSTEM_NAME} MATCHES "VxWorks")#not checked
add_definitions(-DMGA_CONFIG_MGA_VOLATILE_DIR="${MGA_CONFIG_MGA_VOLATILE_DIR}")
add_definitions(-DMGA_CONFIG_MGA_NON_VOLATILE_DIR="${MGA_CONFIG_MGA_NON_VOLATILE_DIR}")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "QNX")
if(MGA_CONFIG_EXEC_QNX_EMULATOR)
add_definitions(-DMGA_CONFIG_MGA_VOLATILE_DIR="${MGA_CONFIG_MGA_VOLATILE_DIR}")#/tmp/mobilgene
add_definitions(-DMGA_CONFIG_MGA_NON_VOLATILE_DIR="${MGA_CONFIG_MGA_NON_VOLATILE_DIR}")#/tmp/mobilgene
else()
add_definitions(-DMGA_CONFIG_MGA_VOLATILE_DIR="${MGA_CONFIG_MGA_VOLATILE_DIR}")
add_definitions(-DMGA_CONFIG_MGA_NON_VOLATILE_DIR="${MGA_CONFIG_MGA_NON_VOLATILE_DIR}")
endif()
else()#linux
add_definitions(-DMGA_CONFIG_MGA_VOLATILE_DIR="${MGA_CONFIG_MGA_VOLATILE_DIR}")
add_definitions(-DMGA_CONFIG_MGA_NON_VOLATILE_DIR="${MGA_CONFIG_MGA_NON_VOLATILE_DIR}")
endif()

# Subdirectories
# based on rootfs image creation
set(MACHINE_NAME "Machine_ECU")
set(MACHINE_NUMBER "1")
set(MACHINE_DESIGN_NAME "MachineDesign_ECU")
string(TOLOWER ${MACHINE_NAME} MACHINE_NAME_LOWER)
set(LOG_LEVEL "debug")
set(ARXML_BASE ${PROJECT_SOURCE_DIR}/ARXML)

# exec_demo_kill.sh
install(FILES exec_demo_kill.sh PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE DESTINATION ${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME})

# exec_demo_s32g_set_test.sh
install(FILES exec_demo_s32g_set_test.sh PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE DESTINATION ${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME})

if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")
# exec_demo_s32g_set_test.sh
install(FILES exec_demo_kill_qnx.sh PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE DESTINATION ${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME})
endif()

# add_subdirectory(StateManagerProc)
add_subdirectory(EmApp1)
add_subdirectory(SMD)
