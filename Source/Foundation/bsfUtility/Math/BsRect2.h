#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Rect2
    {
    public:
        Rect2() = default;

        Rect2(float x, float y, float width, float height) :
            x(x), y(y), width(width), height(height) {}

        bool contains(const Vector2& point) const;

        bool overlaps(const Rect2& other) const;

        void encapsulate(const Rect2& other) const;

        void clip(const Rect2& clipRect);

        void transform(const Matrix4& matrix);

        bool operator==(const Rect2& rhs) const;

        bool operator!=(const Rect2& rhs) const;

        static const Rect2 EMPTY;


    public:
        float x = 0.0f, y = 0.0f, width = 0.0f, height = 0.0f;
    };
}
