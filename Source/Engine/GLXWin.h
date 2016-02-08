#include "GameLoop.h"

#pragma once

namespace gameLoop
{
	class GLXWin : public GameLoop
	{
	public:
		// Default Constructor
		GLXWin();
		// Copy Constructor
		GLXWin(const GLXWin &inGLXWin);
		GLXWin& operator=( const GLXWin& rhs );
	    virtual GLXWin* clone() const;
		void copy(const GLXWin &inGLXWin);
		// Destructor
		~GLXWin();

	protected:
	};
}