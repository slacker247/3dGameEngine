#include <math.h>

#pragma once

namespace math
{
	static const float PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286F;

	// http://www.matrix44.net/cms/notes/opengl-3d-graphics/basic-3d-math-vectors
	class Point
	{
	protected:
		float m_XYZ[4];

	public:
		// Default Constructor
		Point();
		// Copy Constructor
		Point(const Point &inPoint);
		Point& operator=( const Point& rhs );
	    virtual Point* clone() const;
		void copy(const Point &inPoint);
		// Destructor
		~Point();

		float* getPos();
		float getX();
		int setX(float x);
		float getY();
		int setY(float y);
		float getZ();
		int setZ(float z);
		float getW();
		int setW(float w);

		Point scalar(float num);
		Point add(Point* v);
		Point subtract(Point* v);
		Point multiply(Point* v);
		float magnitude();
		Point normalize();
		/// Returns the angle between the given vectors
		float dotProduct(Point* v);
		/// Returned vector is perpendicular to the plane of the given vectors
		Point crossProduct(Point* v);

	protected:
		bool isZero(float num);
	};
}