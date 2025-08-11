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
#  ---------------------------------------------------------------------------
#  |                                                                         |
#  |       888    888                                 888          d8b       |
#  |       888    888                                 888          Y8P       |
#  |       888    888                                 888                    |
#  |       8888888888 888  888 888  888 88888b.   .d88888  8888b.  888       |
#  |       888    888 888  888 888  888 888 "88b d88" 888     "88b 888       |
#  |       888    888 888  888 888  888 888  888 888  888 .d888888 888       |
#  |       888    888 Y88b 888 Y88b 888 888  888 Y88b 888 888  888 888       |
#  |       888    888  "Y88888  "Y88888 888  888  "Y88888 "Y888888 888       |
#  |                       888                                               |
#  |                  Y8b d88P                                               |
#  |                   "Y88P"                                                |
#  |       d8888          888                                                | 
#  |      d88888          888                                                | 
#  |     d88P888          888                                                | 
#  |    d88P 888 888  888 888888  .d88b.   .d88b.  888  888  .d88b.  888d888 | 
#  |   d88P  888 888  888 888    d88""88b d8P  Y8b 888  888 d8P  Y8b 888P"   | 
#  |  d88P   888 888  888 888    888  888 88888888 Y88  88P 88888888 888     | 
#  | d8888888888 Y88b 888 Y88b.  Y88..88P Y8b.      Y8bd8P  Y8b.     888     | 
#  |d88P     888  "Y88888  "Y888  "Y88P"   "Y8888    Y88P    "Y8888  888     |
#  |                                                                         |
#  ---------------------------------------------------------------------------
#  |                                                                         |
#  |  (C) 2019 HYUNDAI AUTOEVER Co., Ltd.                                    |
#  |  Confidential Proprietary Information. Distribution Limited.            |
#  |  Do Not Copy Without Prior Permission                                   |
#  |                                                                         |
#  ---------------------------------------------------------------------------

# Set Process Name
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME REALPATH)
set(PROCESS_NAME "PerExampleFs")
set(EXECUTABLE_NAME "PerExampleFsEx")
string(TOLOWER ${PROCESS_NAME} PROCESS_NAME_LOWER)
string(TOLOWER ${MACHINE_NAME} MACHINE_NAME_LOWER)
set(BINARY_MAKE_TARGET ${PROCESS_NAME}Generated)
set(MBG_GEN_DIR "${PROJECT_BINARY_DIR}/${PROCESS_NAME}/gen")
set(EM_CONFIG_FILENAME ${MBG_GEN_DIR}/manifest/${MACHINE_NAME_LOWER}_machine/${PROCESS_NAME_LOWER}_execution.json)
set(ARA_ROOT_PATH ${MGA_CONFIG_MGA_INSTALL_PREFIX})
set(ARA_ROOT_PATH_PRJ "${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME}")
set(EXECUTABLE_INSTALL_PATH "${MGA_INSTALL_SAMPLE_APP_DIR}/${PROJECT_NAME}/opt/${PROCESS_NAME}")
set(MACHINE_MANIFEST_NAME "${MBG_GEN_DIR}/manifest/${MACHINE_NAME_LOWER}_machine/${MACHINE_NAME_LOWER}_manifest.json")

message(STATUS "FOLDER_NAME: ${FOLDER_NAME} \n"
			   "EXECUTABLE_NAME : ${EXECUTABLE_NAME} \n"
	           "PROCESS_NAME : ${PROCESS_NAME}\n"
			   "gen destination : ${MBG_GEN_DIR}\n"
			   "install path : ${EXECUTABLE_INSTALL_PATH}")

# Setting generated file directory

# Find required packages
find_package(ara_gen REQUIRED)
find_package(ara_logging REQUIRED)
find_package(ara_per REQUIRED)
find_package(ara_exec REQUIRED)

# Find library for exec
find_library(ARA_EXEC_LIB ara_exec)

# Find library for log
find_library(ARA_LOG_LIB ara_logging)

# Find library for dlt
find_library(DLT_LIB dlt)

# Find library for crc
#find_library(CRC_LIB ara_crc)
set(CRC_LIB ara_crc)

set(ARA_LIBRARIES ara::ara_per ${MGA_LIB_JSON})

# message(STATUS "ARA_LIBRARIES: ${ARA_LIBRARIES}")

# Found library lists
set(EXT_LIBS ${ARA_EXEC_LIB} ${ARA_EXEC_OS_LIB} 
             ${ARA_EXEC_CONFIG_LIB} ${ARA_EXEC_PIPE_NAME}
             ${ARA_LOG_LIB} ${DLT_LIB} ${CRC_LIB} ${MGA_LIB_PTHREAD})

# List of ARXML files
file(GLOB FULL_ARXMLS ${PROJECT_SOURCE_DIR}/ARXML/*.arxml
	${PROJECT_SOURCE_DIR}/ARXML/*/*.arxml
	${PROJECT_SOURCE_DIR}/ARXML/*/*/*.arxml
	${PROJECT_SOURCE_DIR}/ARXML/*/*/*/*.arxml
	)

# Generating all files
add_aragen(
    DESTINATION ${MBG_GEN_DIR}
	TARGET ${BINARY_MAKE_TARGET} 
    LOG_CONSOLE
    ARXMLS ${FULL_ARXMLS}
)

# persistency config
add_pergen(
    DESTINATION ${MBG_GEN_DIR}
    TARGET ${PROCESS_NAME}PERGenerated
    PERSISTENCY ${PROCESS_NAME}
    PERSISTENCY_PATH ${PROJECT_SOURCE_DIR}
    ARXMLS ${FULL_ARXMLS}
)

# Application source file lists
file(GLOB CPP_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utility/*.cpp
)

message(STATUS "---------------------------------------------------")
message(STATUS "${PROCESS_NAME} - Importing dependencies -------------------")

# Include platform header files
include_directories(
    ${MGA_INSTALL_INC_DIR} 
    ${ARA_INCLUDE_DIRS} 
    ${MGA_INSTALL_INC_DIR}/libsupport 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    utility
)
link_directories(${MGA_INSTALL_LIB_DIR})

# Build adaptive application (incl. Core glue code)
add_executable(${PROCESS_NAME} ${CPP_SRCS})

target_link_libraries(${PROCESS_NAME} ${ARA_LIBRARIES} ${EXT_LIBS})
message(STATUS "${ARA_LIBRARIES} - ARA_LIBRARIES dependencies -------------------")
message(STATUS "${EXT_LIBS} - EXT_LIBS dependencies -------------------")

add_dependencies(${PROCESS_NAME} ${BINARY_MAKE_TARGET})

install(TARGETS ${PROCESS_NAME} RUNTIME DESTINATION ${EXECUTABLE_INSTALL_PATH}/${MGA_CONFIG_MGA_INSTALL_BIN_DIR})

# EM manifest
install(FILES ${EM_CONFIG_FILENAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc RENAME em_manifest.json)

# machine manifest file install
install(FILES ${MACHINE_MANIFEST_NAME} PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${ARA_ROOT_PATH_PRJ}/${MGA_CONFIG_MGA_INSTALL_ETC_DIR}/system RENAME machine_manifest.json)

# Persistent db
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/manifest/kvsdatabase.json PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc)

# Persistency Manifest
install(FILES ${MBG_GEN_DIR}/per_manifest.json PERMISSIONS OWNER_READ GROUP_READ WORLD_READ DESTINATION ${EXECUTABLE_INSTALL_PATH}/etc)

# Install for training demo
set(REDUNDANCY_ROOT_DIR ${ARA_ROOT_PATH}/${MGA_CONFIG_MGA_INSTALL_ETC_DIR}/redundant/red1)

include("../macro.cmake")

SUBDIRLIST(SUBDIRS ${MBG_GEN_DIR})
FOREACH(subdir ${SUBDIRS})
	IF(EXISTS ${MBG_GEN_DIR}/${subdir}/${subdir})
        # install files storage
  		install(DIRECTORY ${MBG_GEN_DIR}/${subdir}/${subdir} DESTINATION ${EXECUTABLE_INSTALL_PATH}/${MGA_CONFIG_MGA_INSTALL_VAR_DIR})
        # install file's extra storage
        if(EXISTS ${MBG_GEN_DIR}/${subdir}/${subdir}_extra)
  		    install(FILES ${MBG_GEN_DIR}/${subdir}/${subdir}_extra DESTINATION ${EXECUTABLE_INSTALL_PATH}/${MGA_CONFIG_MGA_INSTALL_VAR_DIR})
        ENDIF()
	ELSEIF(EXISTS ${MBG_GEN_DIR}/${subdir}/${subdir}.json)
        # install kvs storage
  		install(FILES ${MBG_GEN_DIR}/${subdir}/${subdir}.json DESTINATION ${EXECUTABLE_INSTALL_PATH}/${MGA_CONFIG_MGA_INSTALL_VAR_DIR})
        # install kvs' extra storage
        IF(EXISTS ${MBG_GEN_DIR}/${subdir}/${subdir}.json_extra)
  		    install(FILES ${MBG_GEN_DIR}/${subdir}/${subdir}.json_extra DESTINATION ${EXECUTABLE_INSTALL_PATH}/${MGA_CONFIG_MGA_INSTALL_VAR_DIR})
        ENDIF()
	ENDIF()

  	install(DIRECTORY ${MBG_GEN_DIR}/${subdir} DESTINATION ${REDUNDANCY_ROOT_DIR}/${PROCESS_NAME})
ENDFOREACH()

# Setting for demo scenario
# Setting about currpted kvs files for recovery test in persistencykvsdemo application.
set(FS_1 "MobilgeneMofNFP")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/${PROCESS_NAME}/files/${FS_1}/demo DESTINATION ${REDUNDANCY_ROOT_DIR}/${PROCESS_NAME}/${FS_1}/redundant)

#add_definitions(-DFEATURE_USE_COUT_LOG)

