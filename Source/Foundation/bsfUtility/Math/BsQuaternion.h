#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Quaternion
    {
    private:
        struct EulerAngleOrderData
        {
            int a, b, c;
        };

    public:
        Quaternion() = default;
        constexpr Quaternion(const Quaternion&) = default;
        constexpr Quaternion& operator=(const Quaternion&) = default;

        constexpr Quaternion(BS_ZERO zero) :
            x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

        constexpr Quaternion(BS_IDENTITY) :
            x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

        constexpr Quaternion(float w, float x, float y, float z) :
            x(x), y(y), z(z), w(w) {}

        explicit Quaternion(const Matrix3& rot)
        {
            fromRotationMatrix(rot);
        }

        explicit Quaternion(const Vector3& axis, const Radian& angle)
        {
            fromAxisAngle(axis, angle);
        }

        explicit Quaternion(const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis)
        {
            fromAxes(xaxis, yaxis, zaxis);
        }

        explicit Quaternion(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle)
        {
            fromEulerAngles(xAngle, yAngle, zAngle);
        }

        explicit Quaternion(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle, EulerAngleOrder order)
        {
            fromEulerAngles(xAngle, yAngle, zAngle, order);
        }

        void swap(Quaternion& other);

        float& operator[](const size_t i);

        void fromRotationMatrix(const Matrix3& mat);

        void fromAxisAngle(const Vector3& axis, const Radian& angle);

        void fromAxes(const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis);

        void fromEulerAngles(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle);

        void fromEulerAngles(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle, EulerAngleOrder order);

        void toRotationMatrix(Matrix3& mat) const;

        void toAxisAngle(Vector3& axis, Radian& angle) const;

        void toAxes(Vector3& xAxis, Vector3& yAxis, Vector3& zAxis) const;

        bool toEulerAngles(Radian& xAngle, Radian& yAngle, Radian& zAngle) const;

        Vector3 xAxis() const;

        Vector3 yAxis() const;

        Vector3 zAxis() const;

        Quaternion operator+(const Quaternion& rhs) const;

        Quaternion operator-(const Quaternion& rhs) const;

        Quaternion operator*(const Quaternion& rhs) const;

        Quaternion operator*(float rhs) const;

        Quaternion operator/(float rhs) const;

        Quaternion operator-() const;

        bool operator==(const Quaternion& rhs) const;

        bool operator!=(const Quaternion& rhs) const;

        Quaternion& operator+=(const Quaternion& rhs);

        Quaternion& operator-=(const Quaternion& rhs);

        Quaternion& operator*=(const Quaternion& rhs);

        friend Quaternion operator*(float lhs, const Quaternion& rhs);

        float dot(const Quaternion& rhs) const;

        float normalize();

        Quaternion inverse() const;

        Vector3 rotate(const Vector3& vec) const;

        void lookRotation(const Vector3& forwardDir);

        void lookRotation(const Vector3& forwardDir, const Vector3& upDir);

        bool isNaN() const;

        static float dot(const Quaternion& lhs, const Quaternion& rhs);

        static Quaternion normalize(const Quaternion& q);

        static Quaternion slerp(float t, const Quaternion& p, const Quaternion& q, bool shortestPath = true);

        static Quaternion lerp(float t, const Quaternion& a, const Quaternion& b);

        static Quaternion min(const Quaternion& a, const Quaternion& b);

        static Quaternion max(const Quaternion& a, const Quaternion& b);

        static constexpr const float EPSILON = 1e-03f;

        static const Quaternion ZERO;
        static const Quaternion IDENTITY;

    private:
        float x, y, z, w;
    };
}

// TODO
namespace std
{
    template<>
    class numeric_limits<bs::Quaternion>
    {
    public:
        constexpr static bs::Quaternion infinity()
        {
            return bs::Quaternion(
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity(),
                std::numeric_limits<float>::infinity()
            );
        }
    };
}
