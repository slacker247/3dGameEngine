#include "LoadAsset.h"

namespace loaders
{
	String LoadAsset::STR_NAME = newString("Name");
	String LoadAsset::STR_GROUP_NAME = newString("Group_Name");
	String LoadAsset::STR_MATRIX = newString("Matrix");
	String LoadAsset::STR_OFFSET_MATRIX = newString("Offset_Matrix");
	String LoadAsset::STR_ANIMATION = newString("Animation");
	String LoadAsset::STR_START_FRAME = newString("Start_Frame");
	String LoadAsset::STR_END_FRAME = newString("End_Frame");
	String LoadAsset::STR_FRAME = newString("Frame");
	String LoadAsset::STR_FRAME_NUMBER = newString("Frame_Number");
	String LoadAsset::STR_TYPE = newString("Type");
	String LoadAsset::STR_ENABLED = newString("Enabled");
	String LoadAsset::STR_COLOR = newString("Color");
	String LoadAsset::STR_MULTIPLIER = newString("Multiplier");
	String LoadAsset::STR_CONTRAST = newString("Contrast");
	String LoadAsset::STR_SOFTEN_DIFFUSE_EDGE = newString("Soften_Diffuse_Edge");
	String LoadAsset::STR_AFFECT_DIFFUSE = newString("Affect_Diffuse");
	String LoadAsset::STR_AFFECT_SPECULAR = newString("Affect_Specular");
	String LoadAsset::STR_AMBIENT_ONLY = newString("Ambient_Only");
	String LoadAsset::STR_PROJECTOR = newString("Projector");
	String LoadAsset::STR_PROJECTOR_MAP = newString("Projector_Map");
	String LoadAsset::STR_NEAR_ATTEN_START = newString("Near_Atten_Start");
	String LoadAsset::STR_NEAR_ATTEN_END = newString("Near_Atten_End");
	String LoadAsset::STR_USE_NEAR_ATTEN = newString("Use_Near_Atten");
	String LoadAsset::STR_FAR_ATTEN_START = newString("Far_Atten_Start");
	String LoadAsset::STR_FAR_ATTEN_END = newString("Far_Atten_End");
	String LoadAsset::STR_USE_FAR_ATTEN = newString("Use_Far_Atten");
	String LoadAsset::STR_ATTEN_DECAY = newString("Atten_Decay");
	String LoadAsset::STR_DECAY_RADIUS = newString("Decay_Radius");
	String LoadAsset::STR_CAST_SHADOWS = newString("Cast_Shadows");
	String LoadAsset::STR_SHADER_TYPE = newString("Shader_Type");
	String LoadAsset::STR_TWO_SIDED = newString("Two_Sided");
	String LoadAsset::STR_FACETED = newString("Faceted");
	String LoadAsset::STR_SOFTEN = newString("Soften");
	String LoadAsset::STR_INDEX_OF_REFRACTION = newString("Index_Of_Refraction");
	String LoadAsset::STR_AMBIENT = newString("Ambient");
	String LoadAsset::STR_AMBIENT_MAP = newString("Ambient_Map");
	String LoadAsset::STR_AMBIENT_MAP_AMOUNT = newString("Ambient_Map_Amount");
	String LoadAsset::STR_DIFFUSE = newString("Diffuse");
	String LoadAsset::STR_DIFFUSE_MAP = newString("Diffuse_Map");
	String LoadAsset::STR_DIFFUSE_MAP_AMOUNT = newString("Diffuse_Map_Amount");
	String LoadAsset::STR_SPECULAR = newString("Specular");
	String LoadAsset::STR_SPECULAR_MAP = newString("Specular_Map");
	String LoadAsset::STR_SPECULAR_MAP_AMOUNT = newString("Specular_Map_Amount");
	String LoadAsset::STR_SPECULAR_LEVEL = newString("Specular_Level");
	String LoadAsset::STR_GLOSSINESS = newString("Glossiness");
	String LoadAsset::STR_GLOSSINESS_MAP = newString("Glossiness_Map");
	String LoadAsset::STR_GLOSSINESS_MAP_AMOUNT = newString("Glossiness_Map_Amount");
	String LoadAsset::STR_SELF_ILLUM_AMOUNT = newString("Self_Illum_Amount");
	String LoadAsset::STR_SELF_ILLUM_COLOR = newString("Self_Illum_Color");
	String LoadAsset::STR_SELF_ILLUM_MAP = newString("Self_Illum_Map");
	String LoadAsset::STR_SELF_ILLUM_MAP_AMOUNT = newString("Self_Illum_Map_Amount");
	String LoadAsset::STR_OPACITY = newString("Opacity");
	String LoadAsset::STR_OPACITY_TYPE = newString("Opacity_Type");
	String LoadAsset::STR_OPACITY_FALL_OFF = newString("Opacity_Fall_Off");
	String LoadAsset::STR_OPACITY_FALL_OFF_TYPE = newString("Opacity_Fall_Off_Type");
	String LoadAsset::STR_OPACITY_MAP = newString("Opacity_Map");
	String LoadAsset::STR_OPACITY_MAP_AMOUNT = newString("Opacity_Map_Amount");
	String LoadAsset::STR_FILTER_MAP = newString("Filter_Map");
	String LoadAsset::STR_FILTER_MAP_AMOUNT = newString("Filter_Map_Amount");
	String LoadAsset::STR_BUMP_MAP = newString("Bump_Map");
	String LoadAsset::STR_BUMP_MAP_AMOUNT = newString("Bump_Map_Amount");
	String LoadAsset::STR_REFLECTION_LEVEL = newString("Reflection_Level");
	String LoadAsset::STR_REFLECTION_MAP = newString("Reflection_Map");
	String LoadAsset::STR_REFLECTION_MAP_AMOUNT = newString("Reflection_Map_Amount");
	String LoadAsset::STR_REFRACTION_MAP = newString("Refraction_Map");
	String LoadAsset::STR_REFRACTION_MAP_AMOUNT = newString("Refraction_Map_Amount");
	String LoadAsset::STR_DISPLACEMENT_MAP = newString("Displacement_Map");
	String LoadAsset::STR_DISPLACEMENT_MAP_AMOUNT = newString("Displacement_Map_Amount");
	String LoadAsset::STR_FILE_NAME = newString("FileName");
	String LoadAsset::STR_START_TIME = newString("StartTime");
	String LoadAsset::STR_PLAYBACK_RATE = newString("PlaybackRate");
	String LoadAsset::STR_END_CONDITION = newString("EndCondition");
	String LoadAsset::STR_FOV = newString("FOV");
	String LoadAsset::STR_NEAR_RANGE = newString("Near_Range");
	String LoadAsset::STR_FAR_RANGE = newString("Far_Range");
	String LoadAsset::STR_NEAR_CLIP = newString("Near_Clip");
	String LoadAsset::STR_FAR_CLIP = newString("Far_Clip");
	String LoadAsset::STR_TARGET_DISTANCE = newString("Target_Distance");
	String LoadAsset::STR_FOV_TYPE = newString("FOV_Type");
	String LoadAsset::STR_CLIP_MANUALLY = newString("Clip_Manually");
	String LoadAsset::STR_TRANSFORM = newString("Transform");
	String LoadAsset::STR_ROW[4] = {newString("r1"), newString("r2"), newString("r3"), newString("r4")};
	String LoadAsset::STR_P[4] = {newString("p1"), newString("p2"), newString("p3"), newString("p4")};
	String LoadAsset::STR_X = newString("x");
	String LoadAsset::STR_Y = newString("y");
	String LoadAsset::STR_Z = newString("z");
	String LoadAsset::STR_A = newString("a");
	String LoadAsset::STR_POSITION = newString("Position");
	String LoadAsset::STR_SCALE = newString("Scale");
	String LoadAsset::STR_ROTATION = newString("Rotation");
	String LoadAsset::STR_CAMERA = newString("camera");
	String LoadAsset::STR_MODEL = newString("model");
	String LoadAsset::STR_MATERIAL = newString("material");
	String LoadAsset::STR_TEXTURE = newString("texture");
	String LoadAsset::STR_LIGHT = newString("light");
	String LoadAsset::STR_GROUP = newString("group");
	String LoadAsset::STR_R = newString("r");
	String LoadAsset::STR_G = newString("g");
	String LoadAsset::STR_B = newString("b");

	// Default Constructor
	LoadAsset::LoadAsset()
	{
		m_IsFinished = false;
	}

	// Copy Constructor
	LoadAsset::LoadAsset(const LoadAsset &inLoadAsset)
	{
		copy(inLoadAsset);
	}

	LoadAsset& LoadAsset::operator=( const LoadAsset& rhs )
	{
		copy(rhs);
		return *this;
	}

	LoadAsset* LoadAsset::clone() const
	{
		printf("New LoadAsset::Clone\n");
		return new LoadAsset(*this);
	}

	void LoadAsset::copy(const LoadAsset &inLoadAsset)
	{
		this->m_FileName = inLoadAsset.m_FileName;
		this->m_Type = inLoadAsset.m_Type;
		
		this->m_Asset = new Asset();
		*(this->m_Asset) = *(inLoadAsset.m_Asset);
		this->m_IsFinished = inLoadAsset.m_IsFinished;
	}

	// Destructor
	LoadAsset::~LoadAsset()
	{
		if(this->m_Asset != NULL)
			delete this->m_Asset;
	}

	int LoadAsset::setFileName(String* fileName)
	{
		int status  = -1;
		this->m_FileName = *fileName;
		return status;
	}

	int LoadAsset::setType(String* type)
	{
		int status = -1;
		this->m_Type = *type;
		return status;
	}

	Asset* LoadAsset::getAsset()
	{
		return this->m_Asset;
	}

	int LoadAsset::setAsset(Asset* asset)
	{
		int status = -1;
		this->m_Asset = asset;
		return status;
	}

	void __cdecl LoadAsset::asyncLoadAsset(void* This)
	{
		LoadAsset* la = (LoadAsset*)This;

		if(la->m_Asset != NULL)
		{
			LoadAsset::loadAsset(&(la->m_FileName),
								 &(la->m_Type),
								 la->m_Asset);
			wprintf(L"Finished loading: %s\n", la->m_Asset->getName()->c_str());
		}
		la->m_IsFinished = true;
	}

	// the 2 "dimensional" pointer is for the calling class to be able
	// to delete the pointer
	int LoadAsset::loadAsset(String* fileName, String* type, Asset* asset)
	{
		int status = -1;
		wprintf(L"Loading Asset: %s\n", fileName->c_str());
		loaders::LoadXML lXML;
		lXML.loadXML(fileName);
		if(lXML.getDocument() != NULL)
		{
			if(asset != NULL)
			{
				// load scenes
				String name = lXML.getTagContent(STR_NAME);
				asset->setName(name);
				if(lXML.getTagContent(STR_GROUP_NAME).length() > 0)
				{
					String grp = lXML.getTagContent(STR_GROUP_NAME);
					asset->setGroupName(grp);
				}
				if(lXML.getTagContent(STR_MATRIX).length() > 0)
					asset->setMatrix(loadMatrix(&lXML, STR_MATRIX));
				if(lXML.getTagContent(STR_OFFSET_MATRIX).length() > 0)
					asset->setOffsetMatrix(loadMatrix(&lXML, STR_OFFSET_MATRIX));
				
				// load specific type
				if(asset->getType() == Asset::CAMERA)
				{
					status = loadCamera(((Camera*)asset), &lXML);
				}
				else if(asset->getType() == Asset::MODEL)
				{
					status = LoadModel::loadModel((Model*)asset, &lXML);
				}
				else if(asset->getType() == Asset::MATERIAL)
				{
					status = loadMaterial((Material*)asset, &lXML);
				}
				else if(asset->getType() == Asset::TEXTURE)
				{
					status = loadTexture((Texture*)asset, &lXML);
				}
				else if(asset->getType() == Asset::LIGHT)
				{
					status = loadLight((Light*)asset, &lXML);
				}
				else if(asset->getType() == Asset::GROUP)
				{
					// no data
				}

				// Load animation
				String animTag = lXML.getTagContent(STR_ANIMATION);
				if(animTag.length() > 0)
				{
					Animation* anim = asset->getAnimtation();
					loadAnimation(anim, &lXML);
				}
			}
			else
				wprintf(L"Failed to find Asset Type: %s\n", type->c_str());
		}
		else
			wprintf(L"Failed to load xml: %s\n", fileName->c_str());
		return status;
	}

	Animation* LoadAsset::loadAnimation(Animation* anim, loaders::LoadXML* lXML)
	{
		String& animTag = STR_ANIMATION;
		anim->setStartFrame(lXML->getTagContentF(STR_START_FRAME));
		anim->setEndFrame(lXML->getTagContentF(STR_END_FRAME));
		DOMNodeList* frames = lXML->getTagNodeList(STR_FRAME);
		if(frames != NULL &&
			frames->getLength() > 0)
		{
			printf("Frames: %d\n", frames->getLength());
			for(int i = 0; i < frames->getLength(); i++)
			{
				int frameNum = (int)lXML->getTagContentF(STR_FRAME_NUMBER, (DOMElement*)frames->item(i));
				KeyFrame* kf = anim->newFrame(frameNum);
				// Frame_Number
				kf->setFrameNumber(frameNum);
				// Matrix
				kf->setMatrix(loadMatrix(lXML, STR_MATRIX, (DOMElement*)frames->item(i)));
			}
		}
		return anim;
	}

	int LoadAsset::loadLight(Light* light, loaders::LoadXML* lXML)
	{
		int status = -1;
		String str;
		float value = 0;
		bool test = false;

		light->setLightType(lXML->getTagContent(STR_TYPE));
		light->setEnabled(lXML->getTagContentB(STR_ENABLED));
		DOMElement* colorNode = lXML->getTagXML(STR_COLOR);
		float color[4];
		getColor(color, colorNode, lXML);
		light->setColor(color[0], color[1], color[2], color[3]);
		light->setMultiplier(lXML->getTagContentF(STR_MULTIPLIER));
		light->setContrast(lXML->getTagContentF(STR_CONTRAST));
		light->setSoftenDiffuseEdge(lXML->getTagContentF(STR_SOFTEN_DIFFUSE_EDGE));
		light->setAffectDiffuse(lXML->getTagContentB(STR_AFFECT_DIFFUSE));
		light->setAffectSpecular(lXML->getTagContentB(STR_AFFECT_SPECULAR));
		light->setAmbientOnly(lXML->getTagContentB(STR_AMBIENT_ONLY));
		light->setProjector(lXML->getTagContentB(STR_PROJECTOR));
		light->setProjectorMap(lXML->getTagContent(STR_PROJECTOR_MAP));
		light->setNearAttenStart(lXML->getTagContentF(STR_NEAR_ATTEN_START));
		light->setNearAttenEnd(lXML->getTagContentF(STR_NEAR_ATTEN_END));
		light->setNearAtten(lXML->getTagContentB(STR_USE_NEAR_ATTEN));
		light->setFarAttenStart(lXML->getTagContentF(STR_FAR_ATTEN_START));
		light->setFarAttenEnd(lXML->getTagContentF(STR_FAR_ATTEN_END));
		light->setFarAtten(lXML->getTagContentB(STR_USE_FAR_ATTEN));
		light->setAttenDecay(lXML->getTagContentF(STR_ATTEN_DECAY));
		light->setDecayRadius(lXML->getTagContentF(STR_DECAY_RADIUS));
		light->setCastShadows(lXML->getTagContentB(STR_CAST_SHADOWS));
		return status;
	}

	int LoadAsset::loadMaterial(Material* material, loaders::LoadXML* lXML)
	{
		int status = -1;
		String str;
		float value = 0;

		material->setShaderType(lXML->getTagContentF(STR_SHADER_TYPE));
		material->setTwoSided(lXML->getTagContentB(STR_TWO_SIDED));
		material->setFaceted(lXML->getTagContentB(STR_FACETED));
		material->setSoften(lXML->getTagContentF(STR_SOFTEN));
		material->setIndexOfRefraction(lXML->getTagContentF(STR_INDEX_OF_REFRACTION));

		DOMElement* colorNode = lXML->getTagXML(STR_AMBIENT);
		float color[4];
		getColor(color, colorNode, lXML);
		material->setAmbientColor(color[0], color[1], color[2], color[3]);
		material->setAmbientMap(lXML->getTagContent(STR_AMBIENT_MAP));
		material->setAmbientMapAmount(lXML->getTagContentF(STR_AMBIENT_MAP_AMOUNT));

		colorNode = lXML->getTagXML(STR_DIFFUSE);
		getColor(color, colorNode, lXML);
		material->setDiffuseColor(color[0], color[1], color[2], color[3]);
		material->setDiffuseMap(lXML->getTagContent(STR_DIFFUSE_MAP));
		material->setDiffuseMapAmount(lXML->getTagContentF(STR_DIFFUSE_MAP_AMOUNT));

		colorNode = lXML->getTagXML(STR_SPECULAR);
		getColor(color, colorNode, lXML);
		material->setSpecularColor(color[0], color[1], color[2], color[3]);
		material->setSpecularMap(lXML->getTagContent(STR_SPECULAR_MAP));
		material->setSpecularMapAmount(lXML->getTagContentF(STR_SPECULAR_MAP_AMOUNT));
		material->setSpecularLevel(lXML->getTagContentF(STR_SPECULAR_LEVEL));

		material->setGlossiness(lXML->getTagContentF(STR_GLOSSINESS));
		material->setGlossinessMap(lXML->getTagContent(STR_GLOSSINESS_MAP));
		material->setGlossinessMapAmount(lXML->getTagContentF(STR_GLOSSINESS_MAP_AMOUNT));

		material->setSelfIllumAmount(lXML->getTagContentF(STR_SELF_ILLUM_AMOUNT));
		colorNode = lXML->getTagXML(STR_SELF_ILLUM_COLOR);
		getColor(color, colorNode, lXML);
		material->setSelfIllumColor(color[0], color[1], color[2], color[3]);
		material->setSelfIllumMap(lXML->getTagContent(STR_SELF_ILLUM_MAP));
		material->setSelfIllumMapAmount(lXML->getTagContentF(STR_SELF_ILLUM_MAP_AMOUNT));

		material->setOpacity(lXML->getTagContentF(STR_OPACITY));
		material->setOpacityType(lXML->getTagContentF(STR_OPACITY_TYPE));
		material->setOpacityFallOff(lXML->getTagContentF(STR_OPACITY_FALL_OFF));
		material->setOpacityFallOffType(lXML->getTagContentF(STR_OPACITY_FALL_OFF_TYPE));
		material->setOpacityMap(lXML->getTagContent(STR_OPACITY_MAP));
		material->setOpacityMapAmount(lXML->getTagContentF(STR_OPACITY_MAP_AMOUNT));

		material->setFilterMap(lXML->getTagContent(STR_FILTER_MAP));
		material->setFilterMapAmount(lXML->getTagContentF(STR_FILTER_MAP_AMOUNT));

		material->setBumpMap(lXML->getTagContent(STR_BUMP_MAP));
		material->setBumpMapAmount(lXML->getTagContentF(STR_BUMP_MAP_AMOUNT));

		material->setReflectionLevel(lXML->getTagContentF(STR_REFLECTION_LEVEL));
		material->setReflectionMap(lXML->getTagContent(STR_REFLECTION_MAP));
		material->setReflectionMapAmount(lXML->getTagContentF(STR_REFLECTION_MAP_AMOUNT));

		material->setRefractionMap(lXML->getTagContent(STR_REFRACTION_MAP));
		material->setRefractionMapAmount(lXML->getTagContentF(STR_REFRACTION_MAP_AMOUNT));

		material->setDisplacementMap(lXML->getTagContent(STR_DISPLACEMENT_MAP));
		material->setDisplacementMapAmount(lXML->getTagContentF(STR_DISPLACEMENT_MAP_AMOUNT));

		return status;
	}

	int LoadAsset::loadTexture(Texture* texture, loaders::LoadXML* lXML)
	{
		int status = -1;
		texture->setFileName(lXML->getTagContent(STR_FILE_NAME));
		texture->setStartFrame(lXML->getTagContentF(STR_START_TIME));
		texture->setPlaybackRate(lXML->getTagContentF(STR_PLAYBACK_RATE));
		texture->setEndCondition(lXML->getTagContentF(STR_END_CONDITION));
		return status;
	}

	int LoadAsset::loadCamera(Camera* camera, loaders::LoadXML* lXML)
	{
		int status = -1;
		String str;
		float value = 0;
		camera->setFOV(lXML->getTagContentF(STR_FOV));
		camera->setNearRange(lXML->getTagContentF(STR_NEAR_RANGE));
		camera->setFarRange(lXML->getTagContentF(STR_FAR_RANGE));
		camera->setNearClip(lXML->getTagContentF(STR_NEAR_CLIP));
		camera->setFarClip(lXML->getTagContentF(STR_FAR_CLIP));
		camera->setTargetDistance(lXML->getTagContentF(STR_TARGET_DISTANCE));
		camera->setFOVType(lXML->getTagContentF(STR_FOV_TYPE));
		camera->setClipManually(lXML->getTagContentB(STR_CLIP_MANUALLY));
		return status;
	}

	math::Matrix* LoadAsset::loadMatrix(loaders::LoadXML* lXML, String& matrixName, DOMElement* tag)
	{
		
		math::Matrix* matrix = new math::Matrix();
		DOMElement* matrixList = NULL;
		if(tag != NULL)
			matrixList = lXML->getTagXML(matrixName, tag);
		else
			matrixList = lXML->getTagXML(matrixName);
		DOMElement* transformList = lXML->getTagXML(STR_TRANSFORM, matrixList);
		for(int n = 0; n < 4; n++)
		{
			DOMElement* rowList = lXML->getTagXML(STR_ROW[n], transformList);

			float p1 = lXML->getTagContentF(STR_P[0], rowList);
			float p2 = lXML->getTagContentF(STR_P[1], rowList);
			float p3 = lXML->getTagContentF(STR_P[2], rowList);
			float p4 = lXML->getTagContentF(STR_P[3], rowList);
			matrix->setRow(n, p1, p2, p3, p4);
		}
		//getPoints(matrix, matrixList, lXML, newString("Rotation"));
		//getPoints(matrix, matrixList, lXML, newString("Scale"));
		//getPoints(matrix, matrixList, lXML, newString("Position"));
		return matrix;
	}

	void LoadAsset::getPoints(math::Matrix* matrix, DOMElement* matrixList, loaders::LoadXML* lXML, String& point)
	{
		DOMElement* positionList = lXML->getTagXML(point, matrixList);
		float x = lXML->getTagContentF(STR_X, positionList);
		float y = lXML->getTagContentF(STR_Y, positionList);
		float z = lXML->getTagContentF(STR_Z, positionList);
		float a = lXML->getTagContentF(STR_A, positionList);
		if(cmpStrI(point, STR_POSITION) == 0)
			matrix->setPosition(x, y, z);
		if(cmpStrI(point, STR_SCALE) == 0)
			matrix->setScale(x, y, z);
		if(cmpStrI(point, STR_ROTATION) == 0)
			matrix->setRotation(x, y, z, a);
	}
	
	int LoadAsset::getColor(float* color, DOMElement* colorNode, loaders::LoadXML* lXML)
	{
		int status = -1;
		color[0] = lXML->getTagContentF(STR_R, colorNode);
		color[1] = lXML->getTagContentF(STR_G, colorNode);
		color[2] = lXML->getTagContentF(STR_B, colorNode);
		color[3] = lXML->getTagContentF(STR_A, colorNode);
		return status;
	}
}