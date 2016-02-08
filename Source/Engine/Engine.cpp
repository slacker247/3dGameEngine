// Engine.cpp : Defines the entry point for the console application.
//

// HACK : this is to stop the redef of DOMDocument
// ref: http://social.msdn.microsoft.com/Forums/en/vcgeneral/thread/e189173e-870d-440b-a416-340678481ed7
#ifndef __MSXML_LIBRARY_DEFINED__
#define __MSXML_LIBRARY_DEFINED__
#endif
// End HACK

#include <stdio.h>

#include "String.h"
#include "Matrix.h"
#include "Settings.h"
#include "GameLoop.h"
#include "GLWin32.h"

#include "TestLoadAsset.h"

using std::string;

using namespace engine;

Settings g_Settings;

int printUsage()
{
	int status = -1;

	printf("Usage:\n");
	printf("-s\tfull path to the settings file including the file name.\n");
	printf("\n\n");

	return status;
}

void test()
{
	char input[255];
	input[0] = '\0';
	Testing::Loaders::TestLoadAsset::run();
	printf("Finished...\n");
	scanf(input);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char settingsFile[255];
	char input[255];

	settingsFile[0] = '\0';
	input[0] = '\0';

	for(int i = 0; i < argc; i++)
	{
		if(cmpStrI(argv[i], newString("-s")) == 0)
		{
			int len = wcslen(argv[i+1]);
			wcstombs(settingsFile, argv[i+1], len);
			settingsFile[len] = '\0';
		}
		else if(cmpStrI(argv[i], newString("-t")) == 0)
		{
			test();
		}
	}

	if(strlen(settingsFile) > 0)
	{
		// Load Settings: which Renderer to use
		String file = newString(settingsFile);
		if(g_Settings.loadXML(&file) == 0)
		{
			// The location of the renderer's settings
			gameLoop::GameLoop* gl = NULL;
			if(cmpStrI(*(g_Settings.getPlatform()), Settings::WIN32_OS) == 0)
			{
				
				gl = new gameLoop::GLWin32(&g_Settings);
			}
			//else if
			gl->init();
		}
	}
	else
	{
		printUsage();
		scanf(input);
	}
	return 0;
}
