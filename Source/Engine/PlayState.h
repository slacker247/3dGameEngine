#include "basestate.h"

#pragma once

namespace States
{
	class PlayState :
		public BaseState
	{
	public:
		PlayState(void);
		PlayState(const PlayState &inPlayState);
		PlayState& operator=( const PlayState& rhs );
	    virtual PlayState* clone() const;
		void copy(const PlayState &inPlayState);
		~PlayState(void);
	};
}