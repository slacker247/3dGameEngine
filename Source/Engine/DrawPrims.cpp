#include "DrawPrims.h"

namespace renderers
{
	DrawPrims::DrawPrims(void)
	{
		CreateSphere(70,0,0,0);
	}

	DrawPrims::~DrawPrims(void)
	{
	}

	void DrawPrims::drawCube(double wdl)
	{
		glScalef(wdl, wdl, wdl);
		glBegin(GL_LINE_LOOP); // Start drawing a line primitive
			glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
			glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner
			glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner
			glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner

			glVertex3f(1.0f, -1.0f, 1.0f); // The bottom left corner
			glVertex3f(1.0f, 1.0f, 1.0f); // The top left corner
			glVertex3f(-1.0f, 1.0f, 1.0f); // The top right corner
			glVertex3f(-1.0f, -1.0f, 1.0f); // The bottom right corner

			glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner
		glEnd();
	}

	void DrawPrims::drawSphere(double radius, int texture)
	{
		int b;

		glScalef (0.0125 * radius, 0.0125 * radius, 0.0125 * radius);
		glRotatef (90, 1, 0, 0);
		if(texture > -1)
			glBindTexture (GL_TEXTURE_2D, texture);
		else
			glColor4f(1,1,1,1);

		glBegin (GL_TRIANGLE_STRIP);

		for ( b = 0; b <= VertCount; b++)
		{
			Point* txt = sphere[b].getTextCoord();
			glTexCoord2f (txt->getX(), txt->getY());
			Point* pt = sphere[b].getPosition();
			glVertex3f (pt->getX(), pt->getY(), -pt->getZ());
		}
		for ( b = 0; b <= VertCount; b++)
		{
			Point* txt = sphere[b].getTextCoord();
			glTexCoord2f (txt->getX(), -txt->getY());
			Point* pt = sphere[b].getPosition();
			glVertex3f (pt->getX(), pt->getY(), pt->getZ());
		}
		glEnd();
	}

	void DrawPrims::CreateSphere (double R, double H, double K, double Z)
	{
		int n;
		int space = 10;
		double a;
		double b;

		n = 0;

		for( b = 0; b <= 90 - space; b += space)
		{
			for( a = 0; a <= 360 - space; a += space)
			{
				Point* txt = sphere[n].getTextCoord();
				Point* pt = sphere[n].getPosition();
				pt->setX(R * sin((a) / 180 * PI) * sin((b) / 180 * PI) - H);
				pt->setY(R * cos((a) / 180 * PI) * sin((b) / 180 * PI) + K);
				pt->setZ(R * cos((b) / 180 * PI) - Z);
				txt->setX((2 * b) / 360);
				txt->setY((a) / 360);
				n++;
				txt = sphere[n].getTextCoord();
				pt = sphere[n].getPosition();

				pt->setX(R * sin((a) / 180 * PI) * sin((b + space) / 180 * PI) - H);
				pt->setY(R * cos((a) / 180 * PI) * sin((b + space) / 180 * PI) + K);
				pt->setY(R * cos((b + space) / 180 * PI) - Z);
				txt->setX((2 * (b + space)) / 360);
				txt->setY((a) / 360);
				n++;
				txt = sphere[n].getTextCoord();
				pt = sphere[n].getPosition();

				pt->setX(R * sin((a + space) / 180 * PI) * sin((b) / 180 * PI) - H);
				pt->setY(R * cos((a + space) / 180 * PI) * sin((b) / 180 * PI) + K);
				pt->setZ(R * cos((b) / 180 * PI) - Z);
				txt->setX((2 * b) / 360);
				txt->setY((a + space) / 360);
				n++;
				txt = sphere[n].getTextCoord();
				pt = sphere[n].getPosition();

				pt->setX(R * sin((a + space) / 180 * PI) * sin((b + space) / 180 * PI) - H);
				pt->setY(R * cos((a + space) / 180 * PI) * sin((b + space) / 180 * PI) + K);
				pt->setZ(R * cos((b + space) / 180 * PI) - Z);
				txt->setX((2 * (b + space)) / 360);
				txt->setY((a + space) / 360);
				n++;
			}
		}
	}
}