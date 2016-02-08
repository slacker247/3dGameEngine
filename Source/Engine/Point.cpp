#include "Point.h"

namespace math
{
	// Default Constructor
	Point::Point()
	{
		this->m_XYZ[0] = 0;
		this->m_XYZ[1] = 0;
		this->m_XYZ[2] = 0;
		this->m_XYZ[3] = 1;
	}

	// Copy Constructor
	Point::Point(const Point &inPoint)
	{
		copy(inPoint);
	}
	
	Point& Point::operator=( const Point& rhs )
	{
		copy(rhs);
		return *this;
	}

	Point* Point::clone() const
	{
		return new Point(*this);
	}

	void Point::copy(const Point &inPoint)
	{
		this->m_XYZ[0] = inPoint.m_XYZ[0];
		this->m_XYZ[1] = inPoint.m_XYZ[1];
		this->m_XYZ[2] = inPoint.m_XYZ[2];
		this->m_XYZ[3] = inPoint.m_XYZ[3];
	}

	// Destructor
	Point::~Point()
	{
	}

	float* Point::getPos()
	{
		return this->m_XYZ;
	}

	float Point::getX()
	{
		return this->m_XYZ[0];
	}

	int Point::setX(float x)
	{
		int status = -1;
		if(!isZero(x))
			this->m_XYZ[0] = x;
		else
			this->m_XYZ[0] = 0;
		return status;
	}

	float Point::getY()
	{
		return this->m_XYZ[1];
	}

	int Point::setY(float y)
	{
		int status = -1;
		if(!isZero(y))
			this->m_XYZ[1] = y;
		else
			this->m_XYZ[1] = 0;
		return status;
	}

	float Point::getZ()
	{
		return this->m_XYZ[2];
	}

	int Point::setZ(float z)
	{
		int status = -1;
		if(!isZero(z))
			this->m_XYZ[2] = z;
		else
			this->m_XYZ[2] = 0;
		return status;
	}

	float Point::getW()
	{
		return this->m_XYZ[3];
	}

	int Point::setW(float w)
	{
		int status = -1;
		if(!isZero(w))
			this->m_XYZ[3] = w;
		else
			this->m_XYZ[3] = 0;
		return status;
	}

	Point Point::scalar(float num)
	{
		Point p;
		for(int i; i < 3; i++)
			p.setX(this->m_XYZ[i] * num);
		return p;
	}

	Point Point::add(Point* v)
	{
		Point p;
		p.setX(this->getX() + v->getX());
		p.setY(this->getY() + v->getY());
		p.setZ(this->getZ() + v->getZ());
		return p;
	}

	Point Point::subtract(Point* v)
	{
		Point p;
		p.setX(this->getX() - v->getX());
		p.setY(this->getY() - v->getY());
		p.setZ(this->getZ() - v->getZ());
		return p;
	}

	Point Point::multiply(Point* v)
	{
		Point p;
		p.setX(this->getX() * v->getX());
		p.setY(this->getY() * v->getY());
		p.setZ(this->getZ() * v->getZ());
		return p;
	}

	float Point::magnitude()
	{
		float mag = sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2));
		return mag;
	}

	Point Point::normalize()
	{
		Point p;
		float mag = this->magnitude();
		p.setX(this->getX()/mag);
		p.setY(this->getY()/mag);
		p.setZ(this->getZ()/mag);
		return p;
	}

	/// Returns the angle between the given vectors
	float Point::dotProduct(Point* v)
	{
		Point top;
		top = this->multiply(v);
		float tResult = top.getX() + top.getY() + top.getZ();
		float bV1 = this->magnitude();
		float bV2 = v->magnitude();
		float radians = acos(tResult/(bV1 * bV2));
		return (radians * (180/PI));
	}

	/// Returned vector is perpendicular to the plane of the given vectors
	Point Point::crossProduct(Point* v)
	{
		Point p;
		p.setX(this->getY() * v->getZ() - this->getZ() * v->getY());
		p.setY(this->getZ() * v->getX() - this->getX() * v->getZ());
		p.setX(this->getX() * v->getY() - this->getY() * v->getX());
		p = p.normalize();
		return p;
	}

	bool Point::isZero(float num)
	{
		bool status = false;
		if(num < 0.0000004f &&
		   num > -0.0000004f)
			status = true;
		return status;
	}
}