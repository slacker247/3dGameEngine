#include "Asset.h"

#pragma once

namespace assets
{
	class Sound : Asset
	{
	public:
		// Default Constructor
		Sound();
		// Copy Constructor
		Sound(const Sound &inSound);
		virtual Sound& operator=( const Sound& rhs );
	    virtual Sound* clone() const;
		virtual void copy(const Sound &inSound);
		// Destructor
		~Sound();
	};
}