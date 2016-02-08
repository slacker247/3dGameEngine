#include "KeyFrame.h"

namespace assets
{
	KeyFrame::KeyFrame(void)
	{
		this->m_FrameNumber = 0;
	}

	// Copy Constructor
	KeyFrame::KeyFrame(const KeyFrame &inAsset)
	{
		copy(inAsset);
	}

	KeyFrame& KeyFrame::operator=( const KeyFrame& rhs )
	{
		copy(rhs);
		return *this;
	}

	KeyFrame* KeyFrame::clone() const
	{
		return new KeyFrame(*this);
	}

	void KeyFrame::copy(const KeyFrame &inKeyFrame)
	{
		this->m_Matrix = inKeyFrame.m_Matrix;
		this->m_FrameNumber = inKeyFrame.m_FrameNumber;
	}

	KeyFrame::~KeyFrame(void)
	{
	}

	int KeyFrame::setMatrix(math::Matrix* matrix)
	{
		int status = -1;
		if(matrix != NULL)
		{
			// copy operation
			this->m_Matrix = *matrix;
			status = -1;
		}
		return status;
	}

	math::Matrix* KeyFrame::getMatrix()
	{
		return &(this->m_Matrix);
	}

	int KeyFrame::getFrameNumber()
	{
		return this->m_FrameNumber;
	}

	int KeyFrame::setFrameNumber(int frame)
	{
		int status = -1;
		this->m_FrameNumber = frame;
		return status;
	}
}