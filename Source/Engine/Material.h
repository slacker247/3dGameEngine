#include "Asset.h"

#pragma once

namespace assets
{
	class Material : public Asset
	{
	protected:
		int m_ShaderType;
		bool m_TwoSided;
		bool m_Faceted;
		float m_Soften;
		float m_IndexOfRefraction;
		float m_AmbientColor[4];
		String m_AmbientMap;
		float m_AmbientMapAmount;
		float m_DiffuseColor[4];
		String m_DiffuseMap;
		float m_DiffuseMapAmount;
		float m_SpecularColor[4];
		String m_SpecularMap;
		float m_SpecularMapAmount;
		float m_SpecularLevel;
		float m_Glossiness;
		String m_GlossinessMap;
		float m_GlossinessMapAmount;
		float m_SelfIllumAmount;
		float m_SelfIllumColor[4];
		String m_SelfIllumMap;
		float m_SelfIllumMapAmount;
		float m_Opacity;
		int m_OpacityType;
		float m_OpacityFallOff;
		int m_OpacityFallOffType;
		String m_OpacityMap;
		float m_OpacityMapAmount;
		String m_FilterMap;
		float m_FilterMapAmount;
		String m_BumpMap;
		float m_BumpMapAmount;
		float m_ReflectionLevel;
		String m_ReflectionMap;
		float m_ReflectionMapAmount;
		String m_RefractionMap;
		float m_RefractionMapAmount;
		String m_DisplacementMap;
		float m_DisplacementMapAmount;

	public:
		// Default Constructor
		Material();
		// Copy Constructor
		Material(const Material &inMaterial);
		virtual Material& operator=( const Material& rhs );
	    virtual Material* clone() const;
		virtual void copy(const Material &inMaterial);
		// Destructor
		~Material();

		int getShaderType();
		int setShaderType(int type);
		bool isTwoSided();
		int setTwoSided(bool state);
		bool isFaceted();
		int setFaceted(bool state);
		float getSoften();
		int setSoften(float value);
		float getIndexOfRefraction();
		int setIndexOfRefraction(float value);
		float* getAmbientColor();
		int setAmbientColor(float r, float g, float b, float a);
		String* getAmbientMap();
		int setAmbientMap(String& name);
		float getAmbientMapAmount();
		int setAmbientMapAmount(float amount);
		float* getDiffuseColor();
		int setDiffuseColor(float r, float g, float b, float a);
		String* getDiffuseMap();
		int setDiffuseMap(String& name);
		float getDiffuseMapAmount();
		int setDiffuseMapAmount(float amount);
		float* getSpecularColor();
		int setSpecularColor(float r, float g, float b, float a);
		String* getSpecularMap();
		int setSpecularMap(String& name);
		float getSpecularMapAmount();
		int setSpecularMapAmount(float amount);
		float getSpecularLevel();
		int setSpecularLevel(float value);
		float getGlossiness();
		int setGlossiness(float value);
		String* getGlossinessMap();
		int setGlossinessMap(String& name);
		float getGlossinessMapAmount();
		int setGlossinessMapAmount(float amount);
		float getSelfIllumAmount();
		int setSelfIllumAmount(float value);
		float* getSelfIllumColor();
		int setSelfIllumColor(float r, float g, float b, float a);
		String* getSelfIllumMap();
		int setSelfIllumMap(String& name);
		float getSelfIllumMapAmount();
		int setSelfIllumMapAmount(float amount);
		float getOpacity();
		int setOpacity(float value);
		int getOpacityType();
		int setOpacityType(int type);
		float getOpacityFallOff();
		int setOpacityFallOff(float value);
		int getOpacityFallOffType();
		int setOpacityFallOffType(int type);
		String* getOpacityMap();
		int setOpacityMap(String& name);
		float getOpacityMapAmount();
		int setOpacityMapAmount(float amount);
		String* getFilterMap();
		int setFilterMap(String& name);
		float getFilterMapAmount();
		int setFilterMapAmount(float amount);
		String* getBumpMap();
		int setBumpMap(String& name);
		float getBumpMapAmount();
		int setBumpMapAmount(float amount);
		float getReflectionLevel();
		int setReflectionLevel(float level);
		String* getReflectionMap();
		int setReflectionMap(String& name);
		float getReflectionMapAmount();
		int setReflectionMapAmount(float amount);
		String* getRefractionMap();
		int setRefractionMap(String& name);
		float getRefractionMapAmount();
		int setRefractionMapAmount(float amount);
		String* getDisplacementMap();
		int setDisplacementMap(String& name);
		float getDisplacementMapAmount();
		int setDisplacementMapAmount(float amount);
	};
}