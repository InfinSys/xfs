
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file policy.hpp
 *
 * @brief
 * Provides declaration for Windows platform path
 * policy implementation.
 */

#ifndef XFSWIN32_LIB_WINDOWS_PATH_POLICY_H_
#define XFSWIN32_LIB_WINDOWS_PATH_POLICY_H_

#include"xfs/path/interface/path_policy.hpp"
#include"xfs/platform/win32/path/path_defs.hpp"

namespace xfs::win32::path
{

// Start (this supports ANSI and UTF-16?)

/*!
 * @brief
 * Microsoft Windows path policy.
 */
template <typename CharEncode_T>
class WindowsPathPolicy : public xfs::path::SystemPathPolicy<CharEncode_T, DELIMITER_CHAR> {
public:
	//static PathStringType toNormalPath(const PathStringType& path) noexcept;
};

}

#endif // XFSWIN32_LIB_WINDOWS_PATH_POLICY_H_
