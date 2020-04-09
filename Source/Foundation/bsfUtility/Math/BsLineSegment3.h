#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class BS_UTILITY_EXPORT LineSegment3
    {
    public:
        LineSegment3() = default;
        LineSegment3(const Vector3& start, const Vector3& end);

        std::pair<std::array<Vector3, 2>, float> getNearestPoint(const Ray& ray) const;

        float getLength() const;

        Vector3 getCenter() const;

        Vector3 start = BsZero;
        Vector3 end = BsZero;
    };
}