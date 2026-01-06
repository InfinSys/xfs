
#======================================
#     /tests/cli Directory Script
#======================================

add_executable(dev_cli_debug "dev_exe.cpp")

if(${XFS_CXX_GCC})
    target_link_libraries(
        dev_cli_debug
    
        PRIVATE
        XFS_gcc_cxx_bundle
        XFS_gcc_c_defines
    )
elseif(${XFS_CXX_CLANG})
    target_link_libraries(
        xfs
    
        PRIVATE
        XFS_clang_cxx_bundle
        XFS_clang_c_defines
    )
elseif(${XFS_CXX_MSVC})
    target_link_libraries(
        dev_cli_debug
    
        PRIVATE
        XFS_msvc_cxx_bundle
    )
endif()

target_link_libraries(
    dev_cli_debug

    PRIVATE
    xfs
)

install(
    TARGETS dev_cli_debug
    COMPONENT DevCLI
    EXPORT dev_cli_debug-targets

    RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
)
