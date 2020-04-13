#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Rect2I
    {
    public:
        constexpr Rect2I() = default;

        constexpr Rect2I(INT32 x, INT32 y, UINT32 width, UINT32 height)
            : x(x), y(y), width(width), height(height) {}

        bool contains(const Vector2I& point) const;

        bool overlaps(const Rect2I& other) const;

        void encapsulate(const Rect2I& other);

        void clip(const Rect2I& clipRect);

        void cut(const Rect2I& cutRect, Vector<Rect2I>& pieces);

        void cut(const Vector<Rect2I>& cutRects, Vector<Rect2I>& pieces);

        void transform(const Matrix4& mat);

        bool operator==(const Rect2I& rhs) const;

        bool operator!=(const Rect2I& rhs) const;

        static const Rect2I EMPTY;

    public:
        INT32 x = 0;
        INT32 y = 0;
        UINT32 width = 0;
        UINT32 height = 0;
    };
}
