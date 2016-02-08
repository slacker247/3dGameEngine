#ifdef WIN32
#include <windows.h>
#endif
#include <map>
#include <gl\gl.h>										// Header File For The OpenGL32 Library
#include <gl\glu.h>										// Header File For The GLu32 Library

#include "PixelFormatDescriptor.h"
#include "Renderer.h"
#include "String.h"
#include "BaseState.h"
#include "Camera.h"
#include "Model.h"
#include "Light.h"
#include "Material.h"
#include "Texture.h"
#include "DrawPrims.h"

using namespace States;
#pragma once

namespace renderers
{
	// http://www.khronos.org/files/opengl43-quick-reference-card.pdf
	class OpenGLRender : public Renderer
	{
		static String STR_TARGET; // newString("Target")
		static String STR_TARGET_DIRECT; // newString("#targetDirect")
	protected:
		float m_FOV;
		float m_NearClip;
		float m_FarClip;
		float m_AspectRatio;
		DrawPrims m_Prims;

	public:
		int frame;

		// Default Constructor
		OpenGLRender();
		OpenGLRender(String& settingsFile);
		// Copy Constructor
		OpenGLRender(const OpenGLRender &inRender);
		OpenGLRender& operator=( const OpenGLRender& rhs );
	    virtual OpenGLRender* clone() const;
		void copy(const OpenGLRender &inOpenGLRender);
		// Destructor
		~OpenGLRender();

		int init();
		int OpenGLRender::applyMatrix(Matrix* mat);
		int draw(BaseState* state);
		int reSize(double x, double y);
		int setupViewport( int cx, int cy );
		int setupPixelFormat();
		int setupViewingFrustum();
		int setupViewingTransform(Camera* camera, Camera* target = NULL);
	};
}