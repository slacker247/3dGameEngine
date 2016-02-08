#include <map>

#include "String.h"
#include "Matrix.h"
#include "LoadXML.h"
#include "LoadModel.h"
#include "Asset.h"
#include "Camera.h"
#include "Model.h"
#include "Material.h"
#include "Texture.h"
#include "Light.h"

#pragma once

using namespace assets;

namespace loaders
{
	class LoadAsset
	{
		static String STR_NAME; // newString("Name")
		static String STR_GROUP_NAME; // newString("Group_Name")
		static String STR_MATRIX; // newString("Matrix")
		static String STR_OFFSET_MATRIX; // newString("Offset_Matrix")
		static String STR_ANIMATION; // newString("Animation")
		static String STR_START_FRAME; // newString("Start_Frame")
		static String STR_END_FRAME; // newString("End_Frame")
		static String STR_FRAME; // newString("Frame")
		static String STR_FRAME_NUMBER; // newString("Frame_Number")
		static String STR_TYPE; // newString("Type")
		static String STR_ENABLED; // newString("Enabled")
		static String STR_COLOR; // newString("Color")
		static String STR_MULTIPLIER; // newString("Multiplier")
		static String STR_CONTRAST; // newString("Contrast")
		static String STR_SOFTEN_DIFFUSE_EDGE; // newString("Soften_Diffuse_Edge")
		static String STR_AFFECT_DIFFUSE; // newString("Affect_Diffuse")
		static String STR_AFFECT_SPECULAR; // newString("Affect_Specular")
		static String STR_AMBIENT_ONLY; // newString("Ambient_Only")
		static String STR_PROJECTOR; // newString("Projector")
		static String STR_PROJECTOR_MAP; // newString("Projector_Map")
		static String STR_NEAR_ATTEN_START; // newString("Near_Atten_Start")
		static String STR_NEAR_ATTEN_END; // newString("Near_Atten_End")
		static String STR_USE_NEAR_ATTEN; // newString("Use_Near_Atten")
		static String STR_FAR_ATTEN_START; // newString("Far_Atten_Start")
		static String STR_FAR_ATTEN_END; // newString("Far_Atten_End")
		static String STR_USE_FAR_ATTEN; // newString("Use_Far_Atten")
		static String STR_ATTEN_DECAY; // newString("Atten_Decay")
		static String STR_DECAY_RADIUS; // newString("Decay_Radius")
		static String STR_CAST_SHADOWS; // newString("Cast_Shadows")
		static String STR_SHADER_TYPE; // newString("Shader_Type")
		static String STR_TWO_SIDED; // newString("Two_Sided")
		static String STR_FACETED; // newString("Faceted")
		static String STR_SOFTEN; // newString("Soften")
		static String STR_INDEX_OF_REFRACTION; // newString("Index_Of_Refraction")
		static String STR_AMBIENT; // newString("Ambient")
		static String STR_AMBIENT_MAP; // newString("Ambient_Map")
		static String STR_AMBIENT_MAP_AMOUNT; // newString("Ambient_Map_Amount")
		static String STR_DIFFUSE; // newString("Diffuse")
		static String STR_DIFFUSE_MAP; // newString("Diffuse_Map")
		static String STR_DIFFUSE_MAP_AMOUNT; // newString("Diffuse_Map_Amount")
		static String STR_SPECULAR; // newString("Specular")
		static String STR_SPECULAR_MAP; // newString("Specular_Map")
		static String STR_SPECULAR_MAP_AMOUNT; // newString("Specular_Map_Amount")
		static String STR_SPECULAR_LEVEL; // newString("Specular_Level")
		static String STR_GLOSSINESS; // newString("Glossiness")
		static String STR_GLOSSINESS_MAP; // newString("Glossiness_Map")
		static String STR_GLOSSINESS_MAP_AMOUNT; // newString("Glossiness_Map_Amount")
		static String STR_SELF_ILLUM_AMOUNT; // newString("Self_Illum_Amount")
		static String STR_SELF_ILLUM_COLOR; // newString("Self_Illum_Color")
		static String STR_SELF_ILLUM_MAP; // newString("Self_Illum_Map")
		static String STR_SELF_ILLUM_MAP_AMOUNT; // newString("Self_Illum_Map_Amount")
		static String STR_OPACITY; // newString("Opacity")
		static String STR_OPACITY_TYPE; // newString("Opacity_Type")
		static String STR_OPACITY_FALL_OFF; // newString("Opacity_Fall_Off")
		static String STR_OPACITY_FALL_OFF_TYPE; // newString("Opacity_Fall_Off_Type")
		static String STR_OPACITY_MAP; // newString("Opacity_Map")
		static String STR_OPACITY_MAP_AMOUNT; // newString("Opacity_Map_Amount")
		static String STR_FILTER_MAP; // newString("Filter_Map")
		static String STR_FILTER_MAP_AMOUNT; // newString("Filter_Map_Amount")
		static String STR_BUMP_MAP; // newString("Bump_Map")
		static String STR_BUMP_MAP_AMOUNT; // newString("Bump_Map_Amount")
		static String STR_REFLECTION_LEVEL; // newString("Reflection_Level")
		static String STR_REFLECTION_MAP; // newString("Reflection_Map")
		static String STR_REFLECTION_MAP_AMOUNT; // newString("Reflection_Map_Amount")
		static String STR_REFRACTION_MAP; // newString("Refraction_Map")
		static String STR_REFRACTION_MAP_AMOUNT; // newString("Refraction_Map_Amount")
		static String STR_DISPLACEMENT_MAP; // newString("Displacement_Map")
		static String STR_DISPLACEMENT_MAP_AMOUNT; // newString("Displacement_Map_Amount")
		static String STR_FILE_NAME; // newString("FileName")
		static String STR_START_TIME; // newString("StartTime")
		static String STR_PLAYBACK_RATE; // newString("PlaybackRate")
		static String STR_END_CONDITION; // newString("EndCondition")
		static String STR_FOV; // newString("FOV")
		static String STR_NEAR_RANGE; // newString("Near_Range")
		static String STR_FAR_RANGE; // newString("Far_Range")
		static String STR_NEAR_CLIP; // newString("Near_Clip")
		static String STR_FAR_CLIP; // newString("Far_Clip")
		static String STR_TARGET_DISTANCE; // newString("Target_Distance")
		static String STR_FOV_TYPE; // newString("FOV_Type")
		static String STR_CLIP_MANUALLY; // newString("Clip_Manually")
		static String STR_TRANSFORM; // newString("Transform")
		static String STR_ROW[4]; // sprintf(row, "r%d", n); n= 1 to 4
		static String STR_P[4]; // sprintf(point, "p%d", n); n= 1 to 4
		static String STR_X; // newString("x")
		static String STR_Y; // newString("y")
		static String STR_Z; // newString("z")
		static String STR_A; // newString("a")
		static String STR_POSITION; // newString("Position")
		static String STR_SCALE; // newString("Scale")
		static String STR_ROTATION; // newString("Rotation")
		static String STR_CAMERA; // newString("camera")
		static String STR_MODEL; // newString("model")
		static String STR_MATERIAL; // newString("material")
		static String STR_TEXTURE; // newString("texture")
		static String STR_LIGHT; // newString("light")
		static String STR_GROUP; // newString("group")
		static String STR_R; // newString("r")
		static String STR_G; // newString("g")
		static String STR_B; // newString("b")

	protected:
		String m_FileName;
		String m_Type;
		Asset* m_Asset;
	public:
		bool m_IsFinished;
		// Default Constructor
		LoadAsset();
		// Copy Constructor
		LoadAsset(const LoadAsset &inLoadAsset);
		LoadAsset& operator=( const LoadAsset& rhs );
	    virtual LoadAsset* clone() const;
		void copy(const LoadAsset &inLoadAsset);
		// Destructor
		~LoadAsset();

		int setFileName(String* fileName);
		int setType(String* type);
		int setAsset(Asset* asset);
		Asset* getAsset();
		
		static void __cdecl asyncLoadAsset(void* This);
		static int loadAsset(String* fileName, String* type, Asset* asset);
		static math::Matrix* loadMatrix(loaders::LoadXML* lXML, String& matrixName, DOMElement* tag = NULL);
		static Animation* loadAnimation(Animation* anim, loaders::LoadXML* lXML);

	protected:
		static void getPoints(math::Matrix* matrix, DOMElement* matrixList, loaders::LoadXML* lXML, String& point);
		static int getColor(float* color, DOMElement* colorNode, loaders::LoadXML* lXML);
		static int loadCamera(Camera* camera, loaders::LoadXML* lXML);
		static int loadMaterial(Material* material, loaders::LoadXML* lXML);
		static int loadTexture(Texture* texture, loaders::LoadXML* lXML);
		static int loadLight(Light* light, loaders::LoadXML* lXML);
	};
}