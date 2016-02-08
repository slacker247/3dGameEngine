#include <list>

#include "Polygon.h"

using namespace std;

#pragma once

namespace assets
{
	class Mesh
	{
	protected:
		list<Polygon> m_Polygons;

	public:
		// Default Constructor
		Mesh();
		// Copy Constructor
		Mesh(const Mesh &inMesh);
		virtual Mesh& operator=( const Mesh& rhs );
	    virtual Mesh* clone() const;
		virtual void copy(const Mesh &inMesh);
		// Destructor
		~Mesh();

		int deletePolys();
		int addPoly(Polygon* poly);
		Polygon* newPoly();
		list<Polygon>* getPolys();
	};
}