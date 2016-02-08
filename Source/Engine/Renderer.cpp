#include "Renderer.h"

namespace renderers
{
	Renderer::Renderer()
	{
	}

	Renderer::Renderer(String settings)
	{
	}

	// Copy Constructor
	Renderer::Renderer(const Renderer &inRenderer)
	{
		copy(inRenderer);
	}

	Renderer& Renderer::operator=( const Renderer& rhs )
	{
		copy(rhs);
		return *this;
	}

	void Renderer::copy(const Renderer &inRenderer)
	{
	}

	// Destructor
	Renderer::~Renderer()
	{
	}
}