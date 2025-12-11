
#==================================
#     PROJECT METADATA MODULE
#==================================

include("${XFS_CMAKE_MODULES_DIR}/utility/metadata_tools.cmake")

create_temporary_cache_list()

set_metadata(PUBLISHER "Infinity Systems, LLC." DESCRIPTION "Product publisher")
set_metadata(PRODUCT_TYPE "Library" DESCRIPTION "Software type")
set_metadata(INTERFACE_TYPE "API" DESCRIPTION "Product interface")
set_metadata(UUID "ISJTB-CXX-XL20240612-000002" DESCRIPTION "Product unique identifier")
set_metadata(LICENSE_TYPE "<MIT or GPLv3>" DESCRIPTION "Product license type")
set_metadata(FULL_NAME "Cross-Platform Filesystem" DESCRIPTION "Product name")
set_metadata(SHORT_NAME "XFS" DESCRIPTION "Product short name")
set_metadata(MAIN_BINARY_NAME "xfs" DESCRIPTION "Main binary")
set_metadata(META_NAMESPACE "XFS" DESCRIPTION "Project metadata namespace")

# Temporarily cached variables for code generation
create_template_reference(SFTW_PUBLISHER    PUBLISHER)
create_template_reference(SFTW_TYPE         PRODUCT_TYPE)
create_template_reference(SFTW_INTERFACE    INTERFACE_TYPE)
create_template_reference(SFTW_UUID         UUID)
create_template_reference(SFTW_LICENSE_TYPE LICENSE_TYPE)
create_template_reference(SFTW_NAME         FULL_NAME)
create_template_reference(SFTW_SHORT_NAME   SHORT_NAME)
create_template_reference(SFTW_MAIN_BINARY  MAIN_BINARY_NAME)
create_template_reference(SFTW_META_PREFIX  META_NAMESPACE)

configure_template(
    "${XFS_SOURCE_DIR}/docs/templ/README.md.in"
    "${XFS_SOURCE_DIR}/README.md"
)

configure_template(
    "${XFS_SOURCE_DIR}/docs/templ/Doxyfile.in"
    "${XFS_SOURCE_DIR}/docs/Doxyfile"
)

configure_template(
    "${XFS_SOURCE_DIR}/docs/templ/index.html.in"
    "${XFS_SOURCE_DIR}/docs/ref/index.html"
)

configure_template(
    "${XFS_SOURCE_DIR}/docs/templ/inaug.md.in"
    "${XFS_SOURCE_DIR}/docs/prj/inaug.md"
)

configure_template(
    "${XFS_SOURCE_DIR}/lib/xfs_metadata/templ/info.h.in"
    "${XFS_SOURCE_DIR}/lib/xfs_metadata/info.h"
)

configure_template(
    "${XFS_SOURCE_DIR}/lib/xfs_metadata/templ/version.h.in"
    "${XFS_SOURCE_DIR}/lib/xfs_metadata/version.h"
)

clear_temporary_cache()
