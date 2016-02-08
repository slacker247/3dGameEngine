#include "String.h"
#include "BaseState.h"

using namespace States;

#pragma once

namespace renderers
{
	class Renderer
	{
	public:
		// Default Constructor
		Renderer();
		Renderer(String settings);
		// Copy Constructor
		Renderer(const Renderer &inRenderer);
		Renderer& operator=( const Renderer& rhs );
	    virtual Renderer* clone() const = 0;
		void copy(const Renderer &inRenderer);
		// Destructor
		~Renderer();

		virtual int init() = 0;
		virtual int reSize(double cx, double cy) = 0;
		virtual int draw(BaseState* state) = 0;
	};
}