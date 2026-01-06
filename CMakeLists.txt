
#=======================================================
#
#     Infinity Systems, LLC. 2025 and Jamon Bailey
#
#     Cross-Platform Filesystem (XFS)
#     - Library Build Generation
#
#     (Root CMakeLists.txt Script)
#
#=======================================================

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

    project(
        xfs_core
        VERSION 0.0.0.0
        LANGUAGES
            C CXX
    )

    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    include(cmake/utility/root_setup.cmake)
    setup_testing_dependencies()
    setup_clang_format_target()
    setup_clang_tidy_target()

    include(cmake/compiler/config_dispatch.cmake)
endif()

set(XFS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(XFS_CMAKE_MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)

# Source Subdirs
add_subdirectory(lib)
add_subdirectory(src)

if (${CMAKE_PROJECT_NAME}_IS_TOP_LEVEL)
    # Testing sources
    add_subdirectory(tests)
endif()
