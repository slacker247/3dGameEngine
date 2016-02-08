#include <windows.h>
#include <stdlib.h>
#include <tchar.h>

#include "String.h"
#include "GameLoop.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#pragma once

namespace gameLoop
{
	class GLWin32 : public GameLoop
	{
	protected:
		HDC m_hDC;
		HGLRC m_hRC;
		HWND m_hwndWindow;

	public:
		// Default Constructor
		GLWin32();
		GLWin32(engine::Settings* settings);
		// Copy Constructor
		GLWin32(const GLWin32 &inGLWin32);
		virtual GLWin32& operator=( const GLWin32& rhs );
	    virtual GLWin32* clone() const;
		virtual void copy(const GLWin32 &inGLWin32);
		// Destructor
		~GLWin32();

		virtual void init();

		// WINDOWS FUNCTIONS
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	protected:

		String* getWindowTitle();
		void findWindow();
		void createWindow();
		int setupPixelFormat(HDC &hdc);
	};
}