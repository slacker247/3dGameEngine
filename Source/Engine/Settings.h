#include "String.h"
#include "Utils.h"
#include "LoadXML.h"

using loaders::LoadXML;

#pragma once

namespace engine
{
	class Settings
	{
	protected:

		// OpenGL, DX11, DX10, DX9, etc.
		String m_Renderer;

		// Win32, Linux, MacOSX, etc.
		String m_Platform;

		// The path to the states file.  Should be a relative path.
		// This file can be in any supported format of the loaders package.
		String m_StatesPath;

		bool m_FullScreen;
		int m_ViewWidth;
		int m_ViewHeight;
		String m_RenderSettingsFile;

	public:
		// TODO : May want to use the system #define for this?
		static const String WIN32_OS;
		static const String LINUX_OS;
		static const String MAC_OS;

		static const String OPENGL;
		static const String DX11;
		static const String DX10;
		static const String DX9;

		// Default Constructor
		Settings();
		// Copy Constructor
		Settings(const Settings &inSettings);
		virtual Settings& operator=( const Settings& rhs );
	    virtual Settings* clone() const;
		virtual void copy(const Settings &inSettings);
		// Destructor
		~Settings();

		int loadXML(String* settingsFile);

		String* getRenderer();
		String* getPlatform();
		String* getStatesPath();
		int getViewWidth();
		int getViewHeight();
		String* getRenderSettingsFile();
	};
}