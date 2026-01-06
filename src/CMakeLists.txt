
#================================
#     /src Directory Script
#================================

# Main XFS library target
add_library(xfs STATIC)

target_include_directories(
    xfs

    PUBLIC
    "${XFS_SOURCE_DIR}/include"
)

# NOTE: Temporary library source
target_sources(
    xfs

    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/temporary.cpp"
)
# NOTE: Library source directories here

# XFS Sources
#add_subdirectory("path")

if(${XFS_CXX_GCC})
    target_link_libraries(
        xfs
    
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
        xfs
    
        PRIVATE
        XFS_msvc_cxx_bundle
    )
endif()

install(
    TARGETS xfs
    COMPONENT XFSLib
    EXPORT xfs-targets

    RUNTIME
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
