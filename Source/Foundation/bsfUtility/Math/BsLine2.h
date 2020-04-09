#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector2.h"

namespace bs
{
    // 
    class BS_UTILITY_EXPORT Line2
    {
    public:
        Line2() = default;

        Line2(const Vector2& origin, const Vector2& direction)
            : mOrigin(origin), mDirection(direction)
        {};

        void setOrigin(const Vector2& origin)
        {
            mOrigin = origin;
        }

        const Vector2& getOrigin() const
        {
            return mOrigin;
        }

        void setDirection(const Vector2& dir)
        {
            mDirection = dir;
        }

        const Vector2& getDirection() const
        {
            return mDirection;
        }

        Vector2 getPoint(float t) const;

        Vector2 operator*(float t) const;

        std::pair<bool, float> intersects(const Line2& line) const;

    protected:
        Vector2 mOrigin{Vector2::ZERO};
        Vector2 mDirection{Vector2::ZERO};
    };
}