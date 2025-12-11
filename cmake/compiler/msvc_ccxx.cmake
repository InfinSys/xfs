
#=================================================================
#     MICROSOFT VISUAL C/C++ COMPILER CONFIGURATION (cl.exe)
#=================================================================

# TODO: Setup cl.exe compiler configuration (if applicable)

set(XFS_MSVC_VERSION_MIN 1940 CACHE STRING "Minimum MSVC compiler version")

# Confirm supported MSVC compiler version
if(MSVC_VERSION VERSION_LESS ${XFS_MSVC_VERSION_MIN})
    message(FATAL_ERROR "Incompatible version of MSVC C/C++ compiler for ${CMAKE_PROJECT_NAME}.")
endif()

# C++ compiler feature configuration target
add_library(XFS_msvc_cxx_features INTERFACE)
# C++ compiler diagnostics configuration target
add_library(XFS_msvc_cxx_warnings INTERFACE)
# General C++ compiler configuration target
add_library(XFS_msvc_cxx_options INTERFACE)

# C compiler feature configuration target
add_library(XFS_msvc_c_features INTERFACE)
# C compiler diagnostics configuration target
add_library(XFS_msvc_c_warnings INTERFACE)
# General C compiler configuration target
add_library(XFS_msvc_c_options INTERFACE)

# C/C++ preprocessor definitions target
add_library(XFS_msvc_common_defines INTERFACE)

# Set C++ standard version
target_compile_features(
    XFS_msvc_cxx_features

    INTERFACE
        cxx_std_20
)

# Set C++ standard conformance
target_compile_options(
    XFS_msvc_cxx_options

    INTERFACE
        # C++ ISO standard conformance flag
        "/permissive-"
)

# Set C++ compiler warning flags
target_compile_options(
    XFS_msvc_cxx_warnings

    INTERFACE
        # Compiler warning flags
        # "/W4"
)

# Conditionally add more aggressive warnings
if(XFS_STRICT_CXX_WARNINGS)
    target_compile_options(
        XFS_msvc_cxx_warnings

        INTERFACE
            "/WX"
    )
endif()

if(XFS_STRICT_C_WARNINGS)
    target_compile_options(
        XFS_msvc_c_warnings

        INTERFACE
            "/WX"
    )
endif()

# Conditionally set compiler optimization level
target_compile_options(
    XFS_msvc_cxx_options

    INTERFACE
        # Disable optimization on debug
        $<$<CONFIG:Debug>:
            "/Od"
        >

        # High optimization on release
        $<$<CONFIG:Release>:
            "/O2"
        >
)

target_compile_options(
    XFS_msvc_cxx_options

    INTERFACE
        # Character set flags
        "/source-charset:utf-8"
        "/execution-charset:utf-8"
)

# Define C/C++ preprocessor definitions
target_compile_definitions(
    XFS_msvc_common_defines

    INTERFACE
        # Unconditional preprocessor definitions
        XFS
        XFS_WIN32

        # Preprocessor definitions on debug build
        $<$<CONFIG:Debug>:
            _XFS_DEBUG
        >

        # Preprocessor definitions on release build
        $<$<CONFIG:Release>:
            XFS_RELEASE
        >
)

# Complete MSVC C++ compiler package
add_library(XFS_msvc_cxx_bundle INTERFACE)
# Complete MSVC C compiler package
add_library(XFS_msvc_c_bundle INTERFACE)

target_link_libraries(
    XFS_msvc_cxx_bundle
    
    INTERFACE
        XFS_msvc_cxx_features
        XFS_msvc_cxx_warnings
        XFS_msvc_cxx_options
        XFS_msvc_common_defines
)

target_link_libraries(
    XFS_msvc_c_bundle
    
    INTERFACE
        XFS_msvc_c_features
        XFS_msvc_c_warnings
        XFS_msvc_c_options
        XFS_msvc_common_defines
)
