#include <map>
#include <iterator>

#include "KeyFrame.h"

using namespace std;

#pragma once

namespace assets
{
	class Animation
	{
	protected:
		map<int, KeyFrame> m_Frames;
		int m_StartFrame;
		int m_EndFrame;
	public:
		// Default Constructor
		Animation();
		// Copy Constructor
		Animation(const Animation &inAnimation);
		virtual Animation& operator=( const Animation& rhs );
	    virtual Animation* clone() const;
		virtual void copy(const Animation &inAnimation);
		// Destructor
		~Animation();
		int deleteFrames();

		int getStartFrame();
		int setStartFrame(int frame);
		int getEndFrame();
		int setEndFrame(int frame);
		int addFrame(KeyFrame* frame);
		KeyFrame* newFrame(int frameNum);
		KeyFrame* getFrame(int frameNum);
		int removeFrame(int frameNum);
	};
}