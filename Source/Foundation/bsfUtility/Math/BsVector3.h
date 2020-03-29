#pragma once

#include <cmath>

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Vector3
    {
    public:
        float x, y, z;

    public:
        Vector3() = default;

        constexpr Vector3(BS_ZERO):x(0.0f),y(0.0f),z(0.0f)
        {}

        constexpr Vector3(float x, float y, float z) : x(x), y(y), z(z)
        {}

        //explicit Vector3(const Vector4& vec);

        void swap(Vector3& other)
        {

        }

        float operator[](UINT32 i) const
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

        Vector3& operator=(float rhs)
        {

        }

        bool operator==(const Vector3& rhs) const
        {

        }

        bool operator!=(const Vector3& rhs) const
        {

        }

        Vector3 operator+(const Vector3& rhs) const
        {

        }

        Vector3 operator-(const Vector3& rhs) const
        {

        }

        Vector3 operator*(float rhs) const
        {

        }

        Vector3 operator*(const Vector3& rhs) const
        {

        }

        Vector3 operator/(float val) const
        {

        }

        Vector3 operator/(const Vector3& rhs) const
        {

        }

        const Vector3& operator+() const
        {

        }

        Vector3 operator-() const
        {

        }

        friend Vector3 operator*(float lhs, const Vector3& rhs)
        {

        }

        friend Vector3 operator/(float lhs, const Vector3& rhs)
        {

        }

        friend Vector3 operator+(const Vector3& lhs, float rhs)
        {

        }

        friend Vector3 operator+(float lhs, const Vector3& rhs)
        {

        }

        friend Vector3 operator-(const Vector3& lhs, float rhs)
        {

        }

        friend Vector3 operator-(float lhs, const Vector3& rhs)
        {

        }

        Vector3& operator+=(const Vector3& rhs)
        {

        }

        Vector3& operator+=(float rhs)
        {

        }

        Vector3 operator-=(float rhs)
        {

        }

        Vector3 operator-=(const Vector3& rhs)
        {

        }

        Vector3& operator*=(float rhs)
        {

        }

        Vector3& operator*=(const Vector3& rhs)
        {

        }

        Vector3& operator/=(float rhs)
        {

        }

        Vector3& operator/=(const Vector3& rhs)
        {

        }

        float length() const
        {

        }

        float squaredLength() const
        {

        }

        float distance(const Vector3& rhs) const
        {

        }

        float squardDistance(const Vector3& rhs) const
        {

        }

        float dot(const Vector3& rhs) const
        {

        }

        float normalize()
        {

        }

        Vector3 cross(const Vector3& other) const
        {

        }

        void min(const Vector3& cmp)
        {

        }

        void max(const Vector3& cmp)
        {

        }

        // 垂线
        Vector3 perpendicular() const
        {

        }

        // inline Radian angleBetween(const Vector3& dest) const;

        bool isZeroLength() const
        {

        }

        Vector3 reflect(const Vector3& normal) const
        {

        }

        // 计算正交
        void orthogonalComplement(Vector3& a, Vector3& b)
        {

        }

        static void orthonormalize(Vector3& vec0, Vector3& vec1, Vector3& vec2)
        {

        }

        static float dot(const Vector3& a, const Vector3& b)
        {

        }

        static Vector3 normalize(const Vector3& val);

        static Vector3 cross(const Vector3& a, const Vector3& b);

        static Vector3 lerp(float t, const Vector3& a, const Vector3& b)
        {

        }

        inline bool isNaN() const;

        static Vector3 min(const Vector3& a, const Vector3& b)
        {

        }

        static Vector3 max(const Vector3& a, const Vector3& b)
        {

        }

        static const Vector3 ZERO;
        static const Vector3 ONE;
        static const Vector3 INF;
        static const Vector3 UNIT_X;
        static const Vector3 UNIT_Y;
        static const Vector3 UNIT_Z;
    };
}

namespace std
{
    template<>
    class numeric_limits<bs::Vector3>
    {
    public:
        constexpr static bs::Vector3 infinity()
        {
            return bs::Vector3(
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity()
            );
        }
    };
}
