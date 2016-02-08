#include "LoadScene.h"

namespace loaders
{
	String LoadScene::STR_NAME = newString("Name");
	String LoadScene::STR_FILE = newString("File");
	String LoadScene::STR_TYPE = newString("Type");

	LoadScene::LoadScene(void)
	{
	}

	LoadScene::~LoadScene(void)
	{
	}

	// TODO : unloadScene

	Scene* LoadScene::loadScene(String* fileName, Scene* scene)
	{
		wprintf(L"Loading Scene: %s\n", fileName->c_str());

		int start = helpers::Time::getTimeMs64();
		
		loaders::LoadXML lXML;
		lXML.loadXML(fileName);
		if(lXML.getDocument() != NULL)
		{
			// load scenes
			XMLCh nodeName[100];
			XMLString::copyString(nodeName, newString("Asset").c_str());
			DOMNodeList* nodeList = lXML.getDocument()->getElementsByTagName(nodeName);
			if(nodeList != NULL &&
				nodeList->getLength() > 0)
			{
				bool threading = false;
				map<int, helpers::Thread*> threads;
				map<int, LoadAsset*> loaders;

				for(int i = 0; i < nodeList->getLength(); i++)
				{
					// Name
					String name = lXML.getTagContent(STR_NAME, (DOMElement*)nodeList->item(i));
					// File
					String file = lXML.getTagContent(STR_FILE, (DOMElement*)nodeList->item(i));
					// Type
					String type = lXML.getTagContent(STR_TYPE, (DOMElement*)nodeList->item(i));

					Asset* asset = scene->newAsset(type, name);
					
					if(threading) // 5m 33s 34ms to load slaad
					{
						loaders::LoadAsset* la = new loaders::LoadAsset();
						la->setAsset(asset);
						la->setFileName(&file);
						la->setType(&type);

						loaders[i] = la;
					
						helpers::Thread* th = new helpers::Thread(&(loaders::LoadAsset::asyncLoadAsset), la);
						threads[i] = th;
						th->setName(&name);
					}
					else // 20m 49s 501ms to load slaad
					{
						loaders::LoadAsset::loadAsset(&file, &type, asset);
						if(asset != NULL)
						{
							wprintf(L"Asset: %s\n", asset->getName()->c_str());
						}
					}
				}

				while(threads.begin() != threads.end())
				{
					map<int, helpers::Thread*>::const_iterator itThread = threads.begin();
					while(itThread != threads.end() && threads.size() > 0)
					{
						if(loaders[itThread->first] != NULL &&
							loaders[itThread->first]->m_IsFinished)
						{
							Asset* asset = loaders[itThread->first]->getAsset();
							if(asset != NULL)
							{
								wprintf(L"Asset: %s\n", asset->getName()->c_str());
							}
							else
								printf("Error...\n");
							delete loaders[itThread->first];
							loaders.erase(itThread->first);
							delete threads[itThread->first];
							threads.erase(itThread->first);
							itThread = threads.begin();
						}
						else if(!itThread->second->isAlive())
						{
							printf("Error: %d\n", itThread->first);
							loaders[itThread->first]->m_IsFinished = true;
						}
						if(itThread != threads.end() && threads.size() > 0)
						{
							++itThread;
						}
					}
					helpers::Thread::sleep(120);
				}
			}
			int end = helpers::Time::getTimeMs64();
			String delta = helpers::Time::toString(end - start);
			wprintf(L"load Time: %s\n", delta.c_str());
		}
		return scene;
	}
}