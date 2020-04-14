#pragma once

#include "Prerequisites/BsPrerequisitesUtil.h"
#include "Math/BsVector3.h"

namespace bs
{
    class BS_UTILITY_EXPORT Rect3
    {
	public:
		Rect3() = default;

		Rect3(const Vector3& center, const std::array<Vector3, 2>& axes,
			const std::array<float, 2>& extents)
			:mCenter(center), mAxisHorz(axes[0]), m_AxisVert(axes[1]),
			mExtentHorz(extents[0]), mExtentVert(extents[1]) {}

		std::pair<std::array<Vector3, 2>, float> getNearestPoint(const Ray& ray) const;

		std::pair<Vector3, float> getNearestPoint(const Vector3& point) const;

		std::pair<bool, float> intersects(const Ray& ray) const;

		const Vector3& getCenter() const;

		const Vector3& getAxisHorz() const;

		const Vector3& getAxisVert() const;

		const float& getExtentHorz() const;

		const float& getExtentVertical() const;


	private:
		Vector3 mCenter{BsZero};
		Vector3 mAxisHorz{ BsZero };
		Vector3 m_AxisVert{ BsZero };
		float mExtentHorz = 0.0f;
		float mExtentVert = 0.0f;
    };
}
