#include "PlayState.h"

namespace States
{
	PlayState::PlayState(void)
	{
	}
	
	PlayState::PlayState(const PlayState &inPlayState)
		: BaseState(inPlayState)
	{
		copy(inPlayState);
	}

	PlayState& PlayState::operator=( const PlayState& rhs )
	{
		copy(rhs);
		return *this;
	}

	PlayState* PlayState::clone() const
	{
		return new PlayState(*this);
	}

	void PlayState::copy(const PlayState &inPlayState)
	{
	}

	PlayState::~PlayState(void)
	{
	}
}