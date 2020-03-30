#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
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





    protected:
        float m[3][3];
    };
}
