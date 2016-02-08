/////////////////////////////////////////////////////////
/// File: Globals.h
///
/// <author>Jeff McCartney</author>
///
/// <version>0.1</version>
///
/// <summary>This is the location for all the globals used
/// by the system.  If any class needs globals include this
/// file.</summary>
/////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <map>

#include "Asset.h"
#include "GameLoop.h"
#include "Loader.h"
#include "Network.h"
#include "Physics.h"
#include "Renderer.h"
#include "UserInput.h"

// Loader
Loader* g_Loader = 0;
// Renderer
Renderer* g_Renderer = 0;
// User Input
UserInput* g_UserInput = 0;
// Physics
Physics* g_Physics = 0;
// Network
Network* g_Network = 0;
// Display List
std::map<std::string, Asset> g_DisplayList;
// Game Loop
GameLoop* g_GameLoop = 0;
