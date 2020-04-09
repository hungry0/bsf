#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsLineSegment3.h"


namespace bs
{
    class BS_UTILITY_EXPORT Capsule
    {
    public:
        Capsule() = default;
        Capsule(const LineSegment3& segment, float radius);

        std::pair<bool, float> intersects(const Ray& ray) const;

        const LineSegment3& getSegment() const
        {
            return mSegment;
        }

        float getRadius() const
        {
            return mRadius;
        }

        float getHeight() const;

        Vector3 getCenter() const;

    protected:
        LineSegment3 mSegment;
        float mRadius = 0.0f;
    };
}
