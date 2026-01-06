
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file policy.hpp
 *
 * @brief
 * Set of XFS filesystem path policy concepts.
 */

#ifndef XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPTS_H_
#define XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPTS_H_

#include<concepts>

/*!
 * @namespace xfs::path::concepts
 * 
 * @brief
 * Library filesystem path concepts.
 */
namespace xfs::path::concepts {

template <typename Policy_Impl>
concept has_path_encoding_types = requires {
    typename Policy_Impl::PathCharType;
    typename Policy_Impl::PathStringType;
};

template <typename Policy_Impl>
concept has_characteristic_attributes = requires {
    { Policy_Impl::DELIMITER } -> std::convertible_to<typename Policy_Impl::PathCharType>;
};

}

#endif // XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPTS_H_
