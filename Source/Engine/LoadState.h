#include <map>

#include "LoadXML.h"
#include "LoadScene.h"
#include "BaseState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Cinematic.h"

using namespace std;
using namespace States;

#pragma once

namespace loaders
{
	class LoadState
	{
	protected:

	public:
		LoadState(void);
		~LoadState(void);

		static int loadStates(map<String, BaseState>* states, LoadXML* loader);
		static int loadState(BaseState* state);

	protected:
		static BaseState* getState(String& stateType);
	};

}