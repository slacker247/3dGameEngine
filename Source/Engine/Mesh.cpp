#include "Mesh.h"

namespace assets
{
	// Default Constructor
	Mesh::Mesh()
	{
	}

	// Copy Constructor
	Mesh::Mesh(const Mesh &inMesh)
	{
		copy(inMesh);
	}

	Mesh& Mesh::operator=( const Mesh& rhs )
	{
		copy(rhs);
		return *this;
	}

	Mesh* Mesh::clone() const
	{
		return new Mesh(*this);
	}

	void Mesh::copy(const Mesh &inMesh)
	{
		deletePolys();
		for (list<Polygon>::const_iterator itPoly = inMesh.m_Polygons.begin();
			itPoly != inMesh.m_Polygons.end();
			++itPoly)
		{
			this->m_Polygons.push_back(*itPoly);
		}
	}

	// Destructor
	Mesh::~Mesh()
	{
	}

	int Mesh::deletePolys()
	{
		int status = -1;
		this->m_Polygons.clear();
		return status;
	}

	int Mesh::addPoly(Polygon* poly)
	{
		int status = -1;
		if(poly != NULL)
		{
			this->m_Polygons.push_back(*poly);
			status = 0;
		}
		return status;
	}

	Polygon* Mesh::newPoly()
	{
		Polygon* poly = NULL;
		this->m_Polygons.push_back(Polygon());
		poly = &(this->m_Polygons.back());
		return poly;
	}

	list<Polygon>* Mesh::getPolys()
	{
		return &(this->m_Polygons);
	}
}