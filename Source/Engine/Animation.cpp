#include "Animation.h"

namespace assets
{
	Animation::Animation(void)
	{
		deleteFrames();
		this->m_StartFrame = 0;
		this->m_EndFrame = 0;
	}

	// Copy Constructor
	Animation::Animation(const Animation &inAnimation)
	{
		copy(inAnimation);
	}

	Animation& Animation::operator=( const Animation& rhs )
	{
		copy(rhs);
		return *this;
	}

	Animation* Animation::clone() const
	{
		return new Animation(*this);
	}

	void Animation::copy(const Animation &inAnimation)
	{
		deleteFrames();
		for (map<int, KeyFrame>::const_iterator itAnim = inAnimation.m_Frames.begin();
			itAnim != inAnimation.m_Frames.end();
			++itAnim)
		{
			this->m_Frames[itAnim->first] = itAnim->second;
		}
		this->m_StartFrame = inAnimation.m_StartFrame;
		this->m_EndFrame = inAnimation.m_EndFrame;
	}

	Animation::~Animation(void)
	{
		deleteFrames();
	}

	int Animation::deleteFrames()
	{
		int status = -1;
		this->m_Frames.clear();
		return status;
	}
	
	int Animation::getStartFrame()
	{
		return this->m_StartFrame;
	}

	int Animation::setStartFrame(int frame)
	{
		int status = -1;
		this->m_StartFrame = frame;
		return status;
	}

	int Animation::getEndFrame()
	{
		return this->m_EndFrame;
	}

	int Animation::setEndFrame(int frame)
	{
		int status = -1;
		this->m_EndFrame = frame;
		return status;
	}

	int Animation::addFrame(KeyFrame* frame)
	{
		int status = -1;
		if(frame != NULL)
		{
			if(this->m_Frames.find(frame->getFrameNumber()) == this->m_Frames.end())
			{
				this->m_Frames[frame->getFrameNumber()] = *frame;
				status = 0;
			}
		}
		return status;
	}

	KeyFrame* Animation::newFrame(int frameNum)
	{
		KeyFrame* kf = NULL;
		this->m_Frames[frameNum] = KeyFrame();
		kf = &(this->m_Frames[frameNum]);
		return kf;
	}

	KeyFrame* Animation::getFrame(int frameNum)
	{
		KeyFrame* frame = NULL;
		if(this->m_Frames.size() > 0)
		{
			map<int, KeyFrame>::iterator it = this->m_Frames.find(frameNum);
			if(it != this->m_Frames.end())
				frame = &(it->second);
		}
		return frame;
	}

	int Animation::removeFrame(int frameNum)
	{
		int status = -1;
		this->m_Frames.erase(frameNum);
		return status;
	}
}