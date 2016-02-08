#ifdef WIN32
#include <windows.h>
#endif
#include <gl\gl.h>										// Header File For The OpenGL32 Library
#include <gl\glu.h>										// Header File For The GLu32 Library
#include <math.h>

#include "Vertex.h"

#pragma once

#define PI 3.1415926535897
#define VertCount 1296

namespace renderers
{
	class DrawPrims
	{
	protected:
		assets::Vertex sphere[VertCount];

	public:
		DrawPrims(void);
		~DrawPrims(void);

		void drawCube(double wdl);
		void drawSphere(double radius, int texture);
		void CreateSphere(double R, double H, double K, double Z);
	};
}