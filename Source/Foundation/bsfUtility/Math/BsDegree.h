#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class Radian;

    class BS_UTILITY_EXPORT Degree
    {
    public:
        constexpr Degree() = default;
        constexpr Degree(const Degree&) = default;
        constexpr Degree& operator=(const Degree&) = default;

        constexpr explicit Degree(float d) : mDeg(d) {}
        constexpr Degree& operator=(const float& f)
        {
            mDeg = f;
            return *this;
        }

        Degree(const Radian& r);

        Degree& operator=(const Radian& r);

        constexpr float valueDegrees() const
        {
            return mDeg;
        }

        float valueRadians() const;

        // [0, 360)
        Degree wrap();

        const Degree& operator+() const
        {
            return *this;
        }

        Degree operator+(const Degree& d) const
        {
            return Degree(mDeg + d.mDeg);
        }

        Degree operator+(const Radian& r);

        Degree& operator+=(const Degree& d)
        {
            mDeg += d.mDeg;
            return *this;
        }

        Degree& operator+=(const Radian& r);

        Degree operator-() const
        {
            return Degree(-mDeg);
        }

        Degree operator-(const Degree& d)
        {
            return Degree(mDeg - d.mDeg);
        }

        Degree operator-(const Radian& r) const;

        Degree& operator-=(const Degree& d)
        {
            mDeg -= d.mDeg;
            return *this;
        }

        Degree& operator-=(const Radian& r);

        Degree operator*(float f) const
        {
            return Degree(mDeg * f);
        }

        Degree operator*(const Degree& d) const
        {
            return Degree(mDeg * d.mDeg);
        }

        Degree& operator*=(float f) const
        {
            return Degree(mDeg / f);
        }

        Degree operator/(float f) const
        {
            return Degree(mDeg / f);
        }

        Degree& operator/=(float f)
        {
            mDeg /= f;
            return *this;
        }

        friend Degree operator* (float lhs, const Degree& rhs) { return Degree(lhs * rhs.mDeg); }
        friend Degree operator/ (float lhs, const Degree& rhs) { return Degree(lhs / rhs.mDeg); }
        friend Degree operator+ (Degree& lhs, float rhs) { return Degree(lhs.mDeg + rhs); }
        friend Degree operator+ (float lhs, const Degree& rhs) { return Degree(lhs + rhs.mDeg); }
        friend Degree operator- (const Degree& lhs, float rhs) { return Degree(lhs.mDeg - rhs); }
        friend Degree operator- (const float lhs, const Degree& rhs) { return Degree(lhs - rhs.mDeg); }

        bool operator<  (const Degree& d) const { return mDeg < d.mDeg; }
        bool operator<= (const Degree& d) const { return mDeg <= d.mDeg; }
        bool operator== (const Degree& d) const { return mDeg == d.mDeg; }
        bool operator!= (const Degree& d) const { return mDeg != d.mDeg; }
        bool operator>= (const Degree& d) const { return mDeg >= d.mDeg; }
        bool operator>  (const Degree& d) const { return mDeg > d.mDeg; }

    private:
        float mDeg = 0.0f;
    };
}
