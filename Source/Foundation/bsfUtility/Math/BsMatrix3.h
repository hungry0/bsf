#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class Radian;
    class Degree;
    class Quaternion;


    // row major format
    class BS_UTILITY_EXPORT Matrix3
    {
    private:
        struct EulerAngleOrderData
        {
            int a, b, c;
            float sign;
        };

    public:
        Matrix3() = default;
        constexpr Matrix3(const Matrix3&) = default;
        constexpr Matrix3& operator=(const Matrix3&) = default;

        constexpr Matrix3(BS_ZERO)
            :m{ {0.0f,0.0f,0.0f},
                {0.0f,0.0f,0.0f},
                {0.0f,0.0f,0.0f} 
              }
        {}

        constexpr Matrix3(BS_IDENTITY)
            :m{ {1.0f,0.0f,0.0f},
                {0.0f,1.0f,0.0f},
                {0.0f,0.0f,1.0f}
              }
        {}

        constexpr Matrix3(float m00, float m01, float m02,
            float m10, float m11, float m12,
            float m20, float m21, float m22)
            :m{ {m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22} }
        { }

        explicit Matrix3(const Quaternion& rotation)
        {
            fromQuaternion(rotation);
        }

        explicit Matrix3(const Quaternion& rotation, const Vector3& scale)
        {
            fromQuaternion(rotation);

            // diy
        }

        explicit Matrix3(const Vector3& axis, const Radian& angle)
        {
            fromAxisAngle(axis, angle);
        }

        explicit Matrix3(const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis)
        {
            fromAxes(xaxis, yaxis, zaxis);
        }

        explicit Matrix3(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle)
        {
            fromEulerAngles(xAngle, yAngle, zAngle);
        }

        explicit Matrix3(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle, EulerAngleOrder order)
        {
            fromEulerAngles(xAngle, yAngle, zAngle, order);
        }

        void swap(Matrix3& order)
        {

        }

        float* operator[](UINT32 row) const
        {
            assert(row < 3);
            return (float*)m[row];
        }

        Vector3 getColumn(UINT32 col) const;

        void setColumn(UINT32 col, const Vector3& vec);

        bool operator==(const Matrix3& rhs) const;
        bool operator!=(const Matrix3& rhs) const;

        Matrix3 operator+(const Matrix3& rhs) const;
        Matrix3 operator-(const Matrix3& rhs) const;
        Matrix3 operator*(const Matrix3& rhs) const;

        Matrix3 operator-() const;
        Matrix3 operator*(float rhs) const;

        friend Matrix3 operator*(float lhs, const Matrix3& rhs);

        Vector3 multiply(const Vector3& vec) const;

        // 转置
        Matrix3 transpost() const;

        // 倒数?
        bool inverse(Matrix3& mat, float fTolerance = 1e-06f) const;

        Matrix3 inverse(float fTolerance = 1e-06f) const;

        // 行列式
        float determinant() const;

        // 拆分成旋转和缩放
        void decomposition(Quaternion& rotation, Vector3& scale) const;

        /**
         * Decomposes the matrix into various useful values.
         *
         * @param[out]	matL	Unitary matrix. Columns form orthonormal bases. If your matrix is affine and
         * 						doesn't use non-uniform scaling this matrix will be a conjugate transpose of the rotation part of the matrix.
         * @param[out]	matS	Singular values of the matrix. If your matrix is affine these will be scaling factors of the matrix.
         * @param[out]	matR	Unitary matrix. Columns form orthonormal bases. If your matrix is affine and
         * 						doesn't use non-uniform scaling this matrix will be the rotation part of the matrix.
         */
        void singularValueDecomposition(Matrix3& matL, Vector3 matS, Matrix3& matR) const;

        /**
         * Decomposes the matrix into a set of values.
         *
         * @param[out]	matQ	Columns form orthonormal bases. If your matrix is affine and
         * 						doesn't use non-uniform scaling this matrix will be the rotation part of the matrix.
         * @param[out]	vecD	If the matrix is affine these will be scaling factors of the matrix.
         * @param[out]	vecU	If the matrix is affine these will be shear factors of the matrix.
         */
        void QDUDecomposition(Matrix3& matQ, Vector3& vecD, Vector3& vecU) const;

        // 正交化
        void orthonormalize();

        void toAxisAngle(Vector3& axis, Radian& angle) const;

        void fromAxisAngle(const Vector3& axis, const Radian& angle);

        void toQuaternion(Quaternion& quat) const;

        void fromQuaternion(const Quaternion& quat);

        void fromAxes(const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis);

        bool toEulerAngles(Radian& xAngle, Radian& yAngle, Radian& zAngle) const;

        void fromEulerAngles(const Radian& xAgnle, const Radian& yAngle, const Radian& zAngle);

        void fromEulerAngles(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle, EulerAngleOrder order);

        /**
         * Eigensolver, matrix must be symmetric.
         *
         * @note
         * Eigenvectors are vectors which when transformed by the matrix, only change in magnitude, but not in direction.
         * Eigenvalue is that magnitude. In other words you will get the same result whether you multiply the vector by the
         * matrix or by its eigenvalue.
         */
        void eigenSolveSymmetric(float eigenValues[3], Vector3 eigenVectors[3]) const;

        static constexpr const float EPSILON = 1e-06f;
        static const Matrix3 ZERO;
        static const Matrix3 IDENTITY;


    protected:
        friend class Matrix4;

        //??? 干什么使的
        void tridiagonal(float diag[3], float subDiag[3]);
        bool QLAlgorithm(float diag[3], float subDiag[3]);

        static constexpr const float SVD_EPSILON = 1e-04f;
        static constexpr const unsigned int SVD_MAX_ITERS = 32;
        static void bidiagonalize(Matrix3& matA, Matrix3& matL, Matrix3& matR);
        static void golubKahanStep(Matrix3& matA, Matrix3& matL, Matrix3& matR);

        float m[3][3];
    };
}
