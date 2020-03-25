//************************************ bs::framework - Copyright 2018 Marko Pintera **************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#include "Components/BsCHingeJoint.h"
#include "Scene/BsSceneObject.h"
#include "Private/RTTI/BsCHingeJointRTTI.h"

namespace bs
{
	CHingeJoint::CHingeJoint()
		: CJoint(mDesc)
	{
		setName("HingeJoint");
	}

	CHingeJoint::CHingeJoint(const HSceneObject& parent)
		: CJoint(parent, mDesc)
	{
		setName("HingeJoint");
	}

	Radian CHingeJoint::getAngle() const
	{
		if (mInternal == nullptr)
			return Radian(0.0f);

		return _getInternal()->getAngle();
	}

	float CHingeJoint::getSpeed() const
	{
		if (mInternal == nullptr)
			return 0.0f;

		return _getInternal()->getSpeed();
	}

	LimitAngularRange CHingeJoint::getLimit() const
	{
		return mDesc.limit;
	}

	void CHingeJoint::setLimit(const LimitAngularRange& limit)
	{
		if (limit == mDesc.limit)
			return;

		mDesc.limit = limit;

		if (mInternal != nullptr)
			_getInternal()->setLimit(limit);
	}

	HingeJointDrive CHingeJoint::getDrive() const
	{
		return mDesc.drive;
	}

	void CHingeJoint::setDrive(const HingeJointDrive& drive)
	{
		if (drive == mDesc.drive)
			return;

		mDesc.drive = drive;

		if (mInternal != nullptr)
			_getInternal()->setDrive(drive);
	}

	void CHingeJoint::setFlag(HingeJointFlag flag, bool enabled)
	{
		bool isEnabled = ((UINT32)mDesc.flag & (UINT32)flag) != 0;
		if (isEnabled == enabled)
			return;

		if (enabled)
			mDesc.flag = (HingeJointFlag)((UINT32)mDesc.flag | (UINT32)flag);
		else
			mDesc.flag = (HingeJointFlag)((UINT32)mDesc.flag & ~(UINT32)flag);

		if (mInternal != nullptr)
			_getInternal()->setFlag(flag, enabled);
	}

	bool CHingeJoint::hasFlag(HingeJointFlag flag) const
	{
		return ((UINT32)mDesc.flag & (UINT32)flag) != 0;
	}

	SPtr<Joint> CHingeJoint::createInternal()
	{
		SPtr<Joint> joint = HingeJoint::create(mDesc);

		joint->_setOwner(PhysicsOwnerType::Component, this);
		return joint;
	}

	RTTITypeBase* CHingeJoint::getRTTIStatic()
	{
		return CHingeJointRTTI::instance();
	}

	RTTITypeBase* CHingeJoint::getRTTI() const
	{
		return CHingeJoint::getRTTIStatic();
	}
}