#pragma once

#include "Math/BsVector3.h"
#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Vector4
    {
    public:
        float x, y, z, w;

    public:
        Vector4() = default;

        constexpr Vector4(BS_ZERO)
            :x(0.0f), y(0.0f), z(0.0f), w(0.0f)
        {}

        constexpr explicit Vector4(const Vector3& vec, float w = 0.0f)
            :x(vec.x), y(vec.y), z(vec.z), w(w)
        {}

        void swap(Vector4& other)
        {

        }

        float operator[] (UINT32 i) const
        {

        }

        float& operator[] (UINT32 i)
        {

        }

        float* ptr()
        {
            return &x;
        }

        const float* ptr() const 
        {

        }

        Vector4& operator=(float rhs)
        {

        }

        bool operator==(const Vector4& rhs) const
        {

        }

        bool operator!=(const Vector4& rhs) const
        {

        }

        Vector4& operator=(const Vector3& rhs)
        {

        }

        Vector4 operator+(const Vector4& rhs) const
        {

        }

        Vector4 operator-(const Vector4& rhs) const
        {

        }

        Vector4 operator*(float rhs) const
        {

        }

        Vector4 operator*(const Vector4& rhs) const
        {

        }

        Vector4 operator/(float rhs) const
        {

        }

        const Vector4& operator+() const
        {

        }

        Vector4 operator-() const
        {

        }

        friend Vector4 operator*(float lhs, const Vector4& rhs)
        {

        }

        friend Vector4 operator/(float lhs, const Vector4& rhs)
        {

        }

        friend Vector4 operator+(const Vector4& lhs, float rhs)
        {

        }

        friend Vector4 operator+(float lhs, const Vector4& rhs)
        {

        }

        friend Vector4 operator-(const Vector4& lhs, float rhs)
        {

        }

        friend Vector4 operator-(float lhs, const Vector4& rhs)
        {

        }

        Vector4& operator+=(const Vector4& rhs)
        {

        }

        Vector4& operator-=(const Vector4& rhs)
        {

        }

        Vector4& operator*=(float rhs)
        {

        }

        Vector4& operator+=(float rhs)
        {

        }

        Vector4& operator-=(float rhs)
        {

        }

        Vector4& operator*=(Vector4& rhs)
        {

        }

        Vector4& operator/=(float rhs)
        {

        }

        Vector4& operator/=(const Vector4& rhs)
        {

        }

        float dot(const Vector4& vec) const
        {

        }

        inline bool isNaN() const;

        static const Vector4 ZERO;
    };
}

