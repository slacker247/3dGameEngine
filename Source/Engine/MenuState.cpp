#include "MenuState.h"

namespace States
{
	MenuState::MenuState(void)
	{
	}
	
	MenuState::MenuState(const MenuState &inMenuState)
		: BaseState(inMenuState)
	{
		copy(inMenuState);
	}

	MenuState& MenuState::operator=( const MenuState& rhs )
	{
		copy(rhs);
		return *this;
	}

	MenuState* MenuState::clone() const
	{
		return new MenuState(*this);
	}

	void MenuState::copy(const MenuState &inMenuState)
	{
	}

	MenuState::~MenuState(void)
	{
	}
}