#pragma once

#include "Prerequisites/BsPlatformDefines.h"

namespace bs
{
    class Degree;

    // »¡¶È
    class BS_UTILITY_EXPORT Radian
    {
    public:
        constexpr Radian() = default;
        constexpr Radian(const Radian&) = default;
        constexpr Radian& operator=(const Radian&) = default;

        constexpr explicit Radian(float r) : mRad(r) {}

        constexpr Radian& operator=(const float& f)
        {
            mRad = f;
            return *this;
        }

        Radian(const Degree& d);

        //Radian& operator=(const Degree& d);

        float valueDegrees() const;

        constexpr float valueRadians() const;

        // clamp[0, 2pai]
        Radian wrap();

        const Radian& operator+() const
        {
            return *this;
        }

        Radian operator+(const Radian& r) const
        {
            return Radian(mRad + r.mRad);
        }

        Radian operator+(const Degree& d) const;

        Radian& operator+=(const Radian& r)
        {
            mRad += r.mRad;
            return *this;
        }

        Radian& operator+=(const Degree& d);

        Radian operator-() const
        {
            return Radian(-mRad);
        }

        Radian operator-(const Radian& r) const
        {
            return Radian(mRad - r.mRad);
        }

        Radian operator-(const Degree& d) const;

        Radian& operator-=(const Radian& r)
        {
            mRad -= r.mRad;
            return *this;
        }

        Radian& operator-=(const Degree& d);

        Radian operator*(float f) const
        {
            return Radian(mRad * f);
        }

        Radian operator*(const Radian& r) const
        {
            return Radian(mRad * r.mRad);
        }

        Radian& operator*=(float f)
        {
            mRad *= f;
            *this;
        }

        Radian operator/(float f) const
        {
            return Radian(mRad / f);
        }

        Radian& operator/=(float f)
        {
            mRad /= f;
            *this;
        }

        friend Radian operator*(float lhs, const Radian& rhs)
        {
            return Radian(lhs * rhs.mRad);
        }

        friend Radian operator/(float lhs, const Radian& rhs)
        {
            return Radian(lhs / rhs.mRad);
        }

        friend Radian operator+(Radian& lhs, float rhs)
        {
            return Radian(lhs.mRad + rhs);
        }

        friend Radian operator+(float lhs, const Radian& rhs)
        {
            return Radian(lhs + rhs.mRad);
        }

        friend Radian operator-(const Radian& lhs, float rhs)
        {
            return Radian(lhs.mRad - rhs);
        }

        friend Radian operator-(float lhs, const Radian& rhs)
        {
            return Radian(lhs - rhs.mRad);
        }

        bool operator<(const Radian& r) const
        {
            return mRad < r.mRad;
        }

        bool operator<= (const Radian& r) const 
        { 
            return mRad <= r.mRad;
        }

        bool operator== (const Radian& r) const
        {
            return mRad == r.mRad; 
        }

        bool operator!= (const Radian& r) const
        {
            return mRad != r.mRad; 
        }

        bool operator>= (const Radian& r) const
        {
            return mRad >= r.mRad; 
        }

        bool operator>  (const Radian& r) const
        {
            return mRad > r.mRad; 
        }

    private:
        float mRad = 0.0f;
    };
}