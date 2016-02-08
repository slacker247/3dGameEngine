
#include "Matrix.h"

#pragma once

namespace assets
{
	class KeyFrame
	{
	protected:
		math::Matrix m_Matrix;
		math::Matrix m_OffsetMatrix;
		int m_FrameNumber;
	public:
		// Default Constructor
		KeyFrame();
		// Copy Constructor
		KeyFrame(const KeyFrame &inKeyFrame);
		virtual KeyFrame& operator=( const KeyFrame& rhs );
	    virtual KeyFrame* clone() const;
		virtual void copy(const KeyFrame &inKeyFrame);
		// Destructor
		~KeyFrame();
				
		int setMatrix(math::Matrix* matrix);
		math::Matrix* getMatrix();
		int getFrameNumber();
		int setFrameNumber(int frame);
	};
}