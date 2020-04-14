#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    struct BS_UTILITY_EXPORT Vector2I
    {
		INT32 x = 0;
		INT32 y = 0;

		constexpr Vector2I() = default;

		constexpr Vector2I(INT32 _x, INT32 _y)
			:x(_x), y(_y) {}

		constexpr explicit Vector2I(int val)
			:x(val), y(val)
		{}

		void swap(Vector2I& other);

		UINT32 manhattanDist(const Vector2I& other) const;

		INT32 operator[](size_t i) const;

		INT32& operator[](size_t i);

		Vector2I& operator=(int val);

		bool operator==(const Vector2I& rhs) const;

		bool operator!=(const Vector2I& rhs) const;

		Vector2I operator+(const Vector2I& rhs) const;

		Vector2I operator-(const Vector2I& rhs) const;

		Vector2I operator*(int val) const;

		Vector2 operator*(float val) const;

		Vector2I operator*(const Vector2I& rhs) const;

		Vector2I operator/(int val) const;

		Vector2 operator/(float val) const;

		Vector2I operator/(const Vector2I& rhs) const;

		const Vector2I& operator+() const;

		Vector2I operator-() const;

		friend Vector2I operator*(int lhs, const Vector2I& rhs);

		friend Vector2I operator/(int lhs, const Vector2I& rhs);

		Vector2I& operator+= (const Vector2I& rhs);

		Vector2I& operator-= (const Vector2I& rhs);

		Vector2I& operator*= (INT32 val);

		Vector2I& operator*= (const Vector2I& rhs);

		Vector2I& operator/= (INT32 val);

		Vector2I& operator/= (const Vector2I& rhs);

		INT32 squaredLength() const;

		INT32 dot(const Vector2I& vec) const;

		static const Vector2I ZERO;
    };
}