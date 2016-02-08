#include "BaseState.h"

#pragma once

namespace States
{
	class MenuState :
		public BaseState
	{
	public:
		MenuState(void);
		MenuState(const MenuState &inMenuState);
		MenuState& operator=( const MenuState& rhs );
	    virtual MenuState* clone() const;
		void copy(const MenuState &inMenuState);
		~MenuState(void);
	};
}