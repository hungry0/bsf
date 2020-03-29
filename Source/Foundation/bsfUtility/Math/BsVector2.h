//************************************ bs::framework - Copyright 2018 Marko Pintera **************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
//#include "Math/BsMath.h"

namespace bs
{
    class BS_UTILITY_EXPORT Vector2
    {
    public:
        float x, y;
        
    public:
        Vector2() = default;

        constexpr Vector2(BS_ZERO) : x(0.0f), y(0.0f)
        {}

        constexpr Vector2(float x, float y) : x(x), y(y)
        {}

        void swap(Vector2& other)
        {
            std::swap(x, other.x);
            std::swap(y, other.y);
        }

        float operator[] (UINT32 i) const
        {

        }

        float& operator[](UINT32 i)
        {

        }

        float* ptr()
        {

        }

        const float* ptr() const
        {

        }

        Vector2& operator=(float rhs)
        {

        }

        bool operator==(const Vector2& rhs) const
        {
            return false;
        }

        bool operator!=(const Vector2& rhs) const
        {
            return false;
        }

        Vector2 operator+(const Vector2& rhs) const
        {
            
        }

        Vector2 operator-(const Vector2& rhs) const
        {

        }

        Vector2 operator*(const float rhs) const
        {

        }

        Vector2 operator*(const Vector2& rhs) const
        {

        }

        Vector2 operator/(const float rhs) const
        {

        }

        Vector2 operator/(const Vector2& rhs) const
        {

        }

        const Vector2& operator+() const
        {

        }

        Vector2 operator-() const
        {

        }

        friend Vector2 operator*(float lhs, const Vector2& rhs)
        {

        }

        friend Vector2 operator/(float lhs, const Vector2& rhs)
        {

        }

        friend Vector2 operator+(Vector2& lhs, float rhs)
        {

        }

        friend Vector2 operator-(const Vector2& lhs, float rhs)
        {

        }

        friend Vector2 operator-(const float lhs, const Vector2& rhs)
        {

        }

        Vector2& operator+=(const Vector2& rhs)
        {

        }

        Vector2& operator+=(float rhs)
        {

        }

        Vector2& operator-=(const Vector2& rhs)
        {

        }

        Vector2& operator-=(float rhs)
        {

        }

        Vector2& operator*=(float rhs)
        {

        }

        Vector2& operator*=(const Vector2& rhs)
        {

        }

        Vector2& operator/=(float rhs)
        {

        }

        Vector2& operator/=(const Vector2& rhs)
        {

        }

        float length() const
        {

        }

        float distance(const Vector2& rhs) const
        {

        }

        float sqrdDistance(const Vector2& rhs) const
        {

        }

        float dot(const Vector2& vec) const
        {

        }

        float normalize()
        {

        }

        // 垂线
        Vector2 perpendicular() const
        {

        }

        float cross(const Vector2& other) const
        {

        }

        void floor(const Vector2& cmp)
        {

        }

        void ceil(const Vector2& cmp)
        {

        }

        bool isZeroLength() const
        {

        }

        Vector2 reflect(const Vector2& normal) const
        {

        }

        /** Performs Gram-Schmidt orthonormalization. */
        static void orthonormalize(Vector2& u, Vector2& v)
        {

        }

        static Vector2 normalize(const Vector2& val)
        {

        }

        // 非数值
        bool isNaN() const
        {

        }

        static Vector2 min(const Vector2& a, const Vector2& b)
        {

        }

        static Vector2 max(const Vector2& a, const Vector2& b)
        {

        }

        static const Vector2 ZERO;
        static const Vector2 ONE;
        static const Vector2 UNIT_X;
        static const Vector2 UNIT_Y;
    };
}
