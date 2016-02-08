#include "Asset.h"

#pragma once

namespace assets
{
	class Light : public Asset
	{
		static unsigned int g_Id ;
	protected:
		unsigned int m_Id;
		String m_LightType;
		bool m_Enabled;
		float m_Color[4];
		float m_Multiplier;
		float m_Contrast;
		float m_SoftenDiffuseEdge;
		bool m_AffectDiffuse;
		bool m_AffectSpecular;
		bool m_AmbientOnly;
		bool m_Projector;
		String m_ProjectorMap;
		float m_NearAttenStart;
		float m_NearAttenEnd;
		bool m_UseNearAtten;
		float m_FarAttenStart;
		float m_FarAttenEnd;
		bool m_UseFarAtten;
		float m_AttenDecay;
		float m_DecayRadius;
		bool m_CastShadows;
		/*
		<Shadow>
			<Generator>shadowMap:shadowMap</Generator>
			<Color>
				<r>0.0</r>
				<g>0.0</g>
				<b>0.0</b>
				<a>1.0</a>
			</Color>
			<Multiplier>1.0</Multiplier>
		</Shadow>
		*/
	public:
		// Default Constructor
		Light();
		// Copy Constructor
		Light(const Light &inLight);
		virtual Light& operator=( const Light& rhs );
	    virtual Light* clone() const;
		virtual void copy(const Light &inLight);
		// Destructor
		~Light();

		unsigned int getId(int offset = 0);
		String* getLightType();
		int setLightType(String& type);
		bool isEnabled();
		int setEnabled(bool value);
		float* getColor();
		int setColor(float r, float g, float b, float a);
		float getMultiplier();
		int setMultiplier(float multi);
		float getContrast();
		int setContrast(float contrast);
		float getSoftenDiffuseEdge();
		int setSoftenDiffuseEdge(float softness);
		bool isAffectDiffuse();
		int setAffectDiffuse(bool value);
		bool isAffectSpecular();
		int setAffectSpecular(bool value);
		bool isAmbientOnly();
		int setAmbientOnly(bool value);
		bool isProjector();
		int setProjector(bool value);
		String* getProjectorMap();
		int setProjectorMap(String& file);
		float getNearAttenStart();
		int setNearAttenStart(float start);
		float getNearAttenEnd();
		int setNearAttenEnd(float end);
		bool useNearAtten();
		int setNearAtten(bool use);
		float getFarAttenStart();
		int setFarAttenStart(float start);
		float getFarAttenEnd();
		int setFarAttenEnd(float end);
		bool useFarAtten();
		int setFarAtten(bool use);
		float getAttenDecay();
		int setAttenDecay(float decay);
		float getDecayRadius();
		int setDecayRadius(float radius);
		bool castShadows();
		int setCastShadows(bool shadows);
	};
}