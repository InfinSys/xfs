
#==========================================
#     Global C COMPILER CONFIGURATION
#==========================================

# Preprocessor definitions target
add_library(XFS_global_c_defines INTERFACE)

# Define preprocessor definitions
target_compile_definitions(
    XFS_global_c_defines

    INTERFACE
        # Unconditional preprocessor definitions
        XFS_LIB

        # Preprocessor definitions on debug
        $<$<CONFIG:Debug>:
            _XFS_DEBUG
        >

        # Preprocessor definitions on release
        $<$<CONFIG:Release>:
            XFS_RELEASE
        >
)
