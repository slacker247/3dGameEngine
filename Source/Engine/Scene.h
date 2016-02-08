#include <cassert>
#include <map>
#include <iterator>

#include "String.h"
#include "Asset.h"
#include "Camera.h"
#include "Model.h"
#include "Texture.h"
#include "Material.h"
#include "Light.h"

using namespace std;

#pragma once

namespace assets
{
	class Scene
	{
	protected:
		static String STR_CAMERA; // = newString("camera");
		static String STR_MODEL; // = newString("model");
		static String STR_MATERIAL; // = newString("material");
		static String STR_TEXTURE; // = newString("texture");
		static String STR_LIGHT; // = newString("light");
		static String STR_GROUP; // = newString("group");

		map<String, Asset*> m_Assets;

	public:
		// Default Constructor
		Scene();
		// Copy Constructor
		Scene(const Scene &inScene);
		virtual Scene& operator=( const Scene& rhs );
	    virtual Scene* clone() const;
		virtual void copy(const Scene &inScene);
		// Destructor
		~Scene();
		int deleteAssets();

		int addAsset(Asset* asset);
		Asset* newAsset(String& type, String& name);
		Asset* getAsset(String& name);
		map<String, Asset*>* getAssets();
	};
}