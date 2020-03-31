#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class Radian;
    class Degree;

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

        constexpr Matrix3(BS_INDENTITY)
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

        //explicit Matrix3(const Quaternion& rotation){ }

        explicit Matrix3(const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis)
        {
            //fromAxes(xaxis, yaxis, zaxis);
        }







    protected:
        float m[3][3];
    };
}
