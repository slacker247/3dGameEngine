#include "BaseState.h"

namespace States
{
	BaseState::BaseState(void)
	{
		this->m_IsLoaded = false;
	}

	// Copy Constructor
	BaseState::BaseState(const BaseState &inBaseState)
	{
		copy(inBaseState);
	}

	BaseState& BaseState::operator=( const BaseState& rhs )
	{
		copy(rhs);
		return *this;
	}

	BaseState* BaseState::clone() const
	{
		return new BaseState(*this);
	}

	void BaseState::copy(const BaseState &inBaseState)
	{
		this->m_Name = inBaseState.m_Name;
		this->m_ResourceXML = inBaseState.m_ResourceXML;
		this->m_ReturnAction = inBaseState.m_ReturnAction;
		this->m_CameraName = inBaseState.m_CameraName;
		this->m_DefaultAction = inBaseState.m_DefaultAction;

		deleteScenes();
		for (map<String, Scene>::const_iterator itScene = inBaseState.m_Scenes.begin();
			itScene != inBaseState.m_Scenes.end();
			++itScene)
		{
			this->m_Scenes[itScene->first] = itScene->second;
		}
	}

	BaseState::~BaseState(void)
	{
	}

	bool BaseState::isLoaded()
	{
		return this->m_IsLoaded;
	}

	int BaseState::setLoaded(bool loaded)
	{
		int status = -1;
		this->m_IsLoaded = loaded;
		return status;
	}

	String BaseState::getName()
	{
		return this->m_Name;
	}

	int BaseState::setName(String& name)
	{
		int status = -1;
		if(name.length() > 0)
		{
			this->m_Name = name;
			status = 0;
		}
		return status;
	}

	String BaseState::getCamera()
	{
		return this->m_CameraName;
	}

	int BaseState::setCamera(String& name)
	{
		int status = -1;
		if(name.length() > 0)
		{
			this->m_CameraName = name;
			status = 0;
		}
		return status;
	}

	String BaseState::getResourceXML()
	{
		return this->m_ResourceXML;
	}

	int BaseState::setResourceXML(String& file)
	{
		int status = -1;
		if(file.length() > 0)
		{
			this->m_ResourceXML = file;
			status = 0;
		}
		return status;
	}

	int BaseState::deleteScenes()
	{
		int status = -1;
		this->m_Scenes.clear();
		return status;
	}

	int BaseState::addScene(Scene* scene, String& name)
	{
		int status = -1;
		if(scene != NULL)
		{
			this->m_Scenes[name] = *scene;
			status = 0;
		}
		return status;
	}
	
	Scene* BaseState::newScene(String& name)
	{
		Scene* scene = NULL;
		if(this->m_Scenes.find(name) == this->m_Scenes.end())
		{
			this->m_Scenes[name] = Scene();
		}
		scene = &(this->m_Scenes[name]);
		return scene;
	}

	map<String, Scene>* BaseState::getScenes()
	{
		return &(this->m_Scenes);
	}
}