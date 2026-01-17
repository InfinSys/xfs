
#===============================================
#     /src/platform/win32 Directory Script
#===============================================

# Microsoft Windows XFS library target
add_library(xfswin32 STATIC)

add_subdirectory("path")

target_link_libraries(
	xfs

	PUBLIC
	xfswin32
)
