#pragma once


namespace bs
{

    /** Values that represent in which order are euler angles applied when used in transformations. */
    enum class EulerAngleOrder
    {
        XYZ,
        XZY,
        YXZ,
        YZX,
        ZXY,
        ZYX
    };


    enum BS_ZERO
    {
        BsZero
    };

    enum BS_IDENTITY
    {
        BSIdentity
    };

    class Matrix4;
    class Sphere;
    class Plane;
    class Ray;
    class AABox;
    class Vector3;
}