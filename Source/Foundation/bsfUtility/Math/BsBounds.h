#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsAABox.h"
#include "Math/BsSphere.h"

namespace bs
{

    /** Bounds represented by an axis aligned box and a sphere. */
    class BS_UTILITY_EXPORT Bounds
    {
    public:
        Bounds() = default;
        Bounds(const AABox& box, const Sphere& sphere);
        ~Bounds() = default;

        const AABox& getBox() const
        {
            return mBox;
        }

        const Sphere& getSphere() const
        {
            return mSphere;
        }

        void setBounds(const AABox& box, const Sphere& sphere);

        void merge(const Bounds& rhs);

        void merge(const Vector3& point);

        void transform(const Matrix4& matrix);

        void transformAffine(const Matrix4& matrix);

    protected:
        AABox mBox;
        Sphere mSphere;
    };
}