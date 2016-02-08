#include <list>

#include "Point.h"

using namespace std;
using namespace math;

#pragma once

namespace assets
{
	class Vertex
	{
	protected:
		math::Point m_Position;
		math::Point m_Normal;
		math::Point m_TextCoord;

	public:
		// Default Constructor
		Vertex();
		// Copy Constructor
		Vertex(const Vertex &inVertex);
		virtual Vertex& operator=( const Vertex& rhs );
	    virtual Vertex* clone() const;
		virtual void copy(const Vertex &inVertex);
		// Destructor
		~Vertex();

		Point* getPosition();
		int setPosition(double x, double y, double z);
		Point* getNormal();
		int setNormal(double x, double y, double z);
		Point* getTextCoord();
		int setTextCoord(double u, double v, double w);
	};
}