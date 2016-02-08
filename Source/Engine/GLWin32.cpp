#include "GLWin32.h"

namespace gameLoop
{
	bool g_WindowResized = false;

	// Default Constructor
	GLWin32::GLWin32()
	{
	}

	GLWin32::GLWin32(engine::Settings* settings)
		: GameLoop(settings)
	{
	}

	// Copy Constructor
	GLWin32::GLWin32(const GLWin32 &inGLWin32)
	{
		copy(inGLWin32);
	}

	GLWin32& GLWin32::operator=( const GLWin32& rhs )
	{
		copy(rhs);
		return *this;
	}

	GLWin32* GLWin32::clone() const
	{
		return new GLWin32(*this);
	}

	void GLWin32::copy(const GLWin32 &inGLWin32)
	{
		this->m_hDC = inGLWin32.m_hDC;
		this->m_hRC = inGLWin32.m_hRC;
		this->m_hwndWindow = inGLWin32.m_hwndWindow;
	}

	// Destructor
	GLWin32::~GLWin32()
	{
	}
	
	int GLWin32::setupPixelFormat(HDC &hdc)
	{
		int status = 0;
		static PIXELFORMATDESCRIPTOR pfd; 
		int pixelformat; 
 
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
		pfd.nVersion = 1;							// Always set this to 1
													// Pass in the appropriate OpenGL flags
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
		pfd.dwLayerMask = PFD_MAIN_PLANE;			// We want the standard mask (this is ignored anyway)
		pfd.iPixelType = PFD_TYPE_RGBA;				// We want RGB and Alpha pixel type
		pfd.cColorBits = 24;						// Here we use our #define for the color bits
		pfd.cDepthBits = 16;						// Depthbits is ignored for RGBA, but we do it anyway
		pfd.cAccumBits = 0;							// No special bitplanes needed
		pfd.cStencilBits = 0;						// We desire no stencil bits
 
		// This gets us a pixel format that best matches the one passed in from the device
		if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == FALSE ) 
		{ 
			status = -2; 
		} 
 
		// This sets the pixel format that we extracted from above
		if (SetPixelFormat(hdc, pixelformat, &pfd) == FALSE) 
		{ 
			status = -3; 
		} 
		return status;
	}

	void GLWin32::init()
	{
		GameLoop::loadSettings();

		// console window exists as soon as app start

		// get its hwnd using combo of "GetConsoleWindowTitle()"
		// and "FindWindow()"

		// Why did i call this _REGION_A_? see end notes!
		#pragma region _REGION_A_ - get HWND of console

		char title[500];

		GetConsoleTitleA( title, 500 ); // retrieve the text
		// of the title bar of the console window

		printf("window title: %s\n", title);

		HWND hwndConsole = FindWindowA( NULL, title );  // FindWindowA actually
		// can get you the HWND of a window, based
		// on the text in its title bar!
		if(hwndConsole != NULL)
			printf("Found window.\n");
		#pragma endregion

		#pragma region _REGION_B - get HINSTANCE and create a window!
		////////////////////////
		// Getting the HINSTANCE given the HWND
		//
		// Want the HINSTANCE of a window, but
		// you only have its HWND?
		//
		// Here's how you generally get the HINSTANCE
		// of the console, based off of the HWND of
		// the console.
		HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndConsole, GWL_HINSTANCE);

		if(hInstance != NULL)
			printf("Found handle to window.\n");

		////////////////////
		// Now I'm going to create an ACTUAL WINDOW.
		//
		// Note that you always need a HINSTANCE
		// to create a window, which is why I just
		// got it in the line just above here.
		WNDCLASS wc = {0};
		wc.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.hCursor = LoadCursor( hInstance, IDC_ARROW );
		wc.hIcon = LoadIcon( hInstance, IDI_APPLICATION );
		wc.hInstance = hInstance;
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = TEXT("GLWnd32");
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (RegisterClass( &wc ) )
		{
			// Create a real live window!
			// (see http://bobobobo.wordpress.com/2008/01/31/how-to-create-a-basic-window-in-c/
			// for more details on basic windows)
			this->m_hwndWindow = CreateWindow(
							TEXT("GLWnd32"),
							LPCWSTR(this->m_Title.c_str()),
							WS_OVERLAPPEDWINDOW,
							520, 20, // pos: x, y
							// size: width, height
							this->m_Settings->getViewWidth(), this->m_Settings->getViewHeight(),
							NULL,   // if you make this hwndConsole, then
									// the console becomes this window's parent
									// Then, this window wouldn't get an
									// entry in the taskbar
							NULL,
							hInstance,
							NULL);
			if(this->m_hwndWindow)
			{
				this->m_hDC = GetDC(m_hwndWindow);	// This sets our global HDC
				// We don't free this hdc until the end of our program
				if (setupPixelFormat(this->m_hDC) > -1)	// This sets our pixel format/information
				{
					this->m_hRC = wglCreateContext(this->m_hDC);	// This creates a rendering context from our hdc
					wglMakeCurrent(this->m_hDC, this->m_hRC);	// This makes the rendering context we just created the one we want to use
				}

				GameLoop::init();

				ShowWindow( this->m_hwndWindow, SW_SHOWNORMAL );  // ShowWindow() on msdn
				printf("Showing window.\n");
				UpdateWindow( this->m_hwndWindow );
				#pragma endregion

				// Enter regular message loop, to process messages for
				// our window.
				#pragma region _REGION_C - message loop
				MSG msg;
				while(1)// GetMessage( &msg,this-> m_hwndWindow, 0, 0 ) )
				{
					// 
					if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
					{ 
						if(msg.message == WM_QUIT)	// If the message wasnt to quit
							break;
						if(msg.message == WM_NCLBUTTONDOWN) // 161: window resize event
							g_WindowResized = true;
						//printf("wnd_msg:%d\n", msg.message);
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
					else
					{
						if(g_WindowResized)
						{
							RECT wndRect;
							GetWindowRect(this->m_hwndWindow , &wndRect );
							this->m_Renderer->reSize(wndRect.right - wndRect.left, wndRect.bottom - wndRect.top);
							g_WindowResized = false;
						}
						this->loop();
						SwapBuffers(this->m_hDC);	// Swap the backbuffers to the foreground
					}
				}
			}
			else
				printf("Failed to create window.\n");
			#pragma endregion
		}
	}

	// Window Procedure
	LRESULT CALLBACK GLWin32::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		int result = -1;
		switch (message)
		{
		case WM_CREATE:
			result = 0;
			break;
		case WM_CLOSE:
			PostQuitMessage( 0 );
			result = 0;
			break;
		case WM_DESTROY:
			result = 0;
			break;
		case WM_SIZE:
		case WM_EXITSIZEMOVE:
			g_WindowResized = true;
			break;
		case WM_KEYDOWN:
			switch ( wParam )
			{
				// Keyboard input
			case VK_ESCAPE:
				PostQuitMessage(0);
				result = 0;
				break;
			}
			result = 0;
			break;
		default:
			result = DefWindowProc( hWnd, message, wParam, lParam );
			break;
		}
		return result;
	}
}