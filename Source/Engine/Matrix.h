#include "String.h"
#include "Point.h"

#pragma once

namespace math
{
	// TODO : http://www.songho.ca/opengl/gl_matrix.html
	// http://www.uwlax.edu/faculty/will/svd/svd/index.html
	// http://msdn.microsoft.com/en-us/magazine/jj863137.aspx

	// best one: http://www.matrix44.net/cms/notes/opengl-3d-graphics/basic-3d-math-matrices
	class Matrix
	{
	protected:
		float m_Matrix[16];
		Point m_Scale;
		Point m_Position;
		Point m_Rotation;
		float m_RotationAngle;
		Point m_Pivot;

	public:
		// Default Constructor
		Matrix();
		// Copy Constructor
		Matrix(const Matrix &inMatrix);
		// operators
		Matrix& operator=( const Matrix& rhs );
		Matrix operator*( const Matrix& rhs );
		Matrix operator*( const float& rhs );
	    virtual Matrix clone() const;
		void copy(const Matrix &inMatrix);
		// Destructor
		~Matrix();

		int loadIdentity();
		// setters & getters
		float* getMatrix();
		float getElement(int row, int col) const;
		int setElement(int row, int col, float value);
		int setRow(int rowIndex, double x, double y, double z, double n);
		int setScale(double x, double y, double z);
		int setScale(Point* p);
		Point* getScale();
		int setPosition(double x, double y, double z);
		int setPosition(Point* p);
		Point* getPosition();
		int setRotation(double x, double y, double z, double angle);
		Point* getRotation();
		float getRotationAngle();
		int setPivot(double x, double y, double z);
		int setPivot(Point* p);
		Point* getPivot();

		Matrix transpose();
		Matrix coFactor();
		float determinant();
		Matrix inverse();

		void printMatrix() const;

	protected:
		static float recursiveDet(float* m, int size);
	};
}