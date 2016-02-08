#include "Polygon.h"

namespace assets
{
	// Default Constructor
	Polygon::Polygon()
	{
		this->m_NormalsCalcd = false;
		for(int i = 0; i < 3; i++)
			this->m_Normal[i] = 0;
	}

	// Copy Constructor
	Polygon::Polygon(const Polygon &inPolygon)
	{
		copy(inPolygon);
	}

	Polygon& Polygon::operator=( const Polygon& rhs )
	{
		copy(rhs);
		return *this;
	}

	Polygon* Polygon::clone() const
	{
		Polygon* poly = NULL;
		poly = new Polygon(*this);
		return poly;
	}

	void Polygon::copy(const Polygon &inPolygon)
	{
		this->m_NormalsCalcd = inPolygon.m_NormalsCalcd;
		for(int i = 0; i < 3; i++)
			this->m_Normal[i] = inPolygon.m_Normal[i];
		deleteVerts();
		for (list<Vertex>::const_iterator itVert = inPolygon.m_Vertices.begin();
			itVert != inPolygon.m_Vertices.end();
			++itVert)
		{
			this->m_Vertices.push_back(*itVert);
		}
	}

	// Destructor
	Polygon::~Polygon()
	{
	}

	int Polygon::deleteVerts()
	{
		int status = -1;
		this->m_Vertices.clear();
		return status;
	}

	int Polygon::addVertex(Vertex* vert)
	{
		int status = -1;
		if(vert != NULL)
		{
			this->m_Vertices.push_back(*vert);
		}
		return status;
	}
	
	Vertex* Polygon::newVertex()
	{
		Vertex* vert = NULL;
		this->m_Vertices.push_back(Vertex());
		vert = &(this->m_Vertices.back());
		return vert;
	}

	list<Vertex>* Polygon::getVertices()
	{
		return &(this->m_Vertices);
	}

	float* Polygon::getNormal()
	{
		if(!this->m_NormalsCalcd)
		{
			float v1[3],v2[3];
			static const int x = 0;
			static const int y = 1;
			static const int z = 2;
			list<Vertex>::iterator vitr = this->m_Vertices.begin();
			Point* vert0 = (*vitr).getPosition();
			Point* vert1 = (*++vitr).getPosition();
			Point* vert2 = (*++vitr).getPosition();

			// Calculate The Vector From Point 1 To Point 0
			v1[x] = vert0->getX() - vert1->getX();
			v1[y] = vert0->getY() - vert1->getY();
			v1[z] = vert0->getZ() - vert1->getZ();
			// Calculate The Vector From Point 2 To Point 1
			v2[x] = vert1->getX() - vert2->getX();
			v2[y] = vert1->getY() - vert2->getY();
			v2[z] = vert1->getZ() - vert2->getZ();
			// Compute The Cross Product To Give Us A Surface Normal
			this->m_Normal[0] = v1[y]*v2[z] - v1[z]*v2[y];
			this->m_Normal[1] = v1[z]*v2[x] - v1[x]*v2[z];
			this->m_Normal[2] = v1[x]*v2[y] - v1[y]*v2[x];
			this->m_NormalsCalcd = true;
		}
		return this->m_Normal;
	}
}