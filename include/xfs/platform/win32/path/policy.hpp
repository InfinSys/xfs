
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
 * Windows platform path policy.
 */
template <typename CharEncode_T>
class WindowsPathPolicy final
	: public xfs::path::SystemPathPolicy<CharEncode_T, (CharEncode_T)DELIMITER_CHAR> {
	/*! @brief Windows path policy base class. */
	using Base = xfs::path::SystemPathPolicy<CharEncode_T, (CharEncode_T)DELIMITER_CHAR>;

public:
	WindowsPathPolicy() noexcept = delete;
	~WindowsPathPolicy() noexcept = delete;

	static Base::PathStringType makeNormalPath(const Base::PathStringType& path) noexcept;

	// static PathCharType makeNormalPath(const PathCharType& path) noexcept
	// {
	// 	return PathCharType{};
	// }
};

}

#endif // XFSWIN32_LIB_WINDOWS_PATH_POLICY_H_
