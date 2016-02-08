#include "Asset.h"

#pragma once

namespace assets
{
	class Camera : public Asset
	{
	protected:
		float m_FOV;
		int m_FOVType;
		float m_NearRange;
		float m_FarRange;
		bool m_ClipManually;
		float m_NearClip;
		float m_FarClip;
		float m_TargetDistance;

	public:
		// Default Constructor
		Camera();
		// Copy Constructor
		Camera(const Camera &inCamera);
		virtual Camera& operator=( const Camera& rhs );
	    virtual Camera* clone() const;
		virtual void copy(const Camera &inCamera);
		// Destructor
		~Camera();

		float getFOV();
		int setFOV(float fov);
		int getFOVType();
		int setFOVType(int type);
		float getNearRange();
		int setNearRange(float range);
		float getFarRange();
		int setFarRange(float range);
		bool isClipManually();
		int setClipManually(bool clip);
		float getNearClip();
		int setNearClip(float clip);
		float getFarClip();
		int setFarClip(float clip);
		float getTargetDistance();
		int setTargetDistance(float distance);
	};
}