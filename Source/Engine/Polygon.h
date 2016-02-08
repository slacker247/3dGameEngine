#include <list>
#include <iterator>

#include "Vertex.h"

using namespace std;

#pragma once

namespace assets
{
	class Polygon
	{
	protected:
		list<Vertex> m_Vertices;
		bool m_NormalsCalcd;
		float m_Normal[3];

	public:
		// Default Constructor
		Polygon();
		// Copy Constructor
		Polygon(const Polygon &inPolygon);
		virtual Polygon& operator=( const Polygon& rhs );
	    virtual Polygon* clone() const;
		virtual void copy(const Polygon &inPolygon);
		// Destructor
		~Polygon();
		
		int deleteVerts();
		int addVertex(Vertex* vert);
		Vertex* newVertex();
		list<Vertex>* getVertices();
		float* getNormal();
	};
}