#include "Camera.h"

namespace assets
{
	// Default Constructor
	Camera::Camera()
	{
		m_FOV = 0;
		m_FOVType = 0;
		m_NearRange = 0;
		m_FarRange = 0;
		m_ClipManually = 0;
		m_NearClip = 0;
		m_FarClip = 0;
		m_TargetDistance = 0;

		this->m_Type = Asset::CAMERA;
	}

	// Copy Constructor
	Camera::Camera(const Camera &inCamera)
		: Asset(inCamera)
	{
		copy(inCamera);
	}

	Camera& Camera::operator=( const Camera& rhs )
	{
		Asset::operator=(rhs);
		copy(rhs);
		return *this;
	}

	Camera* Camera::clone() const
	{
		return new Camera(*this);
	}

	void Camera::copy(const Camera &inCamera)
	{
		Asset::copy(inCamera);
		this->m_FOV = inCamera.m_FOV;
		this->m_FOVType = inCamera.m_FOVType;
		this->m_NearRange = inCamera.m_NearRange;
		this->m_FarRange = inCamera.m_FarRange;
		this->m_ClipManually = inCamera.m_ClipManually;
		this->m_NearClip = inCamera.m_NearClip;
		this->m_FarClip = inCamera.m_FarClip;
		this->m_TargetDistance = inCamera.m_TargetDistance;
	}

	// Destructor
	Camera::~Camera()
	{
	}

	float Camera::getFOV()
	{
		return this->m_FOV;
	}

	int Camera::setFOV(float fov)
	{
		int status = -1;
		this->m_FOV = fov;
		return status;
	}

	int Camera::getFOVType()
	{
		return this->m_FOVType;
	}

	int Camera::setFOVType(int type)
	{
		int status = -1;
		this->m_FOVType = type;
		return status;
	}

	float Camera::getNearRange()
	{
		return this->m_NearRange;
	}

	int Camera::setNearRange(float range)
	{
		int status = -1;
		this->m_NearRange = range;
		return status;
	}

	float Camera::getFarRange()
	{
		return this->m_FarRange;
	}

	int Camera::setFarRange(float range)
	{
		int status = -1;
		this->m_FarRange = range;
		return status;
	}

	bool Camera::isClipManually()
	{
		return this->m_ClipManually;
	}

	int Camera::setClipManually(bool clip)
	{
		int status = -1;
		this->m_ClipManually = clip;
		return status;
	}

	float Camera::getNearClip()
	{
		return this->m_NearClip;
	}

	int Camera::setNearClip(float clip)
	{
		int status = -1;
		this->m_NearClip = clip;
		return status;
	}

	float Camera::getFarClip()
	{
		return this->m_FarClip;
	}

	int Camera::setFarClip(float clip)
	{
		int status = -1;
		this->m_FarClip = clip;
		return status;
	}

	float Camera::getTargetDistance()
	{
		return this->m_TargetDistance;
	}

	int Camera::setTargetDistance(float distance)
	{
		int status = -1;
		this->m_TargetDistance = distance;
		return status;
	}
}