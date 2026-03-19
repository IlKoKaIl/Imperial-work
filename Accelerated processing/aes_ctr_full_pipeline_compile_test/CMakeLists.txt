# Direct CMake to use icpx rather than the default C++ compiler/linker on Linux
# and icx-cl on Windows.
if(UNIX)
    set(CMAKE_CXX_COMPILER icpx)
else()
    include(CMakeForceCompiler)
    CMAKE_FORCE_CXX_COMPILER(icx-cl IntelDPCPP)
    include(Platform/Windows-Clang)
endif()

cmake_minimum_required(VERSION 3.7.2)

project(aes_ctr_full_pipeline_compile_test CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

###############################################################################
### Customize these build variables
###############################################################################
set(SOURCE_FILES src/aes_ctr_full_pipeline_compile_test.cpp)
set(TARGET_NAME aes_ctr_full_pipeline_compile_test)

if(NOT DEFINED FPGA_DEVICE)
    set(FPGA_DEVICE "Agilex7")
    message(STATUS "FPGA_DEVICE was not specified.\
                    \nConfiguring the design to the default FPGA family target: ${FPGA_DEVICE}\
                    \nPlease refer to the README for information on target selection.")
endif()

set(USER_FPGA_FLAGS ${USER_FPGA_FLAGS})
set(USER_FLAGS ${USER_FLAGS})
set(USER_INCLUDE_PATHS include;${USER_INCLUDE_PATHS})

###############################################################################
### no changes after here
###############################################################################

set(EMULATOR_TARGET fpga_emu)
set(SIMULATOR_TARGET fpga_sim)
set(REPORT_TARGET report)
set(FPGA_TARGET fpga)

set(EMULATOR_OUTPUT_NAME ${TARGET_NAME}.${EMULATOR_TARGET})
set(SIMULATOR_OUTPUT_NAME ${TARGET_NAME}.${SIMULATOR_TARGET})
set(REPORT_OUTPUT_NAME ${TARGET_NAME}.${REPORT_TARGET})
set(FPGA_OUTPUT_NAME ${TARGET_NAME}.${FPGA_TARGET})

message(STATUS "Additional USER_FPGA_FLAGS=${USER_FPGA_FLAGS}")
message(STATUS "Additional USER_FLAGS=${USER_FLAGS}")

include_directories(${USER_INCLUDE_PATHS})
message(STATUS "Additional USER_INCLUDE_PATHS=${USER_INCLUDE_PATHS}")

link_directories(${USER_LIB_PATHS})
message(STATUS "Additional USER_LIB_PATHS=${USER_LIB_PATHS}")

link_libraries(${USER_LIBS})
message(STATUS "Additional USER_LIBS=${USER_LIBS}")

if(WIN32)
    set(QACTYPES "-Qactypes")
    set(WIN_FLAG "/EHsc")
else()
    set(QACTYPES "-qactypes")
endif()

string(TOLOWER "${CMAKE_BUILD_TYPE}" LOWER_BUILD_TYPE)
if(LOWER_BUILD_TYPE MATCHES debug)
    if(WIN32)
        set(DEBUG_FLAGS /DEBUG /Od)
    else()
        set(DEBUG_FLAGS -g -O0)
    endif()
else()
    set(DEBUG_FLAGS "")
endif()

if(WIN32)
    set(EXT ".exe")
endif()

set(COMMON_COMPILE_FLAGS -fintelfpga -Wall ${WIN_FLAG} ${QACTYPES} ${USER_FLAGS})
set(COMMON_LINK_FLAGS -fintelfpga ${QACTYPES} ${USER_FLAGS})

set(EMULATOR_COMPILE_FLAGS -DFPGA_EMULATOR ${DEBUG_FLAGS})
set(EMULATOR_LINK_FLAGS)
set(REPORT_COMPILE_FLAGS -DFPGA_HARDWARE)
set(REPORT_LINK_FLAGS -Xshardware -Xstarget=${FPGA_DEVICE} ${USER_FPGA_FLAGS} -fsycl-link=early)
set(SIMULATOR_COMPILE_FLAGS -Xssimulation -DFPGA_SIMULATOR)
set(SIMULATOR_LINK_FLAGS -Xssimulation -Xsghdl -Xstarget=${FPGA_DEVICE} ${USER_FPGA_FLAGS})
set(FPGA_COMPILE_FLAGS -DFPGA_HARDWARE)
set(FPGA_LINK_FLAGS -Xshardware -Xstarget=${FPGA_DEVICE} ${USER_FPGA_FLAGS})

###############################################################################
### FPGA Emulator
###############################################################################
add_executable(${EMULATOR_TARGET} ${SOURCE_FILES})
target_compile_options(${EMULATOR_TARGET} PRIVATE ${COMMON_COMPILE_FLAGS})
target_compile_options(${EMULATOR_TARGET} PRIVATE ${EMULATOR_COMPILE_FLAGS})
target_link_libraries(${EMULATOR_TARGET} ${COMMON_LINK_FLAGS})
target_link_libraries(${EMULATOR_TARGET} ${EMULATOR_LINK_FLAGS})
set_target_properties(${EMULATOR_TARGET} PROPERTIES OUTPUT_NAME ${EMULATOR_OUTPUT_NAME})

###############################################################################
### FPGA Simulator
###############################################################################
add_executable(${SIMULATOR_TARGET} EXCLUDE_FROM_ALL ${SOURCE_FILES})
target_compile_options(${SIMULATOR_TARGET} PRIVATE ${COMMON_COMPILE_FLAGS})
target_compile_options(${SIMULATOR_TARGET} PRIVATE ${SIMULATOR_COMPILE_FLAGS})
target_link_libraries(${SIMULATOR_TARGET} ${COMMON_LINK_FLAGS})
target_link_libraries(${SIMULATOR_TARGET} ${SIMULATOR_LINK_FLAGS})
set_target_properties(${SIMULATOR_TARGET} PROPERTIES OUTPUT_NAME ${SIMULATOR_OUTPUT_NAME})

###############################################################################
### Generate Report
###############################################################################
add_executable(${REPORT_TARGET} EXCLUDE_FROM_ALL ${SOURCE_FILES})
target_compile_options(${REPORT_TARGET} PRIVATE ${COMMON_COMPILE_FLAGS})
target_compile_options(${REPORT_TARGET} PRIVATE ${REPORT_COMPILE_FLAGS})

set(MODIFIED_COMMON_LINK_FLAGS_REPORT ${COMMON_LINK_FLAGS})
list(REMOVE_ITEM MODIFIED_COMMON_LINK_FLAGS_REPORT ${QACTYPES})

target_link_libraries(${REPORT_TARGET} ${MODIFIED_COMMON_LINK_FLAGS_REPORT})
target_link_libraries(${REPORT_TARGET} ${REPORT_LINK_FLAGS})
set_target_properties(${REPORT_TARGET} PROPERTIES OUTPUT_NAME ${REPORT_OUTPUT_NAME})

###############################################################################
### FPGA Hardware
###############################################################################
add_executable(${FPGA_TARGET} EXCLUDE_FROM_ALL ${SOURCE_FILES})
target_compile_options(${FPGA_TARGET} PRIVATE ${COMMON_COMPILE_FLAGS})
target_compile_options(${FPGA_TARGET} PRIVATE ${FPGA_COMPILE_FLAGS})
target_link_libraries(${FPGA_TARGET} ${COMMON_LINK_FLAGS})
target_link_libraries(${FPGA_TARGET} ${FPGA_LINK_FLAGS})
set_target_properties(${FPGA_TARGET} PROPERTIES OUTPUT_NAME ${FPGA_OUTPUT_NAME})
