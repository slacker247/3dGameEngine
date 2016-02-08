#include "Vertex.h"

namespace assets
{
	// Default Constructor
	Vertex::Vertex()
	{
	}

	// Copy Constructor
	Vertex::Vertex(const Vertex &inVertex)
	{
		copy(inVertex);
	}
	
	Vertex& Vertex::operator=( const Vertex& rhs )
	{
		copy(rhs);
		return *this;
	}

	Vertex* Vertex::clone() const
	{
		return new Vertex(*this);
	}

	void Vertex::copy(const Vertex &inVertex)
	{
		this->m_Position = inVertex.m_Position;
		this->m_Normal = inVertex.m_Normal;
		this->m_TextCoord = inVertex.m_TextCoord;
	}

	// Destructor
	Vertex::~Vertex()
	{
	}

	Point* Vertex::getPosition()
	{
		return &(this->m_Position);
	}

	int Vertex::setPosition(double x, double y, double z)
	{
		int status = -1;
		this->m_Position.setX(x);
		this->m_Position.setY(y);
		this->m_Position.setZ(z);
		return status;
	}
	
	Point* Vertex::getNormal()
	{
		return &(this->m_Normal);
	}

	int Vertex::setNormal(double x, double y, double z)
	{
		int status = -1;
		this->m_Normal.setX(x);
		this->m_Normal.setY(y);
		this->m_Normal.setZ(z);
		return status;
	}

	Point* Vertex::getTextCoord()
	{
		return &(this->m_TextCoord);
	}

	int Vertex::setTextCoord(double u, double v, double w)
	{
		int status = -1;
		this->m_TextCoord.setX(u);
		this->m_TextCoord.setY(v);
		this->m_TextCoord.setZ(w);
		return status;
	}
}