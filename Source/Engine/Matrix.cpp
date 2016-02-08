#include "Matrix.h"

namespace math
{
	// Default Constructor
	Matrix::Matrix()
	{
		loadIdentity();
		m_RotationAngle = 0;
	}

	// Copy Constructor
	Matrix::Matrix(const Matrix &inMatrix)
	{
		copy(inMatrix);
	}
	
	// operators
	Matrix& Matrix::operator=( const Matrix& rhs )
	{
		copy(rhs);
		return *this;
	}

	// Row Column multiplication
	Matrix Matrix::operator*( const Matrix& rhs )
	{
		/*
		http://www.matrix44.net/cms/notes/opengl-3d-graphics/basic-3d-math-matrices
		c[0]  c[1]  c[2]  c[3]
		c[4]  c[5]  c[6]  c[7]
		c[8]  c[9]  c[10] c[11]
		c[12] c[13] c[14] c[15]
		*/
		Matrix result;
		result = result * 0;
		for(int i= 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				for(int k = 1; k <= 4; k++)
				{
					float a = this->getElement(i, k);
					float b = rhs.getElement(k, j);
					float c = result.getElement(i, j);
					result.setElement(i, j, 
						c + (a * b)
					);
				}
			}
		}
		return result;
	}

	Matrix Matrix::operator*( const float& rhs )
	{
		Matrix result;
		for(int i = 0; i < 16; i++)
			result.m_Matrix[i] = this->m_Matrix[i] * rhs;
		return result;
	}


	Matrix Matrix::clone() const
	{
		return Matrix(*this);
	}

	void Matrix::copy(const Matrix &inMatrix)
	{
		for(int i = 0; i < 16; i++)
			this->m_Matrix[i] = inMatrix.m_Matrix[i];
		this->m_Pivot = inMatrix.m_Pivot;
		this->m_Position = inMatrix.m_Position;
		this->m_Rotation = inMatrix.m_Rotation;
		this->m_RotationAngle = inMatrix.m_RotationAngle;
		this->m_Scale = inMatrix.m_Scale;
	}

	// Destructor
	Matrix::~Matrix()
	{
	}

	int Matrix::loadIdentity()
	{
		int status = -1;
		for(int i = 0; i < 16; i++)
			m_Matrix[i] = 0;
		m_Matrix[0] = 1;
		m_Matrix[5] = 1;
		m_Matrix[10] = 1;
		m_Matrix[15] = 1;
		return status;
	}

	// setters & getters
	float* Matrix::getMatrix()
	{
		float* pMatrix = this->m_Matrix;
		return pMatrix;
	}

	// Starts at 1
	float Matrix::getElement(int row, int col) const
	{
		return this->m_Matrix[0 + (4 * (row-1)) + (col-1)];
	}
	
	// Starts at 1
	int Matrix::setElement(int row, int col, float value)
	{
		int status = -1;
		this->m_Matrix[0 + (4 * (row-1)) + (col-1)] = value;
		return status;
	}

		/*
		// http://db-in.com/blog/wp-content/uploads/2011/03/matrix_quaternion_example.jpg
		// row major, which is what it is...
		c[0]  c[1]  c[2]  c[3]
		c[4]  c[5]  c[6]  c[7]
		c[8]  c[9]  c[10] c[11]
		c[12] c[13] c[14] c[15]
		*/
	int Matrix::setRow(int rowIndex, double x, double y, double z, double n)
	{
		int status = -1;
		if(rowIndex > -1 &&
		   rowIndex < 4)
		{
			if(true) // row major
			{
				this->m_Matrix[0 + (4 * rowIndex)] = x;
				this->m_Matrix[1 + (4 * rowIndex)] = y;
				this->m_Matrix[2 + (4 * rowIndex)] = z;
				this->m_Matrix[3 + (4 * rowIndex)] = n;
			}
			else // column major
			{
				this->m_Matrix[rowIndex + (4 * 0)] = x;
				this->m_Matrix[rowIndex + (4 * 1)] = y;
				this->m_Matrix[rowIndex + (4 * 2)] = z;
				this->m_Matrix[rowIndex + (4 * 3)] = n;
			}
			status = 0;
		}
		return status;
	}

	int Matrix::setScale(double x, double y, double z)
	{
		int status = -1;
		this->m_Matrix[0] *= x;
		this->m_Matrix[5] *= y;
		this->m_Matrix[10] *= z;
		return status;
	}

	int Matrix::setScale(Point* p)
	{
		int status = -1;
		if(p != 0)
		{
			setScale(p->getX(),
					p->getY(),
					p->getZ());
			status = 0;
		}
		return status;
	}

	Point* Matrix::getScale()
	{
		this->m_Scale.setX(this->m_Matrix[0]);
		this->m_Scale.setY(this->m_Matrix[5]);
		this->m_Scale.setZ(this->m_Matrix[10]);
		return &(this->m_Scale);
	}

	int Matrix::setPosition(double x, double y, double z)
	{
		int status = -1;
		this->m_Matrix[12] = x;
		this->m_Matrix[13] = y;
		this->m_Matrix[14] = z;
		return status;
	}

	int Matrix::setPosition(Point* p)
	{
		int status = -1;
		if(p != 0)
		{
			setPosition(p->getX(),
					p->getY(),
					p->getZ());
			status = 0;
		}
		return status;
	}

	Point* Matrix::getPosition()
	{
		this->m_Position.setX(this->m_Matrix[12]);
		this->m_Position.setY(this->m_Matrix[13]);
		this->m_Position.setZ(this->m_Matrix[14]);
		return &(this->m_Position);
	}

	int Matrix::setRotation(double x, double y, double z, double angle)
	{
		// TODO : Not correct
		int status = -1;
		this->m_Rotation.setX(x);
		Matrix xMat;
		xMat.setElement(2, 2, cos(angle)*x);
		xMat.setElement(2, 3, sin(angle)*x*(-1));
		xMat.setElement(3, 2, sin(angle)*x);
		xMat.setElement(3, 3, cos(angle)*x);
		//xMat.printMatrix();

		this->m_Rotation.setY(y);
		Matrix yMat;
		yMat.setElement(1,1, cos(angle)*y);
		yMat.setElement(1,3, sin(angle)*y);
		yMat.setElement(3,1, sin(angle)*y*(-1));
		yMat.setElement(3,3, cos(angle)*y);
		//yMat.printMatrix();

		this->m_Rotation.setZ(z);
		Matrix zMat;
		zMat.setElement(1,1, cos(angle)*z);
		zMat.setElement(1,2, sin(angle)*z*(-1));
		zMat.setElement(2,1, sin(angle)*z);
		zMat.setElement(2,2, cos(angle)*z);
		//zMat.printMatrix();

		Matrix rMat = (xMat * yMat * zMat);
		//rMat.printMatrix();

		Matrix fMat = ((*this) * rMat);
		//fMat.printMatrix();

		for(int i = 0; i < 16; i++)
		{
			this->m_Matrix[i] = fMat.getMatrix()[i];
		}
		this->m_RotationAngle = angle;
		return status;
	}

	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToAngle/
	// x = (m21 - m12)/sqrt((m21 - m12)^2+(m02 - m20)^2+(m10 - m01)^2)
	// y = (m02 - m20)/sqrt((m21 - m12)^2+(m02 - m20)^2+(m10 - m01)^2)
	// z = (m10 - m01)/sqrt((m21 - m12)^2+(m02 - m20)^2+(m10 - m01)^2)
	Point* Matrix::getRotation()
	{
		this->m_Rotation.setX((this->getElement(3,2) - this->getElement(2,3))/
			sqrt(pow(this->getElement(3,2) - this->getElement(2,3), 2) +
				 pow(this->getElement(1, 3) - this->getElement(3,1), 2) +
				 pow(this->getElement(2, 1) - this->getElement(1, 2), 2)));
		this->m_Rotation.setY((this->getElement(1,3) - this->getElement(3,1))/
			sqrt(pow(this->getElement(3,2) - this->getElement(2,3), 2) +
				 pow(this->getElement(1, 3) - this->getElement(3,1), 2) +
				 pow(this->getElement(2, 1) - this->getElement(1, 2), 2)));
		this->m_Rotation.setZ((this->getElement(2,1) - this->getElement(1,2))/
			sqrt(pow(this->getElement(3,2) - this->getElement(2,3), 2) +
				 pow(this->getElement(1, 3) - this->getElement(3,1), 2) +
				 pow(this->getElement(2, 1) - this->getElement(1, 2), 2)));
		return &(this->m_Rotation);
	}
	
	//http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToAngle/
	// angle = acos(( m00 + m11 + m22 - 1)/2)
	float Matrix::getRotationAngle()
	{
		this->m_RotationAngle = acos((this->getElement(1,1) + this->getElement(2,2) + this->getElement(3,3) - 1)/2.0) * 180.0 / PI;
		return this->m_RotationAngle;
	}

	int Matrix::setPivot(double x, double y, double z)
	{
		int status = -1;
		this->m_Pivot.setX(x);
		this->m_Pivot.setY(y);
		this->m_Pivot.setZ(z);
		return status;
	}

	int Matrix::setPivot(Point* p)
	{
		int status = -1;
		if(p != 0)
		{
			setPivot(p->getX(),
					p->getY(),
					p->getZ());
			status = 0;
		}
		return status;
	}

	Point* Matrix::getPivot()
	{
		return &(this->m_Pivot);
	}

	Matrix Matrix::transpose()
	{
		Matrix& result = this->clone();
		int from[6] = {1,2,3,6,7,11};
		int to[6] = {4,8,12,9,13,14};
		for(int i = 0; i < 6; i++)
		{
			float tmp = result.getMatrix()[to[i]];
			result.getMatrix()[to[i]] = result.getMatrix()[from[i]];
			result.getMatrix()[from[i]] = tmp;
		}
		return result;
	}

	Matrix Matrix::coFactor()
	{
		Matrix result;
		for(int i = 0; i < 16; i++)
		{
			result.m_Matrix[i] = (-1) * this->m_Matrix[i];
		}
		return result;
	}

	/// http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
	Matrix Matrix::inverse()
	{
		Matrix result;
		float* mat = this->m_Matrix;
		float det = (mat[0]*mat[5]*mat[10]*mat[15] + mat[0]*mat[9]*mat[14]*mat[7] + mat[0]*mat[13]*mat[6]*mat[11] +
					 mat[4]*mat[1]*mat[14]*mat[11] + mat[4]*mat[9]*mat[2]*mat[15] + mat[4]*mat[13]*mat[10]*mat[3] +
					 mat[8]*mat[1]*mat[6]*mat[15] + mat[8]*mat[5]*mat[14]*mat[3] + mat[8]*mat[13]*mat[2]*mat[7] +
					 mat[12]*mat[1]*mat[10]*mat[7] + mat[12]*mat[5]*mat[2]*mat[11] + mat[12]*mat[9]*mat[6]*mat[3] -
					 mat[0]*mat[5]*mat[14]*mat[11] - mat[0]*mat[9]*mat[6]*mat[15] - mat[0]*mat[13]*mat[10]*mat[7] -
					 mat[4]*mat[1]*mat[10]*mat[15] - mat[4]*mat[9]*mat[14]*mat[3] - mat[4]*mat[13]*mat[2]*mat[11] -
					 mat[8]*mat[1]*mat[14]*mat[7] - mat[8]*mat[5]*mat[2]*mat[15] - mat[8]*mat[13]*mat[6]*mat[3] -
					 mat[12]*mat[1]*mat[6]*mat[11] - mat[12]*mat[5]*mat[10]*mat[3] - mat[12]*mat[9]*mat[2]*mat[7]);
		if(det != 0)
		{
			Matrix b;
			b.setElement(1,1, getElement(2,2)*getElement(3,3)*getElement(4,4) + getElement(2,3)*getElement(3,4)*getElement(4,2) +
							getElement(2,4)*getElement(3,2)*getElement(4,3) - getElement(2,2)*getElement(3,4)*getElement(4,3) -
							getElement(2,3)*getElement(3,2)*getElement(4,4) - getElement(2,4)*getElement(3,3)*getElement(4,2));
			b.setElement(1,2, getElement(1,2)*getElement(3,4)*getElement(4,3) + getElement(1,3)*getElement(3,2)*getElement(4,4) +
							getElement(1,4)*getElement(3,3)*getElement(4,2) - getElement(1,2)*getElement(3,3)*getElement(4,4) -
							getElement(1,3)*getElement(3,4)*getElement(4,2) - getElement(1,4)*getElement(3,2)*getElement(4,3));
			b.setElement(1,3, getElement(1,2)*getElement(2,3)*getElement(4,4) + getElement(1,3)*getElement(2,4)*getElement(4,2) +
							getElement(1,4)*getElement(2,2)*getElement(4,3) - getElement(1,2)*getElement(2,4)*getElement(4,3) -
							getElement(1,3)*getElement(2,2)*getElement(4,4) - getElement(1,4)*getElement(2,3)*getElement(4,2));
			b.setElement(1,4, getElement(1,2)*getElement(2,4)*getElement(3,3) + getElement(1,3)*getElement(2,2)*getElement(3,4) +
							 getElement(1,4)*getElement(2,3)*getElement(3,2) - getElement(1,2)*getElement(2,3)*getElement(3,4) -
							 getElement(1,3)*getElement(2,4)*getElement(3,2) - getElement(1,4)*getElement(2,2)*getElement(3,3));
			b.setElement(2,1, getElement(2,1)*getElement(3,4)*getElement(4,3) + getElement(2,3)*getElement(3,1)*getElement(4,4) +
							getElement(2,4)*getElement(3,3)*getElement(4,1) - getElement(2,1)*getElement(3,3)*getElement(4,4) -
							getElement(2,3)*getElement(3,4)*getElement(4,1) - getElement(2,4)*getElement(3,1)*getElement(4,3));
			b.setElement(2,2, getElement(1,1)*getElement(3,3)*getElement(4,4) + getElement(1,3)*getElement(3,4)*getElement(4,1) +
							getElement(1,4)*getElement(3,1)*getElement(4,3) - getElement(1,1)*getElement(3,4)*getElement(4,3) -
							getElement(1,3)*getElement(3,1)*getElement(4,4) - getElement(1,4)*getElement(3,3)*getElement(4,1));
			b.setElement(2,3, getElement(1,1)*getElement(2,4)*getElement(4,3) + getElement(1,3)*getElement(2,1)*getElement(4,4) +
							getElement(1,4)*getElement(2,3)*getElement(4,1) - getElement(1,1)*getElement(2,3)*getElement(4,4) -
							getElement(1,3)*getElement(2,4)*getElement(4,1) - getElement(1,4)*getElement(2,1)*getElement(4,3));
			b.setElement(2,4, getElement(1,1)*getElement(2,3)*getElement(3,4) + getElement(1,3)*getElement(2,4)*getElement(3,1) +
							 getElement(1,4)*getElement(2,1)*getElement(3,3) - getElement(1,1)*getElement(2,4)*getElement(3,3) -
							 getElement(1,3)*getElement(2,1)*getElement(3,4) - getElement(1,4)*getElement(2,3)*getElement(3,1));
			b.setElement(3,1, getElement(2,1)*getElement(3,2)*getElement(4,4) + getElement(2,2)*getElement(3,4)*getElement(4,1) +
							getElement(2,4)*getElement(3,1)*getElement(4,2) - getElement(2,1)*getElement(3,4)*getElement(4,2) -
							getElement(2,2)*getElement(3,1)*getElement(4,4) - getElement(2,4)*getElement(3,2)*getElement(4,1));
			b.setElement(3,2, getElement(1,1)*getElement(3,4)*getElement(4,2) + getElement(1,2)*getElement(3,1)*getElement(4,4) +
							getElement(1,4)*getElement(3,2)*getElement(4,1) - getElement(1,1)*getElement(3,2)*getElement(4,4) -
							getElement(1,2)*getElement(3,4)*getElement(4,1) - getElement(1,4)*getElement(3,1)*getElement(4,2));
			b.setElement(3,3, getElement(1,1)*getElement(2,2)*getElement(4,4) + getElement(1,2)*getElement(2,4)*getElement(4,1) +
							 getElement(1,4)*getElement(2,1)*getElement(4,2) - getElement(1,1)*getElement(2,4)*getElement(4,2) -
							 getElement(1,2)*getElement(2,1)*getElement(4,4) - getElement(1,4)*getElement(2,2)*getElement(4,1));
			b.setElement(3,4, getElement(1,1)*getElement(2,4)*getElement(3,2) + getElement(1,2)*getElement(2,1)*getElement(3,4) +
							 getElement(1,4)*getElement(2,2)*getElement(3,1) - getElement(1,1)*getElement(2,2)*getElement(3,4) -
							 getElement(1,2)*getElement(2,4)*getElement(3,1) - getElement(1,4)*getElement(2,1)*getElement(3,2));
			b.setElement(4,1, getElement(2,1)*getElement(3,3)*getElement(4,2) + getElement(2,2)*getElement(3,1)*getElement(4,3) +
							getElement(2,3)*getElement(3,2)*getElement(4,1) - getElement(2,1)*getElement(3,2)*getElement(4,3) -
							getElement(2,2)*getElement(3,3)*getElement(4,1) - getElement(2,3)*getElement(3,1)*getElement(4,2));
			b.setElement(4,2, getElement(1,1)*getElement(3,2)*getElement(4,3) + getElement(1,2)*getElement(3,3)*getElement(4,1) +
							getElement(1,3)*getElement(3,1)*getElement(4,2) - getElement(1,1)*getElement(3,3)*getElement(4,2) -
							getElement(1,2)*getElement(3,1)*getElement(4,3) - getElement(1,3)*getElement(3,2)*getElement(4,1));
			b.setElement(4,3, getElement(1,1)*getElement(2,3)*getElement(4,2) + getElement(1,2)*getElement(2,1)*getElement(4,3) +
							 getElement(1,3)*getElement(2,2)*getElement(4,1) - getElement(1,1)*getElement(2,2)*getElement(4,3) -
							 getElement(1,2)*getElement(2,3)*getElement(4,1) - getElement(1,3)*getElement(2,1)*getElement(4,2));
			b.setElement(4,4, getElement(1,1)*getElement(2,2)*getElement(3,3) + getElement(1,2)*getElement(2,3)*getElement(3,1) +
							 getElement(1,3)*getElement(2,1)*getElement(3,2) - getElement(1,1)*getElement(2,3)*getElement(3,2) -
							 getElement(1,2)*getElement(2,1)*getElement(3,3) - getElement(1,3)*getElement(2,2)*getElement(3,1));

			result = b * (1.0f/det);
		}
		return result;
	}

	float Matrix::determinant()
	{
		return Matrix::recursiveDet(this->m_Matrix, 16);
	}

	
	float Matrix::recursiveDet(float* m, int size)
	{
		if(size == 4)
		{
		}
		else if(size > 4)
		{

		}
		return 0;
	}

		/*
		// row major, which is what it is...
		left (X)    -- c[0]  c[1]  c[2]  c[3]
		UP (Y)      -- c[4]  c[5]  c[6]  c[7]
		Forward (Z) -- c[8]  c[9]  c[10] c[11]
		Translation -- c[12] c[13] c[14] c[15]
		*/
	void Matrix::printMatrix() const
	{
		for(int i = 0; i < 4; i++)
		{
			printf("[");
			for(int n = 0; n < 4; n++)
			{
				printf("%f, ", this->m_Matrix[n + (4 * i)]);
			}
			printf("]\n");
		}
	}
}