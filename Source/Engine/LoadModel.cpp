#include "LoadModel.h"

namespace loaders
{
	String LoadModel::STR_MATERIAL_NAME = newString("Material_Name");
	String LoadModel::STR_MESH = newString("Mesh");
	String LoadModel::STR_POLY = newString("Poly");
	String LoadModel::STR_VERT = newString("Vert");
	String LoadModel::STR_X = newString("x");
	String LoadModel::STR_Y = newString("y");
	String LoadModel::STR_Z = newString("z");
	String LoadModel::STR_U = newString("u");
	String LoadModel::STR_V = newString("v");
	String LoadModel::STR_W = newString("w");
	String LoadModel::STR_TEXT_COORD = newString("Text_Coord");
	String LoadModel::STR_NORMAL = newString("Normal");

	// Default Constructor
	LoadModel::LoadModel()
	{
	}

	// Copy Constructor
	LoadModel::LoadModel(const LoadModel &inLoadModel)
	{
	}

	// Destructor
	LoadModel::~LoadModel()
	{
	}

	int LoadModel::loadModel(assets::Model* model, loaders::LoadXML* lXML)
	{
		int status = -1;
		String materialName = lXML->getTagContent(STR_MATERIAL_NAME);
		model->setMaterialName(materialName);
		DOMNodeList* meshes = lXML->getTagNodeList(STR_MESH);
		if(meshes != NULL &&
			meshes->getLength() > 0)
		{
			for(int i = 0; i < meshes->getLength(); i++)
			{
				assets::Mesh* mesh = model->newMesh();
				loadMesh((DOMElement*)meshes->item(i), lXML, mesh);
			}
		}
		return status;
	}

	Mesh* LoadModel::loadMesh(DOMElement* meshXML, loaders::LoadXML* lXML, Mesh* mesh)
	{
		DOMNodeList* polys = lXML->getTagNodeList(STR_POLY, meshXML);
		if(polys != NULL &&
			polys->getLength() > 0)
		{
			for(int i = 0; i < polys->getLength(); i++)
			{ // i = 9
				assets::Polygon* poly = mesh->newPoly();
				loadPoly((DOMElement*)polys->item(i), lXML, poly);
			}
		}
		return mesh;
	}

	assets::Polygon* LoadModel::loadPoly(DOMElement* polyXML, loaders::LoadXML* lXML, assets::Polygon* poly)
	{
		DOMNodeList* verts = lXML->getTagNodeList(STR_VERT, polyXML);
		if(verts != NULL &&
			verts->getLength() > 0)
		{
			for(int i = 0; i < verts->getLength(); i++)
			{
				Vertex* vert = poly->newVertex();
				loadVert((DOMElement*)verts->item(i), lXML, vert);
			}
		}
		return poly;
	}

	Vertex* LoadModel::loadVert(DOMElement* vertXML, loaders::LoadXML* lXML, Vertex* vert)
	{
		String str;
		str = lXML->getTagContent(STR_X, vertXML);
		float x = strToDbl(str);
		str = lXML->getTagContent(STR_Y, vertXML);
		float y = strToDbl(str);
		str = lXML->getTagContent(STR_Z, vertXML);
		float z = strToDbl(str);
		vert->setPosition(x, y, z);

		DOMElement* textCoords = lXML->getTagXML(STR_TEXT_COORD, vertXML);
		str = lXML->getTagContent(STR_U, textCoords);
		float u = strToDbl(str);
		str = lXML->getTagContent(STR_V, textCoords);
		float v = strToDbl(str);
		str = lXML->getTagContent(STR_W, textCoords);
		float w = strToDbl(str);
		vert->setTextCoord(u, v, w);
				
		DOMElement* normal = lXML->getTagXML(STR_NORMAL, vertXML);
		str = lXML->getTagContent(STR_X, normal);
		x = strToDbl(str);
		str = lXML->getTagContent(STR_Y, normal);
		y = strToDbl(str);
		str = lXML->getTagContent(STR_Z, normal);
		z = strToDbl(str);
		vert->setNormal(x, y, z);
		return vert;
	}
}