#include "RenderSettings.h"

namespace renderers
{
	// Default Constructor
	RenderSettings::RenderSettings()
	{
	}

	// Copy Constructor
	RenderSettings::RenderSettings(const RenderSettings &inRenderSettings)
	{
		copy(inRenderSettings);
	}

	RenderSettings& RenderSettings::operator=( const RenderSettings& rhs )
	{
		copy(rhs);
		return *this;
	}

	RenderSettings* RenderSettings::clone() const
	{
		return new RenderSettings(*this);
	}

	void RenderSettings::copy(const RenderSettings &inRenderSettings)
	{
	}

	// Destructor
	RenderSettings::~RenderSettings()
	{
	}
}
