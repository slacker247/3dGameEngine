#include <time.h>
#include <map>

#include "String.h"
#include "Settings.h"
#include "OpenGLRender.h"
#include "LoadState.h"
#include "BaseState.h"

using namespace std;
using namespace States;

#pragma once

namespace gameLoop
{
	class GameLoop
	{
	protected:
        int frameRate;
        bool frame;
        long m_FPS;
        long m_LastFPS;
        long m_FPSTime;
        int gameTimer;
        clock_t lastTime;
        clock_t currentTime;
        int lastFPS;
        int currentFPS;
        clock_t beforeExeTime;
        clock_t afterExeTime;
        clock_t exeTimer;

		engine::Settings* m_Settings;
		::renderers::Renderer* m_Renderer;
		String m_Title;
		String m_ReturnAction;
		String m_PauseGame;
		String m_DefaultState;
		String m_CurrentState;
		map<String, BaseState*> m_States;

	public:
		// Default Constructor
		GameLoop();
		GameLoop(engine::Settings* settings);
		// Copy Constructor
		GameLoop(const GameLoop &inGameLoop);
		virtual GameLoop& operator=( const GameLoop& rhs );
	    virtual GameLoop* clone() const;
		virtual void copy(const GameLoop &inGameLoop);
		// Destructor
		~GameLoop();

		void deleteStates();
		virtual void init();
		void loadSettings();
		int loadStates(LoadXML* loader);
		virtual void loop();
        long getTimeDiff(void);
		BaseState* newState(String& name, String& type);
	};
}