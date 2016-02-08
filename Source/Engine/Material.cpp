#include "Material.h"

namespace assets
{
	// Default Constructor
	Material::Material()
	{
		this->m_ShaderType = 0;
		this->m_TwoSided = false;
		this->m_Faceted = false;
		this->m_Soften = 0;
		this->m_IndexOfRefraction = 0;
		int i = 0;
		for(i = 0; i < 3; i++)
			this->m_AmbientColor[i] = 0;
		this->m_AmbientColor[3] = 1;
		this->m_AmbientMap = newString("");
		this->m_AmbientMapAmount = 0;
		for(i = 0; i < 3; i++)
			this->m_DiffuseColor[i] = 0;
		this->m_DiffuseColor[3] = 1;
		this->m_DiffuseMap = newString("");
		this->m_DiffuseMapAmount = 0;
		for(i = 0; i < 3; i++)
			this->m_SpecularColor[i] = 0;
		this->m_SpecularColor[3] = 1;
		this->m_SpecularMap = newString("");
		this->m_SpecularMapAmount = 0;
		for(i = 0; i < 3; i++)
			this->m_SelfIllumColor[i] = 0;
		this->m_SelfIllumColor[3] = 1;
		this->m_SelfIllumAmount = 1;
		this->m_SelfIllumMap = newString("");
		this->m_SelfIllumMapAmount = 0;
		this->m_SpecularLevel = 1;
		this->m_Glossiness = 0;
		this->m_GlossinessMap = newString("");
		this->m_GlossinessMapAmount = 0;
		this->m_Opacity = 1;
		this->m_OpacityType = 0;
		this->m_OpacityFallOff = 0;
		this->m_OpacityFallOffType = 0;
		this->m_OpacityMap = newString("");
		this->m_OpacityMapAmount = 0;
		this->m_FilterMap = newString("");
		this->m_FilterMapAmount = 0;
		this->m_BumpMap = newString("");
		this->m_BumpMapAmount = 0;
		this->m_ReflectionLevel = 0;
		this->m_ReflectionMap = newString("");
		this->m_ReflectionMapAmount = 0;
		this->m_RefractionMap = newString("");
		this->m_RefractionMapAmount = 0;
		this->m_DisplacementMap = newString("");
		this->m_DisplacementMapAmount = 0;

		this->m_Type = Asset::MATERIAL;
	}

	// Copy Constructor
	Material::Material(const Material &inMaterial)
		: Asset(inMaterial)
	{
		copy(inMaterial);
	}

	Material& Material::operator=( const Material& rhs )
	{
		Asset::operator=(rhs);
		copy(rhs);
		return *this;
	}

	Material* Material::clone() const
	{
		return new Material(*this);
	}

	void Material::copy(const Material &inMaterial)
	{
		Asset::copy(inMaterial);
		this->m_ShaderType = inMaterial.m_ShaderType;
		this->m_TwoSided = inMaterial.m_TwoSided;
		this->m_Faceted = inMaterial.m_Faceted;
		this->m_Soften = inMaterial.m_Soften;
		this->m_IndexOfRefraction = inMaterial.m_IndexOfRefraction;
		int i = 0;
		for(i = 0; i < 4; i++)
			this->m_AmbientColor[i] = inMaterial.m_AmbientColor[i];
		this->m_AmbientMap = inMaterial.m_AmbientMap;
		this->m_AmbientMapAmount = inMaterial.m_AmbientMapAmount;
		for(i = 0; i < 4; i++)
			this->m_DiffuseColor[i] = inMaterial.m_DiffuseColor[i];
		this->m_DiffuseMap = inMaterial.m_DiffuseMap;
		this->m_DiffuseMapAmount = inMaterial.m_DiffuseMapAmount;
		for(i = 0; i < 4; i++)
			this->m_SpecularColor[i] = inMaterial.m_SpecularColor[i];
		this->m_SpecularMap = inMaterial.m_SpecularMap;
		this->m_SpecularMapAmount = inMaterial.m_SpecularMapAmount;
		for(i = 0; i < 4; i++)
			this->m_SelfIllumColor[i] = inMaterial.m_SelfIllumColor[i];
		this->m_SelfIllumAmount = inMaterial.m_SelfIllumAmount;
		this->m_SelfIllumMap = inMaterial.m_SelfIllumMap;
		this->m_SelfIllumMapAmount = inMaterial.m_SelfIllumMapAmount;
		this->m_SpecularLevel = inMaterial.m_SpecularLevel;
		this->m_Glossiness = inMaterial.m_Glossiness;
		this->m_GlossinessMap = inMaterial.m_GlossinessMap;
		this->m_GlossinessMapAmount = inMaterial.m_GlossinessMapAmount;
		this->m_Opacity = inMaterial.m_Opacity;
		this->m_OpacityType = inMaterial.m_OpacityType;
		this->m_OpacityFallOff = inMaterial.m_OpacityFallOff;
		this->m_OpacityFallOffType = inMaterial.m_OpacityFallOffType;
		this->m_OpacityMap = inMaterial.m_OpacityMap;
		this->m_OpacityMapAmount = inMaterial.m_OpacityMapAmount;
		this->m_FilterMap = inMaterial.m_FilterMap;
		this->m_FilterMapAmount = inMaterial.m_FilterMapAmount;
		this->m_BumpMap = inMaterial.m_BumpMap;
		this->m_BumpMapAmount = inMaterial.m_BumpMapAmount;
		this->m_ReflectionLevel = inMaterial.m_ReflectionLevel;
		this->m_ReflectionMap = inMaterial.m_ReflectionMap;
		this->m_ReflectionMapAmount = inMaterial.m_ReflectionMapAmount;
		this->m_RefractionMap = inMaterial.m_RefractionMap;
		this->m_RefractionMapAmount = inMaterial.m_RefractionMapAmount;
		this->m_DisplacementMap = inMaterial.m_DisplacementMap;
		this->m_DisplacementMapAmount = inMaterial.m_DisplacementMapAmount;
	}

	// Destructor
	Material::~Material()
	{
	}

	int Material::getShaderType()
	{
		return this->m_ShaderType;
	}

	int Material::setShaderType(int type)
	{
		int status = -1;
		this->m_ShaderType = type;
		return status;
	}

	bool Material::isTwoSided()
	{
		return this->m_TwoSided;
	}

	int Material::setTwoSided(bool state)
	{
		int status = -1;
		this->m_TwoSided = state;
		return status;
	}

	bool Material::isFaceted()
	{
		return this->m_Faceted;
	}

	int Material::setFaceted(bool state)
	{
		int status = -1;
		this->m_Faceted = state;
		return status;
	}

	float Material::getSoften()
	{
		return this->m_Soften;
	}

	int Material::setSoften(float value)
	{
		int status = -1;
		this->m_Soften = value;
		return status;
	}

	float Material::getIndexOfRefraction()
	{
		return this->m_IndexOfRefraction;
	}

	int Material::setIndexOfRefraction(float value)
	{
		int status = -1;
		this->m_IndexOfRefraction = value;
		return status;
	}

	float* Material::getAmbientColor()
	{
		return this->m_AmbientColor;
	}

	int Material::setAmbientColor(float r, float g, float b, float a)
	{
		int status = -1;
		this->m_AmbientColor[0] = r;
		this->m_AmbientColor[1] = g;
		this->m_AmbientColor[2] = b;
		this->m_AmbientColor[3] = a;
		return status;
	}

	String* Material::getAmbientMap()
	{
		return &(this->m_AmbientMap);
	}

	int Material::setAmbientMap(String& name)
	{
		int status = -1;
		this->m_AmbientMap = name;
		return status;
	}

	float Material::getAmbientMapAmount()
	{
		return this->m_AmbientMapAmount;
	}

	int Material::setAmbientMapAmount(float amount)
	{
		int status = -1;
		this->m_AmbientMapAmount = amount;
		return status;
	}

	float* Material::getDiffuseColor()
	{
		return this->m_DiffuseColor;
	}

	int Material::setDiffuseColor(float r, float g, float b, float a)
	{
		int status = -1;
		this->m_DiffuseColor[0] = r;
		this->m_DiffuseColor[1] = g;
		this->m_DiffuseColor[2] = b;
		this->m_DiffuseColor[3] = a;
		return status;
	}

	String* Material::getDiffuseMap()
	{
		return &(this->m_DiffuseMap);
	}

	int Material::setDiffuseMap(String& name)
	{
		int status = -1;
		this->m_DiffuseMap = name;
		return status;
	}

	float Material::getDiffuseMapAmount()
	{
		return this->m_DiffuseMapAmount;
	}

	int Material::setDiffuseMapAmount(float amount)
	{
		int status = -1;
		this->m_DiffuseMapAmount = amount;
		return status;
	}

	float* Material::getSpecularColor()
	{
		return this->m_SpecularColor;
	}

	int Material::setSpecularColor(float r, float g, float b, float a)
	{
		int status = -1;
		this->m_SpecularColor[0] = r;
		this->m_SpecularColor[1] = g;
		this->m_SpecularColor[2] = b;
		this->m_SpecularColor[3] = a;
		return status;
	}

	String* Material::getSpecularMap()
	{
		return &(this->m_SpecularMap);
	}

	int Material::setSpecularMap(String& name)
	{
		int status = -1;
		this->m_SpecularMap = name;
		return status;
	}

	float Material::getSpecularMapAmount()
	{
		return this->m_SpecularMapAmount;
	}

	int Material::setSpecularMapAmount(float amount)
	{
		int status = -1;
		this->m_SpecularMapAmount = amount;
		return status;
	}

	// Specular level is a simple multiplication with the specular color. 
	float Material::getSpecularLevel()
	{
		return this->m_SpecularLevel;
	}

	int Material::setSpecularLevel(float value)
	{
		int status = -1;
		this->m_SpecularLevel = value;
		return status;
	}

	float Material::getGlossiness()
	{
		return this->m_Glossiness;
	}

	int Material::setGlossiness(float value)
	{
		int status = -1;
		this->m_Glossiness = value;
		return status;
	}

	String* Material::getGlossinessMap()
	{
		return &(this->m_GlossinessMap);
	}

	int Material::setGlossinessMap(String& name)
	{
		int status = -1;
		this->m_GlossinessMap = name;
		return status;
	}

	float Material::getGlossinessMapAmount()
	{
		return this->m_GlossinessMapAmount;
	}

	int Material::setGlossinessMapAmount(float amount)
	{
		int status = -1;
		this->m_GlossinessMapAmount = amount;
		return status;
	}

	float Material::getSelfIllumAmount()
	{
		return this->m_SelfIllumAmount;
	}

	int Material::setSelfIllumAmount(float value)
	{
		int status = -1;
		this->m_SelfIllumAmount = value;
		return status;
	}

	float* Material::getSelfIllumColor()
	{
		return this->m_SelfIllumColor;
	}

	int Material::setSelfIllumColor(float r, float g, float b, float a)
	{
		int status = -1;
		this->m_SelfIllumColor[0] = r;
		this->m_SelfIllumColor[1] = g;
		this->m_SelfIllumColor[2] = b;
		this->m_SelfIllumColor[3] = a;
		return status;
	}
	
	String* Material::getSelfIllumMap()
	{
		return &(this->m_SelfIllumMap);
	}

	int Material::setSelfIllumMap(String& name)
	{
		int status = -1;
		this->m_SelfIllumMap = name;
		return status;
	}

	float Material::getSelfIllumMapAmount()
	{
		return this->m_SelfIllumMapAmount;
	}

	int Material::setSelfIllumMapAmount(float amount)
	{
		int status = -1;
		this->m_SelfIllumMapAmount = amount;
		return status;
	}

	float Material::getOpacity()
	{
		return this->m_Opacity;
	}

	int Material::setOpacity(float value)
	{
		int status = -1;
		this->m_Opacity = value;
		return status;
	}

	int Material::getOpacityType()
	{
		return this->m_OpacityType;
	}

	int Material::setOpacityType(int type)
	{
		int status = -1;
		this->m_OpacityType = type;
		return status;
	}

	float Material::getOpacityFallOff()
	{
		return this->m_OpacityFallOff;
	}

	int Material::setOpacityFallOff(float value)
	{
		int status = -1;
		this->m_OpacityFallOff = value;
		return status;
	}

	int Material::getOpacityFallOffType()
	{
		return this->m_OpacityFallOffType;
	}

	int Material::setOpacityFallOffType(int type)
	{
		int status = -1;
		this->m_OpacityFallOffType = type;
		return status;
	}

	String* Material::getOpacityMap()
	{
		return &(this->m_OpacityMap);
	}

	int Material::setOpacityMap(String& name)
	{
		int status = -1;
		this->m_OpacityMap = name;
		return status;
	}

	float Material::getOpacityMapAmount()
	{
		return this->m_OpacityMapAmount;
	}

	int Material::setOpacityMapAmount(float amount)
	{
		int status = -1;
		this->m_OpacityMapAmount = amount;
		return status;
	}

	String* Material::getFilterMap()
	{
		return &(this->m_FilterMap);
	}

	int Material::setFilterMap(String& name)
	{
		int status = -1;
		this->m_FilterMap = name;
		return status;
	}

	float Material::getFilterMapAmount()
	{
		return this->m_FilterMapAmount;
	}

	int Material::setFilterMapAmount(float amount)
	{
		int status = -1;
		this->m_FilterMapAmount = amount;
		return status;
	}

	String* Material::getBumpMap()
	{
		return &(this->m_BumpMap);
	}

	int Material::setBumpMap(String& name)
	{
		int status = -1;
		this->m_BumpMap = name;
		return status;
	}

	float Material::getBumpMapAmount()
	{
		return this->m_BumpMapAmount;
	}

	int Material::setBumpMapAmount(float amount)
	{
		int status = -1;
		this->m_BumpMapAmount = amount;
		return status;
	}

	float Material::getReflectionLevel()
	{
		return this->m_ReflectionLevel;
	}

	int Material::setReflectionLevel(float level)
	{
		int status = -1;
		this->m_ReflectionLevel = level;
		return status;
	}

	String* Material::getReflectionMap()
	{
		return &(this->m_ReflectionMap);
	}

	int Material::setReflectionMap(String& name)
	{
		int status = -1;
		this->m_ReflectionMap = name;
		return status;
	}

	float Material::getReflectionMapAmount()
	{
		return this->m_ReflectionMapAmount;
	}

	int Material::setReflectionMapAmount(float amount)
	{
		int status = -1;
		this->m_ReflectionMapAmount = amount;
		return status;
	}

	String* Material::getRefractionMap()
	{
		return &(this->m_RefractionMap);
	}

	int Material::setRefractionMap(String& name)
	{
		int status = -1;
		this->m_RefractionMap = name;
		return status;
	}

	float Material::getRefractionMapAmount()
	{
		return this->m_RefractionMapAmount;
	}

	int Material::setRefractionMapAmount(float amount)
	{
		int status = -1;
		this->m_RefractionMapAmount = amount;
		return status;
	}

	String* Material::getDisplacementMap()
	{
		return &(this->m_DisplacementMap);
	}

	int Material::setDisplacementMap(String& name)
	{
		int status = -1;
		this->m_DisplacementMap = name;
		return status;
	}

	float Material::getDisplacementMapAmount()
	{
		return this->m_DisplacementMapAmount;
	}

	int Material::setDisplacementMapAmount(float amount)
	{
		int status = -1;
		this->m_DisplacementMapAmount = amount;
		return status;
	}
}