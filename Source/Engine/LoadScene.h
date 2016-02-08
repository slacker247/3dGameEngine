#include <map>

#include "LoadXML.h"
#include "LoadAsset.h"
#include "Scene.h"
#include "Asset.h"
#include "Time.h"
#include "Thread.h"

using namespace std;
using namespace assets;

#pragma once

namespace loaders
{
	class LoadScene
	{
		static String STR_NAME; // newString("Name")
		static String STR_FILE; // newString("File")
		static String STR_TYPE; // newString("Type")
	public:
		LoadScene(void);
		~LoadScene(void);

		static Scene* loadScene(String* fileName, Scene* scene);
	};
}
