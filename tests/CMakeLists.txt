
#==================================
#     /tests Directory Script
#==================================

if(XFS_CLI_DEBUG)
    add_subdirectory(cli)
endif()

if(XFS_UNIT_TEST)
    add_subdirectory(unit)
endif()

if(XFS_BENCHMARK)
    add_subdirectory(benchmark)
endif()
