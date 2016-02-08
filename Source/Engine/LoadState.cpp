#include "LoadState.h"

namespace loaders
{
	LoadState::LoadState(void)
	{
	}


	LoadState::~LoadState(void)
	{
	}
	
	int LoadState::loadState(BaseState* state)
	{
		int status = -1;
		if(state != NULL)
		{
			// TODO : Switch based on file type
			//loaders::LoadXML lXML;
			//lXML.loadXML(&(state->getResourceXML()));
			//if(lXML.getDocument() != NULL)
			{
				//// load scenes
				//XMLCh nodeName[100];
				//XMLString::copyString(nodeName, newString("Scene").c_str());
				//DOMNodeList* nodeList = lXML.getDocument()->getElementsByTagName(nodeName);
				//if(nodeList != NULL &&
				//	nodeList->getLength() > 0)
				//{
				//	for(int i = 0; i < nodeList->getLength(); i++)
				//	{
						assets::Scene* scene = state->newScene(state->getResourceXML());
				//		// Name
				//		String name = lXML.getTagContent(newString("Name"), (DOMElement*)nodeList->item(i));
				//		// File
				//		String file = lXML.getTagContent(newString("File"), (DOMElement*)nodeList->item(i));

						loaders::LoadScene::loadScene(&(state->getResourceXML()), scene);
				//	}
				//}
				state->setLoaded(true);
			}
		}
		return status;
	}

	BaseState* LoadState::getState(String& stateType)
	{
		BaseState* state = NULL;
		if(stateType == newString("MenuState"))
		{
			
			state = new MenuState();
		}
		else if(stateType == newString("PlayState"))
		{
			
			state = new PlayState();
		}
		else if(stateType == newString("Cinematic"))
		{
			
			state = new Cinematic();
		}

		return state;
	}
}