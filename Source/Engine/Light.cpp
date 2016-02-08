#include "Light.h"

namespace assets
{
	unsigned int Light::g_Id = 0;

	// Default Constructor
	Light::Light()
	{
		this->m_Id = Light::g_Id;
		Light::g_Id++;

		this->m_Type = Asset::LIGHT;

		m_LightType = newString("");
		m_Enabled = false;
		for(int i = 0; i < 3; i++)	
			m_Color[i] = 0;
		m_Color[4] = 1;
		m_Multiplier = 1;
		m_Contrast = 0;
		m_SoftenDiffuseEdge = 0;
		m_AffectDiffuse = false;
		m_AffectSpecular = false;
		m_AmbientOnly = false;
		m_Projector = false;
		m_ProjectorMap = newString("");
		m_NearAttenStart = 0;
		m_NearAttenEnd = 0;
		m_UseNearAtten = false;
		m_FarAttenStart = 0;
		m_FarAttenEnd = 0;
		m_UseFarAtten = false;
		m_AttenDecay = 0;
		m_DecayRadius = 0;
		m_CastShadows = false;
	}

	// Copy Constructor
	Light::Light(const Light &inLight)
		: Asset(inLight)
	{
		copy(inLight);
	}

	Light& Light::operator=( const Light& rhs )
	{
		copy(rhs);
		return *this;
	}

	Light* Light::clone() const
	{
		return new Light(*this);
	}

	void Light::copy(const Light &inLight)
	{
		Asset::copy(inLight);
		this->m_Id = inLight.m_Id;
		this->m_LightType = inLight.m_LightType;
		this->m_Enabled = inLight.m_Enabled;
		for(int i = 0; i < 4; i++)
			this->m_Color[i] = inLight.m_Color[i];
		this->m_Multiplier = inLight.m_Multiplier;
		this->m_Contrast = inLight.m_Contrast;
		this->m_SoftenDiffuseEdge = inLight.m_SoftenDiffuseEdge;
		this->m_AffectDiffuse = inLight.m_AffectDiffuse;
		this->m_AffectSpecular = inLight.m_AffectSpecular;
		this->m_AmbientOnly = inLight.m_AmbientOnly;
		this->m_Projector = inLight.m_Projector;
		this->m_ProjectorMap = inLight.m_ProjectorMap;
		this->m_NearAttenStart = inLight.m_NearAttenStart;
		this->m_NearAttenEnd = inLight.m_NearAttenEnd;
		this->m_UseNearAtten = inLight.m_UseNearAtten;
		this->m_FarAttenStart = inLight.m_FarAttenStart;
		this->m_FarAttenEnd = inLight.m_FarAttenEnd;
		this->m_UseFarAtten = inLight.m_UseFarAtten;
		this->m_AttenDecay = inLight.m_AttenDecay;
		this->m_DecayRadius = inLight.m_DecayRadius;
		this->m_CastShadows = inLight.m_CastShadows;
	}

	// Destructor
	Light::~Light()
	{
	}
	
	unsigned int Light::getId(int offset)
	{
		return this->m_Id + offset;
	}

	String* Light::getLightType()
	{
		String* ptr = NULL;
		if(this->m_LightType.size() == 0)
		{
			this->m_LightType = newString("");
		}
		ptr = &(this->m_LightType);
		return ptr;
	}

	int Light::setLightType(String& type)
	{
		int status = -1;
		if(type.length() > 0)
		{
			this->m_LightType = type;
			status = 0;
		}
		return status;
	}

	bool Light::isEnabled()
	{
		return this->m_Enabled;
	}

	int Light::setEnabled(bool value)
	{
		int status = -1;
		this->m_Enabled = value;
		return status;
	}

	float* Light::getColor()
	{
		return this->m_Color;
	}

	int Light::setColor(float r, float g, float b, float a)
	{
		int status = -1;
		this->m_Color[0] = r;
		this->m_Color[1] = g;
		this->m_Color[2] = b;
		this->m_Color[3] = a;
		return status;
	}

	float Light::getMultiplier()
	{
		return this->m_Multiplier;
	}

	int Light::setMultiplier(float multi)
	{
		int status = -1;
		this->m_Multiplier = multi;
		return status;
	}

	float Light::getContrast()
	{
		return this->m_Contrast;
	}

	int Light::setContrast(float contrast)
	{
		int status = -1;
		this->m_Contrast = contrast;
		return status;
	}

	float Light::getSoftenDiffuseEdge()
	{
		return this->m_SoftenDiffuseEdge;
	}

	int Light::setSoftenDiffuseEdge(float softness)
	{
		int status = -1;
		this->m_SoftenDiffuseEdge = softness;
		return status;
	}

	bool Light::isAffectDiffuse()
	{
		return this->m_AffectDiffuse;
	}

	int Light::setAffectDiffuse(bool value)
	{
		int status = -1;
		this->m_AffectDiffuse = value;
		return status;
	}

	bool Light::isAffectSpecular()
	{
		return this->m_AffectSpecular;
	}

	int Light::setAffectSpecular(bool value)
	{
		int status = -1;
		this->m_AffectSpecular = value;
		return status;
	}

	bool Light::isAmbientOnly()
	{
		return this->m_AmbientOnly;
	}

	int Light::setAmbientOnly(bool value)
	{
		int status = -1;
		this->m_AmbientOnly = value;
		return status;
	}

	bool Light::isProjector()
	{
		return this->m_Projector;
	}

	int Light::setProjector(bool value)
	{
		int status = -1;
		this->m_Projector = value;
		return status;
	}

	String* Light::getProjectorMap()
	{
		return &(this->m_ProjectorMap);
	}

	int Light::setProjectorMap(String& file)
	{
		int status = -1;
		if(file.length() > 0)
		{
			this->m_ProjectorMap = file;
			status = 0;
		}
		return status;
	}

	float Light::getNearAttenStart()
	{
		return this->m_NearAttenStart;
	}

	int Light::setNearAttenStart(float start)
	{
		int status = -1;
		this->m_NearAttenStart = start;
		return status;
	}

	float Light::getNearAttenEnd()
	{
		return this->m_NearAttenEnd;
	}

	int Light::setNearAttenEnd(float end)
	{
		int status = -1;
		this->m_NearAttenEnd = end;
		return status;
	}

	bool Light::useNearAtten()
	{
		return this->m_UseNearAtten;
	}

	int Light::setNearAtten(bool use)
	{
		int status = -1;
		this->m_UseNearAtten = use;
		return status;
	}

	float Light::getFarAttenStart()
	{
		return this->m_FarAttenStart;
	}

	int Light::setFarAttenStart(float start)
	{
		int status = -1;
		this->m_FarAttenStart = start;
		return status;
	}

	float Light::getFarAttenEnd()
	{
		return this->m_FarAttenEnd;
	}

	int Light::setFarAttenEnd(float end)
	{
		int status = -1;
		this->m_FarAttenEnd = end;
		return status;
	}

	bool Light::useFarAtten()
	{
		return this->m_UseFarAtten;
	}

	int Light::setFarAtten(bool use)
	{
		int status = -1;
		this->m_UseFarAtten = use;
		return status;
	}

	float Light::getAttenDecay()
	{
		return this->m_AttenDecay;
	}

	int Light::setAttenDecay(float decay)
	{
		int status = -1;
		this->m_AttenDecay = decay;
		return status;
	}

	float Light::getDecayRadius()
	{
		return this->m_DecayRadius;
	}

	int Light::setDecayRadius(float radius)
	{
		int status = -1;
		this->m_DecayRadius = radius;
		return status;
	}

	bool Light::castShadows()
	{
		return this->m_CastShadows;
	}

	int Light::setCastShadows(bool shadows)
	{
		int status = -1;
		this->m_CastShadows = shadows;
		return status;
	}
}