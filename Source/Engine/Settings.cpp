#include "Settings.h"

namespace engine
{
	const String Settings::WIN32_OS = newString("Win32");
	const String Settings::LINUX_OS = newString("Linux");
	const String Settings::MAC_OS = newString("MacOS");

	const String Settings::OPENGL = newString("OpenGL");
	const String Settings::DX11 = newString("DX11");
	const String Settings::DX10 = newString("DX10");
	const String Settings::DX9 = newString("DX9");

	Settings::Settings()
	{
		this->m_ViewWidth = 300;
		this->m_ViewHeight = 300;
		this->m_FullScreen = false;
		this->m_RenderSettingsFile = newString("");
	}

	// Copy Constructor
	Settings::Settings(const Settings &inSettings)
	{
		copy(inSettings);
	}

	Settings& Settings::operator=( const Settings& rhs )
	{
		copy(rhs);
		return *this;
	}

	Settings* Settings::clone() const
	{
		return new Settings(*this);
	}

	void Settings::copy(const Settings &inSettings)
	{
		this->m_Platform = inSettings.m_Platform;
		this->m_Renderer = inSettings.m_Renderer;
		this->m_StatesPath = inSettings.m_StatesPath;
		this->m_ViewWidth = inSettings.m_ViewWidth;
		this->m_ViewHeight = inSettings.m_ViewHeight;
		this->m_FullScreen = inSettings.m_FullScreen;
		this->m_RenderSettingsFile = inSettings.m_RenderSettingsFile;
	}

	// Destructor
	Settings::~Settings()
	{
	}

	int Settings::loadXML(String* settingsFile)
	{
		int status = -1;
		if(utils::Utils::fileExists(settingsFile))
		{
			LoadXML loader;

			if(loader.loadXML(settingsFile) == 0)
			{
				this->m_Platform = loader.getTagContent(newString("Platform"));
				this->m_Renderer = loader.getTagContent(newString("Renderer"));
				this->m_StatesPath = loader.getTagContent(newString("StatesPath"));
				this->m_ViewWidth = _wtoi(loader.getTagContent(newString("ViewWidth")).c_str());
				this->m_ViewHeight = _wtoi(loader.getTagContent(newString("ViewHeight")).c_str());
				this->m_FullScreen = false;
				if(cmpStrI(loader.getTagContent(newString("FullScreen")), newString("true")) == 0)
					this->m_FullScreen = true;
				this->m_RenderSettingsFile = loader.getTagContent(newString("RenderSettingsFile"));
				status = 0;
			}
		}
		return status;
	}

	String* Settings::getRenderer()
	{
		return &(this->m_Renderer);
	}

	String* Settings::getPlatform()
	{
		return &(this->m_Platform);
	}

	String* Settings::getStatesPath()
	{
		return &(this->m_StatesPath);
	}

	int Settings::getViewWidth()
	{
		return this->m_ViewWidth;
	}

	int Settings::getViewHeight()
	{
		return this->m_ViewHeight;
	}

	String* Settings::getRenderSettingsFile()
	{
		return &(this->m_RenderSettingsFile);
	}
}