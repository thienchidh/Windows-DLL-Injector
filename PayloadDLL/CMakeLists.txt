set(PROJECT_NAME PayloadDLL)

################################################################################
# Source groups
################################################################################
set(Header_Files
        "src/APIHook.h"
        "src/functions.h"
        "src/Payload.h"
        )
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
        "src/APIHook.cpp"
        "src/functions.cpp"
        "src/Payload.cpp"
        )
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
        ${Header_Files}
        ${Source_Files}
        )

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE PayloadDLL)

################################################################################
# Output directory
################################################################################
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/Build/PayloadDLLBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Build/PayloadDLLBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/Build/PayloadDLLBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Build/PayloadDLLBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            )
endif ()
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
            )
endif ()
################################################################################
# Compile definitions
################################################################################
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
            "_MBCS"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
            "_MBCS"
            )
endif ()

################################################################################
# Compile and link options
################################################################################
if (MSVC)
    if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Debug>:
                /Od
                >
                $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
                >
                /permissive-;
                /sdl;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                ${DEFAULT_CXX_EXCEPTION_HANDLING}
                )
    elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Debug>:
                /Od
                >
                $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
                >
                /permissive-;
                /sdl;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                ${DEFAULT_CXX_EXCEPTION_HANDLING}
                )
    endif ()
    if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
                >
                /DEBUG:FULL
                )
    elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
                $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
                >
                /DEBUG:FULL
                )
    endif ()
endif ()

################################################################################
# Dependencies
################################################################################
use_package(${PROJECT_NAME} Detours 4.0.1)
