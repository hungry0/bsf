#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    struct BS_UTILITY_EXPORT Vector4I
    {
		INT32 x = 0;
		INT32 y = 0;
		INT32 z = 0;
		INT32 w = 0;

		constexpr Vector4I() = default;

		constexpr Vector4I(INT32 x, INT32 y, INT32 z, INT32 w)
			:x(x), y(y), z(z), w(w) {}

		INT32 operator[](size_t i) const;

		INT32& operator[](size_t i);

		bool operator==(const Vector4I& rhs) const;

		bool operator!=(const Vector4I& rhs) const;
    };
}
