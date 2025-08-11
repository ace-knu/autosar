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

# Set Process Name

set(PROCESS_NAME SMD)
set(EXECUTABLE_NAME "/mga/autoever/sample/smd/smd")
set(PROCESS_FQN "/mga/autoever/sample/smd/${MACHINE_NAME_LOWER}/${PROCESS_NAME}")

# get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME REALPATH)
set(FOLDER_NAME ${PROCESS_NAME})
string(TOLOWER ${PROCESS_NAME} PROCESS_NAME_LOWER)
set(BINARY_MAKE_TARGET ${PROCESS_NAME}Generated)
set(MBG_GEN_DIR "${PROJECT_BINARY_DIR}/${FOLDER_NAME}/gen")
set(EM_CONFIG_FILENAME ${MBG_GEN_DIR}/manifest/${MACHINE_NAME_LOWER}_machine/${PROCESS_NAME_LOWER}_execution.json)
set(SOMEIP_CONFIG_FILENAME ${MBG_GEN_DIR}/machines/someip/${MACHINE_NAME_LOWER}_someip.json)
set(MACHINE_MANIFEST_FILENAME "${MBG_GEN_DIR}/manifest/${MACHINE_NAME_LOWER}_machine/${MACHINE_NAME_LOWER}_manifest.json")
set(ARA_INCLUDE_DIRS "${MBG_GEN_DIR}/includes" "${CMAKE_SOURCE_DIR}/ara-api/com/inc")
set(ARA_ROOT_PATH "${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME}")
set(EXECUTABLE_INSTALL_PATH "${ARA_ROOT_PATH}/${MGA_CONFIG_MGA_INSTALL_OPT_DIR}/${FOLDER_NAME}")
set(MACHINE_MANIFEST_INSTALL_PATH "${ARA_ROOT_PATH}/${MGA_CONFIG_MGA_INSTALL_ETC_DIR}/system")

message(STATUS "FOLDER_NAME: ${FOLDER_NAME} \n"
			   "EXECUTABLE_NAME : ${EXECUTABLE_NAME} \n"
	           "PROCESS_NAME : ${PROCESS_NAME}\n"
			   "gen destination : ${MBG_GEN_DIR}\n"
			   "install path : ${EXECUTABLE_INSTALL_PATH}")

# add_definitions(-DHAS_HASOMEIP_BINDING)

# Setting generated file directory

# Find required packages
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")#ara_gen, ara_logging
find_package(ara_gen REQUIRED)
find_package(ara_logging REQUIRED)
else()
find_package(ara_gen REQUIRED)
find_package(ara_logging REQUIRED)
endif()
find_package(ara_per REQUIRED)
find_package(ara_exec REQUIRED)

# Find library for exec
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")
find_library(ARAEXEC_LIBRARIES ara_exec)
else()
find_library(ARA_EXEC_LIB ara_exec)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")
# Find library for log
find_library(ARA_LOG_LIB ara_logging)

# Find library for dlt
find_library(DLT_LIB dlt)

# Found library lists
set(CRYPTO_LIBS "ara_crypto")
set(EXT_LIBS ${ARAEXEC_LIBRARIES} ${ARA_EXEC_OS_LIB} ${ARA_LOG_LIB} ${DLT_LIB}
             ${ARA_EXEC_CONFIG_LIB} ${ARA_EXEC_PIPE_NAME} ${CRYPTO_LIBS} ara_per ara_crc)
else()
# Find library for log
find_library(ARA_LOG_LIB ara_logging)

# Find library for dlt
find_library(DLT_LIB dlt)

# Found library lists
set(EXT_LIBS ${ARA_EXEC_LIB} ${ARA_EXEC_OS_LIB} 
             ${ARA_EXEC_CONFIG_LIB} ${ARA_EXEC_PIPE_NAME}
             ${ARA_LOG_LIB} ${DLT_LIB} ${MGA_LIB_PTHREAD} ${MGA_LIB_CPPFS})
endif()

file(GLOB FULL_ARXMLS ${PROJECT_SOURCE_DIR}/ARXML/machine/Machine.arxml
    ${PROJECT_SOURCE_DIR}/ARXML/applications/smd.arxml
    )

# Generating all files
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")#em_manifest.json
add_aragen(
    DESTINATION ${MBG_GEN_DIR}
        TARGET ${BINARY_MAKE_TARGET}
    LOG_CONSOLE
        ARXMLS ${FULL_ARXMLS}
)
else()
add_aragen(
    DESTINATION ${MBG_GEN_DIR}
        TARGET ${BINARY_MAKE_TARGET}
    LOG_CONSOLE
        ARXMLS ${FULL_ARXMLS}
)
endif()

# Application source file lists
file(GLOB CPP_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(FILE_SRCS
        ${CPP_SRCS}
		${${BINARY_MAKE_TARGET}_SOURCES}
		${${BINARY_MAKE_TARGET}_HEADERS}
)

message(STATUS "---------------------------------------------------")
message(STATUS "${PROCESS_NAME} - Importing dependencies -------------------")

# Include platform header files
include_directories(${MGA_INSTALL_INC_DIR} ${ARA_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories(${MGA_INSTALL_LIB_DIR})

if (${CMAKE_SYSTEM_NAME} MATCHES "VxWorks")#not checked
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -D_GLIBCXX_USE_NANOSLEEP -DLINUX -DHAS_SOMEIP_BINDING")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "QNX")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -D_GLIBCXX_USE_NANOSLEEP -DLINUX -DHAS_SOMEIP_BINDING")
else()#linux
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Werror -D_GLIBCXX_USE_NANOSLEEP -DLINUX -DHAS_SOMEIP_BINDING")
endif()

# Build adaptive application (incl. Core glue code)
add_executable(${PROCESS_NAME} ${FILE_SRCS})

# Target link libraries
target_link_libraries(${PROCESS_NAME} ${ARA_LIBRARIES} ${EXT_LIBS})

# message(STATUS "${ARA_LIBRARIES} - ARA_LIBRARIES dependencies -------------------")
message(STATUS "${EXT_LIBS} - EXT_LIBS dependencies -------------------")

if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")
add_dependencies(${PROCESS_NAME} ${BINARY_MAKE_TARGET})
else()
add_dependencies(${PROCESS_NAME} ${BINARY_MAKE_TARGET})
endif()

# Install executable binary
install(TARGETS ${PROCESS_NAME} RUNTIME DESTINATION ${EXECUTABLE_INSTALL_PATH}/bin)

# Install execution manifest file
# EM manifest
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")#em_manifest.json
install(FILES ${EM_CONFIG_FILENAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc RENAME em_manifest.json)
#install(FILES ${PROJECT_SOURCE_DIR}/exec_sample/${PROCESS_NAME}/etc/em_manifest.json PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc RENAME em_manifest.json)
else()
install(FILES ${EM_CONFIG_FILENAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc RENAME em_manifest.json)
endif()

# Machine Manifest
# : Installation of machine_manifest.json is only for exec_demo.
# : Normal Application doesn't install machine_manifest.json file.
if(${CMAKE_SYSTEM_NAME} MATCHES "QNX")#machine_manifest.json
install(FILES ${MACHINE_MANIFEST_FILENAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${MACHINE_MANIFEST_INSTALL_PATH} RENAME machine_manifest.json)
#install(FILES ${PROJECT_SOURCE_DIR}/exec_sample/machine_manifest.json PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${MACHINE_MANIFEST_INSTALL_PATH})
else()
install(FILES ${MACHINE_MANIFEST_FILENAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${MACHINE_MANIFEST_INSTALL_PATH} RENAME machine_manifest.json)
endif()

add_subdirectory(command)

