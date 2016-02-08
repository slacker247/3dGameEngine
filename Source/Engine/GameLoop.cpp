#include "GameLoop.h"

namespace gameLoop
{
	GameLoop::GameLoop()
	{
	}

	GameLoop::GameLoop(engine::Settings* settings)
	{
		this->m_Settings = settings;
	}

	// Copy Constructor
	GameLoop::GameLoop(const GameLoop &inGameLoop)
	{
		copy(inGameLoop);
	}

	GameLoop& GameLoop::operator=( const GameLoop& rhs )
	{
		copy(rhs);
		return *this;
	}

	GameLoop* GameLoop::clone() const
	{
		return new GameLoop(*this);
	}

	void GameLoop::copy(const GameLoop &inGameLoop)
	{
		this->m_Settings = inGameLoop.m_Settings->clone();
		this->m_Renderer = inGameLoop.m_Renderer->clone();
		this->m_Title = inGameLoop.m_Title;
		this->m_ReturnAction = inGameLoop.m_ReturnAction;
		this->m_PauseGame = inGameLoop.m_PauseGame;
		this->m_DefaultState = inGameLoop.m_DefaultState;
		this->deleteStates();
		for (map<String, BaseState*>::const_iterator itState = inGameLoop.m_States.begin();
			itState != inGameLoop.m_States.end();
			++itState)
		{
			this->m_States[itState->first] = itState->second->clone();
		}
	}

	// Destructor
	GameLoop::~GameLoop()
	{
		// TODO : Cleanup
		//m_States
	}

	void GameLoop::deleteStates()
	{
		for (map<String, BaseState*>::const_iterator itState = this->m_States.begin();
			itState != this->m_States.end();
			++itState)
		{
			if(this->m_States[itState->first] != NULL)
				delete this->m_States[itState->first];
		}
		this->m_States.clear();
	}
	
	BaseState* GameLoop::newState(String& name, String& type)
	{
		BaseState* state = NULL;
		if(this->m_States.find(name) == this->m_States.end())
		{
			this->m_States[name] = new BaseState();
		}
		state = this->m_States[name];
		return state;
	}

	void GameLoop::loadSettings()
	{
		// load initial state
		loaders::LoadXML lXML;
		lXML.loadXML(this->m_Settings->getStatesPath());
		this->m_Title = lXML.getTagContent(newString("Title"));
		this->m_ReturnAction = lXML.getTagContent(newString("return_action"));
		this->m_PauseGame = lXML.getTagContent(newString("pause_game"));
		this->m_DefaultState = lXML.getTagContent(newString("default"));
		this->m_CurrentState = this->m_DefaultState;
		loadStates(&lXML);
	}
	
	int GameLoop::loadStates(LoadXML* loader)
	{
		int status = -1;
		if(loader != NULL &&
		   loader->getDocument() != NULL)
		{
			XMLCh nodeName[100];
			XMLString::copyString(nodeName, newString("state").c_str());
			DOMNodeList* nodeList = loader->getDocument()->getElementsByTagName(nodeName);
			if(nodeList != NULL &&
				nodeList->getLength() > 0)
			{
				for(int i = 0; i < nodeList->getLength(); i++)
				{
					String type = loader->getTagContent(newString("type"), (DOMElement*)nodeList->item(i));
					String name = loader->getTagContent(newString("name"), (DOMElement*)nodeList->item(i));
					BaseState* state = this->newState(name, type);
					String camera = loader->getTagContent(newString("camera"), (DOMElement*)nodeList->item(i));
					String resources = loader->getTagContent(newString("resources"), (DOMElement*)nodeList->item(i));
					if(state != NULL)
					{
						state->setName(name);
						state->setResourceXML(resources);
						state->setCamera(camera);
					}
				}
			}
		}
		return status;
	}

	void GameLoop::init()
	{
		lastTime = clock();
		currentTime = clock();
		lastFPS = 0;
		currentFPS = 0;
		m_FPS = 0;
		m_LastFPS = 0;
		m_FPSTime = 0;
		frameRate = 15;
		frame = false;
		beforeExeTime = clock();
		afterExeTime = clock();
		exeTimer = 20;

		printf("initializing renderer.\n");
		m_Renderer = NULL;
		if(cmpStrI(*(this->m_Settings->getRenderer()), engine::Settings::OPENGL) == 0)
		{
			
			m_Renderer = new renderers::OpenGLRender(*(this->m_Settings->getRenderSettingsFile()));
		}
		if(m_Renderer != NULL)
		{
			m_Renderer->init();
			m_Renderer->reSize(this->m_Settings->getViewWidth(), this->m_Settings->getViewHeight());
		}
	}

	void GameLoop::loop()
	{
		
		beforeExeTime = clock();
		
		long deltaTime = getTimeDiff();
		// Set state
		if(!this->m_States[this->m_CurrentState]->isLoaded())
		{
			// display loading screen
			loaders::LoadState::loadState(this->m_States[this->m_CurrentState]);
		}
		// calc user movement
		// calc ai movement
		// calc physics
		// pre render (pixel shaders, camera effects)
		// render
		static int frameNum = 0;
		if(frame)
			frameNum++;
		if(frameNum > 1743)
			frameNum = 0;
		((renderers::OpenGLRender*)m_Renderer)->frame = frameNum;
		m_Renderer->draw(m_States[this->m_CurrentState]);
		// post render

		long t_current = clock();
		afterExeTime = clock();
		exeTimer = t_current - afterExeTime + 5;
		if (exeTimer < 5)
		{
			exeTimer = 5;
		}

	}

	long GameLoop::getTimeDiff(void)
	{
		currentTime = clock();
		long diff = currentTime - lastTime;
		lastTime = currentTime;
		if (diff < 0)
		{
			diff = 0;
		}

		frame = false;
		currentFPS += diff;
		m_FPSTime += diff;
		m_LastFPS++;
		if (currentFPS >= CLOCKS_PER_SEC / frameRate)
		{
			currentFPS = 0;
			frame = true;
		}
		if(m_FPSTime >= 1000)
		{
			m_FPS = m_LastFPS;
			m_LastFPS = 0;
			m_FPSTime = 0;

			char msg[255];
			sprintf(msg, "FPS : %d\n", m_FPS);
			printf(msg);
		}
		return diff;
	}
}