//************************************ bs::framework - Copyright 2018 Marko Pintera **************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#pragma once

#include "BsCorePrerequisites.h"
#include "Reflection/BsRTTIType.h"
#include "Scene/BsGameObject.h"
#include "Scene/BsSceneObject.h"
#include "Scene/BsGameObjectManager.h"

namespace bs
{
	/** @cond RTTI */
	/** @addtogroup RTTI-Impl-Core
	 *  @{
	 */

	/**	Provides temporary storage for data used during GameObject deserialization. */
	struct GODeserializationData
	{
		SPtr<GameObject> ptr;
		UINT64 originalId = 0;
	};

	class BS_CORE_EXPORT GameObjectRTTI : public RTTIType<GameObject, IReflectable, GameObjectRTTI>
	{
	private:
		String& getName(GameObject* obj) { return obj->mName; }
		void setName(GameObject* obj, String& name) { obj->mName = name; }

		UINT64& getInstanceID(GameObject* obj) { return obj->mInstanceData->mInstanceId; }
		void setInstanceID(GameObject* obj, UINT64& instanceId) 
		{  
			// We record the ID for later use. Any child RTTI of GameObject must call GameObjectManager::registerObject
			// with this ID, so we know how to map deserialized GO handles to live objects, otherwise the handle
			// references will get broken.
			GameObject* go = static_cast<GameObject*>(obj);
			GODeserializationData& deserializationData = any_cast_ref<GODeserializationData>(go->mRTTIData);

			deserializationData.originalId = instanceId;
		}

		UINT32& getLinkId(GameObject* obj) { return obj->mLinkId; }
		void setLinkId(GameObject* obj, UINT32& linkId) { obj->mLinkId = linkId; }

	public:
		/**	Helper method used for creating Component objects used during deserialization. */
		template <typename T>
		static SPtr<T> createGameObject()
		{
			SPtr<T> component = SceneObject::createEmptyComponent<T>();
			component->mRTTIData = component;

			return component;
		}

	public:
		GameObjectRTTI()
		{
			addPlainField("mInstanceID", 0, &GameObjectRTTI::getInstanceID, &GameObjectRTTI::setInstanceID);
			addPlainField("mName", 1, &GameObjectRTTI::getName, &GameObjectRTTI::setName);
			addPlainField("mLinkId", 2, &GameObjectRTTI::getLinkId, &GameObjectRTTI::setLinkId);
		}

		void onDeserializationStarted(IReflectable* obj, SerializationContext* context) override
		{
			GameObject* gameObject = static_cast<GameObject*>(obj);

			// It's possible we're just accessing the game object fields, in which case the process below is not needed
			// (it's only required for new game objects).
			if (gameObject->mRTTIData.empty())
				return;

			SPtr<GameObject> gameObjectPtr = any_cast<SPtr<GameObject>>(gameObject->mRTTIData);

			// Every GameObject must store GODeserializationData in its RTTI data field during deserialization
			gameObject->mRTTIData = GODeserializationData();
			GODeserializationData& deserializationData = any_cast_ref<GODeserializationData>(gameObject->mRTTIData);

			// Store shared pointer since the system only provides us with raw ones
			deserializationData.ptr = gameObjectPtr;
		}

		const String& getRTTIName() override
		{
			static String name = "GameObject";
			return name;
		}

		UINT32 getRTTIId() override
		{
			return TID_GameObject;
		}

		SPtr<IReflectable> newRTTIObject() override
		{
			BS_EXCEPT(InternalErrorException, "Cannot instantiate an abstract class.");
			return nullptr;
		}
	};

	/** @} */
	/** @endcond */
}