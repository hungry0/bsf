#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Plane
    {
    public:
        enum Side
        {
            NO_SIDE,
            POSITIVE_SIDE,
            NEGATIVE_SIDE,
            BOTH_SIDE
        };

        Plane() = default;
        Plane(const Plane& copy) = default;
        Plane(const Vector3& normal, float d);
        Plane(float a, float b, float c, float d);
        Plane(const Vector3& normal, const Vector3& point);
        Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2);

        Plane& operator=(const Plane& rhs) = default;

        Side getSide(const Vector3& point, float epsilon = 0.0f) const;

        Side getSide(const AABox& box) const;

        Side getSide(const Sphere& sphere) const;

        float getDistance(const Vector3& point) const;

        Vector3 projectVector(const Vector3& v) const;

        float normalize();

        bool intersects(const AABox& box) const;

        bool intersects(const Sphere& sphere) const;

        std::pair<bool, float> intersects(const Ray& ray) const;

        bool operator==(const Plane& rhs) const;

        bool operator!=(const Plane& rhs) const;

    public:
        Vector3 normal{BsZero};
        float d = 0.0f;
    };
}