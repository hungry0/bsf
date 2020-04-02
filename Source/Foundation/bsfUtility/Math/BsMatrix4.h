#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsMatrix3.h"
#include "Math/BsVector4.h"
#include "Math/BsPlane.h"

namespace bs
{

    class BS_UTILITY_EXPORT Matrix4
    {
    public:
        Matrix4() = default;
        constexpr Matrix4(const Matrix4&) = default;
        constexpr Matrix4& operator=(const Matrix4&) = default;

        constexpr Matrix4(BS_ZERO)
            :m{ {0.0f, 0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f, 0.0f} }
        {}

        constexpr Matrix4(BS_IDENTITY)
            :m{ {1.0f, 0.0f, 0.0f, 0.0f},
                {0.0f, 1.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 1.0f, 0.0f},
                {0.0f, 0.0f, 0.0f, 1.0f} }
        { }

        constexpr Matrix4(
            float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33)
            :m{ {m00, m01, m02, m03},
                {m10, m11, m12, m13},
                {m20, m21, m22, m23},
                {m30, m31, m32, m33} }
        { }

        constexpr explicit Matrix4(const Matrix3& mat3)
            :m{ {mat3.m[0][0], mat3.m[0][1], mat3.m[0][2], 0.0f},
                {mat3.m[1][0], mat3.m[1][1], mat3.m[1][2], 0.0f},
                {mat3.m[2][0], mat3.m[2][1], mat3.m[2][2], 0.0f},
                {0.0f, 0.0f, 0.0f, 1.0f} }
        { }

        void swap(Matrix4& other)
        {
            std::swap(m[0][0], other.m[0][0]);
            std::swap(m[0][1], other.m[0][1]);
            std::swap(m[0][2], other.m[0][2]);
            std::swap(m[0][3], other.m[0][3]);
            std::swap(m[1][0], other.m[1][0]);
            std::swap(m[1][1], other.m[1][1]);
            std::swap(m[1][2], other.m[1][2]);
            std::swap(m[1][3], other.m[1][3]);
            std::swap(m[2][0], other.m[2][0]);
            std::swap(m[2][1], other.m[2][1]);
            std::swap(m[2][2], other.m[2][2]);
            std::swap(m[2][3], other.m[2][3]);
            std::swap(m[3][0], other.m[3][0]);
            std::swap(m[3][1], other.m[3][1]);
            std::swap(m[3][2], other.m[3][2]);
            std::swap(m[3][3], other.m[3][3]);
        }

        Vector4& operator[](UINT32 row)
        {
            assert(row < 4);

            return *(Vector4*)m[row];
        }

        Matrix4 operator*(const Matrix4& rhs) const;

        Matrix4 operator+(const Matrix4& rhs) const;

        Matrix4 operator-(const Matrix4& rhs) const;

        inline bool operator==(const Matrix4& rhs) const;

        inline bool operator!=(const Matrix4& rhs) const
        {
            return !operator==(rhs);
        }

        Matrix4 operator*(float rhs) const;

        Vector3 getColumn(UINT32 col) const;

        Vector4 getColumn4D(UINT32 col) const;

        Matrix4 transpose() const;

        void setColumn(UINT32 idx, const Vector4& column);

        void setRow(UINT32 idx, const Vector4& column);

        Matrix3 get3x3() const;

        // °éËæ¾ØÕó£¿
        Matrix4 adjoint() const;

        // ÐÐÁÐÊ½
        float determinant() const;

        float determinant3x3() const;

        Matrix4 inverse() const;

        void setTRS(const Vector3& translation, const Quaternion& rotation, const Vector3& scale);

        void setInverseTRS(const Vector3& translation, const Quaternion& rotation, const Vector3& scale);

        void decomposition(Vector3& position, Quaternion& rotation, Vector3& scale);

        Vector3 getTranslation() const;

        bool isAffine() const;

        Matrix4 inverseAffine() const;

        Matrix4 concatenateAffine(const Matrix4& other) const;

        Plane multiplyAffine(const Plane& p) const;

        Vector3 multiplyAffine(const Vector3& v) const;

        Vector4 multiplyAffine(const Vector4& v) const;

        Vector3 multiplyDirection(const Vector3& v) const;

        Vector3 multiply(const Vector3& v) const;

        Vector4 multiply(const Vector4& v) const;

        void makeView(const Vector3& position, const Quaternion& rotation);

        void makeProjectionOrtho(float left, float right, float top, float near, float far);

        static Matrix4 translation(const Vector3& translation);

        static Matrix4 scaling(const Vector3& scale);

        static Matrix4 scaling(float scaling);

        static Matrix4 rotation(const Quaternion& rotation);

        static Matrix4 projectionPerspective(const Degree& horzFOV, float aspect, float near, float far,
            bool positiveZ = false);

        static Matrix4 projectionOrthographic(float left, float right, float top, float bottom, float neat, float far);

        static Matrix4 view(const Vector3& position, const Quaternion& orientation);

        static Matrix4 TRS(const Vector3& translation, const Quaternion& rotation, const Vector3& scale);

        static Matrix4 inverseTRS(const Vector3 translation, const Quaternion& rotation, const Vector3& scale);

        static const Matrix4 ZERO;
        static const Matrix4 IDENTITY;

    private:
        float m[4][4];

    };
}