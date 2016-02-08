#pragma once

namespace renderers
{
	class RenderSettings
	{
	public:
		// Default Constructor
		RenderSettings();
		// Copy Constructor
		RenderSettings(const RenderSettings &inRenderSettings);
		RenderSettings& operator=( const RenderSettings& rhs );
	    virtual RenderSettings* clone() const;
		void copy(const RenderSettings &inRenderSettings);
		// Destructor
		~RenderSettings();
	};
}