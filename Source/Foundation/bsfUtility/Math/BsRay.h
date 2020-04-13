#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class BS_UTILITY_EXPORT Ray
    {
    public:
        Ray() = default;
        Ray(const Vector3& origin, const Vector3& direction) :
            mOrigin(origin), mDirection(direction) {}

        void setOrigin(const Vector3& origin);

        const Vector3& getOrigin();

        void setDirection(const Vector3& dir);

        const Vector3& getDirection() const;

        Vector3 getPoint(float t) const;

        Vector3 operator*(float t) const;

        void transform(const Matrix4& mat);

        void transformAffine(const Matrix4& mat);

        std::pair<bool, float> intersects(const Plane& p) const;

        std::pair<bool, float> intersects(const Sphere& s) const;

        std::pair<bool, float> intersects(const AABox& box) const;

        std::pair<bool, float> intersects(const Vector3& a, const Vector3& b, const Vector3& c,
            const Vector3& normal, bool positiveSide = true, bool negativeSide = true) const;

    protected:
        Vector3 mOrigin{Vector3::ZERO};
        Vector3 mDirection{Vector3::UNIT_Z};
    };
}