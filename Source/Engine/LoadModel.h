#include "String.h"
#include "LoadXML.h"
#include "Model.h"

#pragma once

using namespace assets;

namespace loaders
{
	class LoadModel
	{
		static String STR_MATERIAL_NAME; // newString("Material_Name")
		static String STR_MESH; // newString("Mesh")
		static String STR_POLY; // newString("Poly")
		static String STR_VERT; // newString("Vert")
		static String STR_X; // newString("x")
		static String STR_Y; // newString("y")
		static String STR_Z; // newString("z")
		static String STR_U; // newString("u")
		static String STR_V; // newString("v")
		static String STR_W; // newString("w")
		static String STR_TEXT_COORD; // newString("Text_Coord")
		static String STR_NORMAL; // newString("Normal")
	public:
		// Default Constructor
		LoadModel();
		// Copy Constructor
		LoadModel(const LoadModel &inLoadModel);
		// Destructor
		~LoadModel();

		static int loadModel(Model* model, loaders::LoadXML* lXML);
		static Mesh* loadMesh(DOMElement* meshXML, loaders::LoadXML* lXML, Mesh* mesh);
		static assets::Polygon* loadPoly(DOMElement* polyXML, loaders::LoadXML* lXML, assets::Polygon* poly);
		static Vertex* loadVert(DOMElement* vertXML, loaders::LoadXML* lXML, Vertex* vert);
	};
}