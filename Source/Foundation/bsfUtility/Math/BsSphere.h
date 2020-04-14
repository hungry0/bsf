#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class BS_UTILITY_EXPORT Sphere
    {
	public:
		Sphere() = default;

		Sphere(const Vector3& center, float radius)
			:mRadius(radius), mCenter(center) {}

		float getRadius() const;

		void setRadius(float radius);

		const Vector3& getCenter() const;

		void setCenter(const Vector3& center);

		void merge(const Sphere& rhs);

		void merge(const Vector3& point);

		void transform(const Matrix4& matrix);

		inline bool contains(const Vector3& v) const;

		bool intersects(const Sphere& s) const;

		bool intersects(const AABox& box) const;

		bool intersects(const Plane& plane) const;

		std::pair<bool, float> intersects(const Ray& ray, bool discardInside = true) const;

	private:
		float mRadius = 1.0f;
		Vector3 mCenter{Vector3::ZERO};
    };
}
