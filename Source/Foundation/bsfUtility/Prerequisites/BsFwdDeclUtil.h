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
}