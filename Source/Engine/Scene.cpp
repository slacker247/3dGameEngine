#include "Scene.h"

namespace assets
{
	String Scene::STR_CAMERA = newString("camera");
	String Scene::STR_MODEL = newString("model");
	String Scene::STR_MATERIAL = newString("material");
	String Scene::STR_TEXTURE = newString("texture");
	String Scene::STR_LIGHT = newString("light");
	String Scene::STR_GROUP = newString("group");

	// Default Constructor
	Scene::Scene()
	{
		deleteAssets();
	}

	// Copy Constructor
	Scene::Scene(const Scene &inScene)
	{
		copy(inScene);
	}
	
	Scene& Scene::operator=(const Scene &rhs)
	{
		copy(rhs);
		return *this;
	}

	Scene* Scene::clone() const
	{
		return new Scene(*this);
	}

	void Scene::copy(const Scene &inScene)
	{
		deleteAssets();
		for (map<String, Asset*>::const_iterator itAsset = inScene.m_Assets.begin();
			itAsset != inScene.m_Assets.end();
			++itAsset)
		{
			Asset* asset = itAsset->second->clone();
			this->m_Assets[itAsset->first] = asset;
		}
	}

	// Destructor
	Scene::~Scene()
	{
		deleteAssets();
	}

	int Scene::deleteAssets()
	{
		int status = -1;
		for (map<String, Asset*>::const_iterator itAsset = this->m_Assets.begin();
			itAsset != this->m_Assets.end();
			++itAsset)
		{
			if(itAsset->second != NULL)
				delete itAsset->second;
		}
		this->m_Assets.clear();
		return status;
	}

	int Scene::addAsset(Asset* asset)
	{
		int status = -1;
		if(asset != NULL &&
			asset->getName() != NULL &&
			asset->getName()->length() > 0)
		{
			String name = *(asset->getName());
			if(this->m_Assets.find(name) == this->m_Assets.end())
			{
				this->m_Assets[name] = asset->clone();
				status = 0;
			}
		}
		return status;
	}

	Asset* Scene::newAsset(String& type, String& name)
	{
		Asset* asset = NULL;
		if(cmpStrI(type, STR_CAMERA) == 0)
		{
			this->m_Assets[name] = new Camera();
		}
		else if(cmpStrI(type, STR_MODEL) == 0)
		{
			this->m_Assets[name] = new Model();
		}
		else if(cmpStrI(type, STR_MATERIAL) == 0)
		{
			this->m_Assets[name] = new Material();
		}
		else if(cmpStrI(type, STR_TEXTURE) == 0)
		{
			this->m_Assets[name] = new Texture();
		}
		else if(cmpStrI(type, STR_LIGHT) == 0)
		{
			this->m_Assets[name] = new Light(); 
		}
		else if(cmpStrI(type, STR_GROUP) == 0)
		{
			this->m_Assets[name] = new Asset();
			this->m_Assets[name]->setType(Asset::GROUP);
		}
		if(m_Assets.find(name) != m_Assets.end())
		{
			asset = this->m_Assets[name];
		}
		return asset;
	}

	Asset* Scene::getAsset(String& name)
	{
		Asset* asset = NULL;
		if(this->m_Assets.size() > 0 &&
			name.size() > 0)
		{
			map<String, Asset*>::iterator it = this->m_Assets.find(name);
			if(it != this->m_Assets.end())
				asset = it->second;
		}
		return asset;
	}

	map<String, Asset*>* Scene::getAssets()
	{
		return &(this->m_Assets);
	}
}