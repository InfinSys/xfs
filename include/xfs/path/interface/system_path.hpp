
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file system_path.hpp
 *
 * @brief
 * Provides declaration for platform-agnostic path
 * interface.
 */

#ifndef XFS_LIB_FILESYSTEM_PATH_INTERFACE_H_
#define XFS_LIB_FILESYSTEM_PATH_INTERFACE_H_

#include<cstdint>
#include"xfs/path/concepts/path_policy.hpp"

namespace xfs::path {

/*!
 * @brief
 * Platform-agnostic filesystem path interface.
 * 
 * @details
 * N/A
 */
template <concepts::compatible_path_policy_api Path_Policy>
class FileSystemPath {
protected:
    /*! @brief Platform filesystem path policy. */
    using PathPolicy = Path_Policy;

    FileSystemPath() noexcept = default;
    ~FileSystemPath() noexcept = default;

public:
    /*! @brief Platform path encoding character type. */
    using CharType = typename Path_Policy::PathCharType;
    /*! @brief Platform path string type. */
    using StringType = typename Path_Policy::PathStringType;

    // TODO: `Const_Iterator` and `Const_R_Iterator` types

    /*!
     * @brief
     * Enumeration of system path character encodings.
     */
    enum Encoding : uint8_t {
        NATIVE,    ///< Platform native path encoding

        UTF_8,     ///< UTF-8 path encoding
        UTF_16     ///< UTF-16 path encoding
    };

    /*! @brief Path separation character. */
    static constexpr CharType Delimiter = Path_Policy::DELIMITER;
};

}

#endif // XFS_LIB_FILESYSTEM_PATH_INTERFACE_H_
