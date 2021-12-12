set(PROJECT_NAME TargetProgram)

################################################################################
# Source groups
################################################################################
set(Source_Files
        "src/Target.cpp"
        )
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
        ${Source_Files}
        )

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE TargetProgram)

################################################################################
# Output directory
################################################################################
if ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/Build/TargetProgramBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Build/TargetProgramBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            )
elseif ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
            OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/Build/TargetProgramBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
            OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Build/TargetProgramBuild/bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}/"
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

