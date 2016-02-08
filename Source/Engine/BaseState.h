#include "String.h"
#include "LoadXML.h"
#include "Scene.h"

using namespace assets;

#pragma once

namespace States
{
	class BaseState
	{
	protected: 
		bool m_IsLoaded;
		String m_Name;
		String m_ResourceXML;
		String m_ReturnAction;
		String m_CameraName;
		String m_DefaultAction;
		map<String, Scene> m_Scenes;
		//map<String, Action*> m_Actions;

	public:
		BaseState(void);
		// Copy Constructor
		BaseState(const BaseState &inBaseState);
		virtual BaseState& operator=( const BaseState& rhs );
	    virtual BaseState* clone() const;
		virtual void copy(const BaseState &inBaseState);
		~BaseState(void);

		bool isLoaded();
		int setLoaded(bool loaded);
		String getName();
		int setName(String& name);
		String getCamera();
		int setCamera(String& name);
		Scene* getScene(String& name);
		String getResourceXML();
		int setResourceXML(String& file);
		int deleteScenes();
		int addScene(Scene* scene, String& name);
		Scene* newScene(String& name);
		map<String, Scene>* getScenes();
	};
}