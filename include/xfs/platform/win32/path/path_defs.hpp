
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file path_defs.hpp
 *
 * @brief
 * N/A
 */

#ifndef XFSWIN32_LIB_WINDOWS_PATH_DEFINITIONS_H_
#define XFSWIN32_LIB_WINDOWS_PATH_DEFINITIONS_H_

/*!
 * @namespace xfs::win32::path
 * 
 * @brief
 * Microsoft Windows path facilities.
 */
namespace xfs::win32::path
{

/*!
 * @brief
 * Native path character encoding type for Windows.
 */
using NativeCharEncoding = wchar_t;

/*!
 * @brief
 * Windows path separation character.
 */
inline constexpr char DELIMITER_CHAR = '\\';

}

#endif // XFSWIN32_LIB_WINDOWS_PATH_DEFINITIONS_H_
