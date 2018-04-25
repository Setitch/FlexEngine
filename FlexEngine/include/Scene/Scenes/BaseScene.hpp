#pragma once

#include <string>
#include <vector>

#include "GameContext.hpp"
#include "Scene/GameObject.hpp"

namespace flex
{
	class PhysicsWorld;
	class ReflectionProbe;
	struct JSONObject;

	class BaseScene
	{
	public:
		BaseScene(const std::string& name, const std::string& jsonFilePath);
		virtual ~BaseScene();

		std::string GetName() const;

		PhysicsWorld* GetPhysicsWorld();

		/* 
		* Serializes all data from scene into JSON scene file.
		* Only writes data that has non-default values (e.g. an identity 
		* transform is not saved)
		*/
		void SerializeToFile(const GameContext& gameContext);

	protected:
		virtual void Initialize(const GameContext& gameContext);
		virtual void PostInitialize(const GameContext& gameContext);
		virtual void Destroy(const GameContext& gameContext);
		virtual void Update(const GameContext& gameContext);

		void AddChild(const GameContext& gameContext, GameObject* gameObject);
		void RemoveChild(GameObject* gameObject, bool deleteChild);
		void RemoveAllChildren(bool deleteChildren);

		PhysicsWorld* m_PhysicsWorld = nullptr;

	private:
		GameObject* CreateEntityFromJSON(const GameContext& gameContext, const JSONObject& obj);

		JSONObject SerializeObject(GameObject* gameObject, const GameContext& gameContext);

		void RootInitialize(const GameContext& gameContext);
		void RootPostInitialize(const GameContext& gameContext);
		void RootUpdate(const GameContext& gameContext);
		void RootDestroy(const GameContext& gameContext);

		friend class SceneManager;

		std::string m_Name;
		std::string m_JSONFilePath;

		std::vector<GameObject*> m_Children;

		ReflectionProbe* m_ReflectionProbe = nullptr;

		BaseScene(const BaseScene&) = delete;
		BaseScene& operator=(const BaseScene&) = delete;
	};
} // namespace flex
