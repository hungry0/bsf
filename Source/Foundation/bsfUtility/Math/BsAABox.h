#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

#include "Math/BsVector3.h"
#include "Math/BsMatrix4.h"

namespace bs
{
    class BS_UTILITY_EXPORT AABox
    {
        /** Different corners of a box. */
        /*
           1-----2
          /|    /|
         / |   / |
        5-----4  |
        |  0--|--3
        | /   | /
        |/    |/
        6-----7
        */
    public:
        enum Corner
        {
            FAR_LEFT_BOTTOM = 0,
            FAR_LEFT_TOP = 1,
            FAR_RIGHT_TOP = 2,
            FAR_RIGHT_BOTTOM = 3,
            NEAR_RIGHT_BOTTOM = 7,
            NEAR_LEFT_BOTTOM = 6,
            NEAR_LEFT_TOP = 5,
            NEAR_RIGHT_TOP = 4
        };

        AABox();
        AABox(const AABox& copy) = default;
        AABox(const Vector3& min, const Vector3& max);

        ~AABox() = default;

        const Vector3& getMin() const
        {
            return mMininum;
        }

        const Vector3 getMax() const
        {
            return mMaximum;
        }

        void setMin(const Vector3& vec)
        {
            mMininum = vec;
        }

        void setMax(const Vector3& vec)
        {
            mMaximum = vec;
        }

        void setExtends(const Vector3& min, const Vector3& max);

        void scale(const Vector3& s);

        Vector3 getCorner(Corner cornerToGet) const;

        void merge(const AABox& rhs);

        void merge(const Vector3& point);

        void transform(const Matrix4& matrix);

        void transformAffine(const Matrix4& matrix);

        bool intersects(const AABox& b2) const;

        bool intersects(const Sphere& s) const;

        bool intersects(const Plane& plane) const;

        std::pair<bool, float> intersects(const Ray& ray) const;

        bool intersects(const Ray& ray, float& d1, float& d2) const;

        Vector3 getCenter() const;

        Vector3 getSize() const;

        Vector3 getHalfSize() const;

        float getRadius() const;

        float getVolume() const;

        bool contains(const Vector3& v) const;

        bool contains(const Vector3& v, float extra) const;

        bool contains(const AABox& other) const;

        bool operator==(const AABox& rhs) const;

        bool operator!=(const AABox& rhs) const;

        static const AABox BOX_EMPTY;
        static const AABox UNIT_BOX;
        static const AABox INF_BOX;

        static const UINT32 CUBE_INDICES[36];

    protected:
        Vector3 mMininum{ Vector3::ZERO };
        Vector3 mMaximum{ Vector3::ONE };
    };
}