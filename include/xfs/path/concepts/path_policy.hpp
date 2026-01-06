
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3

// [ISJTB-CXX-XL20240612-000002]

/*!
 * @file path_policy.hpp
 *
 * @brief
 * XFS filesystem path policy concept.
 */

#ifndef XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPT_H_
#define XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPT_H_

#include<concepts>
#include"xfs/path/concepts/policy.hpp"

namespace xfs::path::concepts {

/*!
 * @brief
 * Concept of a type that meets the requirements to be
 * considered a compatible filesystem path policy type
 * with the XFS library.
 */
template <typename Policy_Impl>
concept compatible_path_policy_api = requires {
    requires has_path_encoding_types<Policy_Impl>;
    requires has_characteristic_attributes<Policy_Impl>;
};

}

#endif // XFS_LIB_SYSTEM_FILE_PATH_POLICY_CONCEPT_H_
