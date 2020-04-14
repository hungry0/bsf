#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    struct BS_UTILITY_EXPORT Vector3I
    {
		INT32 x = 0;
		INT32 y = 0;
		INT32 z = 0;

		constexpr Vector3I() = default;

		constexpr Vector3I(INT32 x, INT32 y, INT32 z)
			:x(x), y(y), z(z) {}

		INT32 operator[](size_t i) const;

		INT32& operator[](size_t);

		bool operator==(const Vector3I& rhs) const;

		bool operator!=(const Vector3I& rhs) const;


    };
}
