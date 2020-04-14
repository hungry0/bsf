#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"

namespace bs
{
    class BS_UTILITY_EXPORT Math
    {
	public:
		static constexpr float BIGGEST_FLOAT_SMALLER_THAN_ONE = 0.99999994f;

		static Radian acos(float val);

		static Radian asin(float val);

		static Radian atan(float val);

		static Radian atan2(float y, float x);

		static float cos(const Radian& val);

		static float cos(float val);

		static float sin(const Radian& val);

		static float sin(float val);

		static float tan(const Radian& val);

		static float tan(float val);

		static float sqrt(float val);

		static float sqrt(const Radian& val);

		static float sqrt(const Degree& val);

		static float invSqrt(float val);

		static float sqr(float val);

		static float pow(float base, float exponent);

		static float log(float val);

		static float log2(float val);

		static float logN(float base, float val);

		static float sign(float val);

		static Radian sign(const Radian& val);

		static Degree sign(const Degree& val);

		static float abs(float val);

		static Degree abs(const Degree& val);

		static Radian abs(const Radian& val);

		static float ceil(float val);

		static INT32 ceilToInt(float val);

		static UINT32 ceilToPosInt(float val);

		static float round(float val);

		static INT32 roundToInt(float val);

		static UINT32 roundToPosInt(float val);

		template<class T>
		static constexpr T divideAndRoundUp(T n, T d);

		static float floor(float val);

		static int floatToInt(float val);

		static UINT32 floorToPosInt(float val);

		static float roundToMultiple(float x, float multiple);

		template<typename T>
		static T clamp(T val, T minval, T maxval);

		template<typename T>
		static T clamp01(T val);

		static float frac(float val);

		static float repeat(float val, float length);

		static float pingPong(float val, float length);

		static bool isNaN(float f);

		static bool approxEquals(float a, float b, 
			float tolerance = std::numeric_limits<float>::epsilon());

		static bool approxEquals(double a, double b,
			double tolerance = std::numeric_limits<double>::epsilon());

		static bool approxEquals(const Vector2& a, const Vector2& b,
			float tolerance = std::numeric_limits<float>::epsilon());

		static bool approxEquals(const Vector3& a, const Vector3& b,
			float tolerance = std::numeric_limits<float>::epsilon());

		static bool approxEquals(const Vector4& a, const Vector4& b,
			float tolerance = std::numeric_limits<float>::epsilon());

		static bool approxEquals(const Quaternion& a, const Quaternion& b,
			float tolerance = std::numeric_limits<float>::epsilon());

		static Vector3 calculateTriTangent(const Vector3& position1, const Vector3& position2,
			const Vector3& position3, float u1, float v1, float u2, float v2, float u3, float v3);



		static float fastSin0(float val);

		static float fastSin1(const Radian& val);

		static float fastSin1(float val);

		static float fastCos0(const Radian& val);

		static float fastCos0(float val);

		static float fastCos1(const Radian& val);

		static float fastTan0(const Radian& val);

		static float fastTan0(float val);

		static float fastTan1(const Radian& val);

		static float fastTan1(float val);

		static float fastASin0(const Radian& val);

		static float fastASin0(float val);

		static float fastASin1(float val);

		static float fastACos0(const Radian& val);

		static float fastACos0(float val);

		static float fastACos1(const Radian& val);

		static float fastATan0(const Radian& val);

		static float fastATan0(float val);

		static float fastATan1(const Radian& val);

		static float fastATan1(float val);

		template<typename T>
		static T lerp(float t, T min, T max);

		template<typename T>
		static float invLerp(T val, T min, T max);

		template<typename T>
		static UINT32 solveLinear(T A, T B, T* roots);

		template<typename T>
		static UINT32 solveQuadratic(T A, T B, T C, T* roots);

		template<typename T>
		static UINT32 solveCubic(T A, T B, T C, T D, T* roots);

		template<typename T>
		static UINT32 solveQuartic(T A, T B, T C, T D, T E, T* roots);

		template<typename T>
		static T cubicHermite(float t, const T& pointA, const T& pointB, const T& tangentA, const T& tangetB);

		template<typename T>
		static T cubicHermiteD1(float t, const T& pointA, const T& pointB, const T& tangentA, const T& tangentB);

		template<class T>
		static void cubicHerimiteCoefficients(const T& pointA, const T& pointB, const T& tangentA,
			const T& tangentB, T (&coefficients)[4]);

		template<class T>
		static void cubicHermiteCoefficients(const T& pointA, const T& pointB, const T& tangentA, const T& tangentB,
			float length, T(&coefficients)[4]);

		template<typename T>
		static T rombergIntegration(T a, T b, int order, const std::function<T(T)> integrand);

		template<typename T>
		static T gaussianQuadrature(T a, T b, T* roots, T* coefficients, const std::function<T(T)>& integrand);

		static constexpr float POS_INFINITY = std::numeric_limits<float>::infinity();
		static constexpr float NEG_INFINITY = -std::numeric_limits<float>::infinity();
		static constexpr float PI = 3.14159265358979323846f;
		static constexpr float TWO_PI = (float)(2.0f * PI);
		static constexpr float HALF_PI = (float)(0.5f * PI);
		static constexpr float QUARTER_PI = (float)(0.25f * PI);
		static constexpr float INV_PI = (float)(1 / PI);
		static constexpr float INV_HALF_PI = (float)(INV_PI / 2);
		static constexpr float INV_TWO_PI = (float)(2.0f * INV_PI);
		static constexpr float DEG2RAD = PI / 180.0f;
		static constexpr float RAD2DEG = 180.0f / PI;
		static constexpr float SQRT2 = 1.4142135623730951f;
		static constexpr float INV_SQRT2 = (float)(1.0f / SQRT2);

		static const float LOG2;
    };
}
