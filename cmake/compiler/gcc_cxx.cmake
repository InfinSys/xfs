
#===============================================
#     GCC C++ COMPILER CONFIGURATION (g++)
#===============================================

# TODO: Setup g++ compiler configuration (if applicable)

set(XFS_GCC_CXX_VERSION_MIN 14 CACHE STRING "Minimum g++ compiler version")

# Confirm supported g++ compiler version
if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${XFS_GCC_CXX_VERSION_MIN})
    message(FATAL_ERROR "Incompatible version of GCC C++ compiler for ${CMAKE_PROJECT_NAME}.")
endif()

# Compiler feature configuration target
add_library(XFS_gcc_cxx_features INTERFACE)
# Compiler diagnostics configuration target
add_library(XFS_gcc_cxx_warnings INTERFACE)
# General compiler configuration target
add_library(XFS_gcc_cxx_options INTERFACE)
# Preprocessor definitions target
add_library(XFS_gcc_cxx_defines INTERFACE)

# Set C++ standard version
target_compile_features(
    XFS_gcc_cxx_features

    INTERFACE
        cxx_std_20
)

# Set compiler warning flags
target_compile_options(
    XFS_gcc_cxx_warnings

    INTERFACE
        # Compiler warning flags
        "-Wall"
        "-Wextra"
        "-Wpedantic"
)

# Conditionally add more aggressive warnings
if(XFS_STRICT_CXX_WARNINGS)
    target_compile_options(
        XFS_gcc_cxx_warnings

        INTERFACE
            "-Werror"
            "-Wshadow"
            "-Wdouble-promotion"
            "-Wformat=2"
    )
endif()

# Conditionally set compiler optimization level
target_compile_options(
    XFS_gcc_cxx_options

    INTERFACE
        # Disable optimization on debug
        $<$<CONFIG:Debug>:
            "-O0"
        >

        # High optimization on release
        $<$<CONFIG:Release>:
            "-O2"
        >
)

# Define preprocessor definitions
target_compile_definitions(
    XFS_gcc_cxx_defines

    INTERFACE
        # Unconditional preprocessor definitions
        XFS

        # Preprocessor definitions on debug
        $<$<CONFIG:Debug>:
            _XFS_DEBUG
        >

        # Preprocessor definitions on release
        $<$<CONFIG:Release>:
            XFS_RELEASE
        >
)

# Complete GCC C++ compiler package
add_library(XFS_gcc_cxx_bundle INTERFACE)

target_link_libraries(
    XFS_gcc_cxx_bundle
    
    INTERFACE
        XFS_gcc_cxx_features
        XFS_gcc_cxx_warnings
        XFS_gcc_cxx_options
        XFS_gcc_cxx_defines
)
