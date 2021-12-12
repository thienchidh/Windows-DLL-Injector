cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 10.0.17763.0 CACHE STRING "" FORCE)

project(WindowsDLLInjector CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if (NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif ()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

set(platform ${CMAKE_VS_PLATFORM_NAME})
if (platform STREQUAL "Win32")
    set(platform "x86")
endif ()

if (NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
        OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"
        OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif ()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE
        )

################################################################################
# Global compiler options
################################################################################
if (MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif ()

################################################################################
# Global linker options
################################################################################
if (MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif ()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message("${TARGET} ${CMAKE_SOURCE_DIR}/packages/${PACKAGE}.${VERSION}/lib/native/libs/${platform}/*.lib")
    target_link_libraries(${TARGET} "${CMAKE_SOURCE_DIR}/packages/${PACKAGE}.${VERSION}/lib/native/libs/${platform}/*.lib")

    include_directories("${CMAKE_SOURCE_DIR}/packages/${PACKAGE}.${VERSION}/lib/native/include")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(Injector)
add_subdirectory(PayloadDLL)
add_subdirectory(TargetProgram)

