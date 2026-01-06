
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file path_policy.hpp
 *
 * @brief
 * Provides declaration for base platform-agnostic
 * path policy interface.
 */

#ifndef XFS_LIB_SYSTEM_FILE_PATH_POLICY_INTERFACE_H_
#define XFS_LIB_SYSTEM_FILE_PATH_POLICY_INTERFACE_H_

#include<string>

/*!
 * @namespace xfs::path
 *
 * @brief
 * XFS library path facilities.
 */
namespace xfs::path
{

/*!
 * @brief
 * Platform-agnostic system path policy interface.
 * 
 * @details
 * This class is used as a base interface for platform
 * specific path policies that detail the specifics of
 * how path strings are handled in the native environment.
 * A `SystemPathPolicy` and its derivatives are not
 * concerned with or knowledgeable of the local filesystem,
 * their function is purely lexical. This base class
 * presents some of the common API elements expected among
 * path policies while derivatives of this type will
 * implement the logic necessary to process paths on their
 * respective platform. The implemented API will conform to
 * the set of requirements created by the associated
 * `FileSystemPath` structure.
 */
template<typename CharEncode_T, CharEncode_T Delimiter_Char>
struct SystemPathPolicy {
    /*! @brief System path character type. */
    using PathCharType = CharEncode_T;
    /*! @brief System path string type. */
    using PathStringType = std::basic_string<CharEncode_T>;

    /*! @brief System path delimiter character. */
    static constexpr PathCharType DELIMITER = Delimiter_Char;
};

}

#endif // XFS_LIB_SYSTEM_FILE_PATH_POLICY_INTERFACE_H_
