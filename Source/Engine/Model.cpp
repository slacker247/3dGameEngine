#include "Model.h"

namespace assets
{
	// Default Constructor
	Model::Model()
	{
		m_MaterialName = newString("");
		m_Type = Asset::MODEL;
	}

	// Copy Constructor
	Model::Model(const Model &inModel)
		: Asset(inModel)
	{
		copy(inModel);
	}

	Model& Model::operator=( const Model& rhs )
	{
		Asset::operator=(rhs);
		copy(rhs);
		return *this;
	}

	Model* Model::clone() const
	{
		return new Model(*this);
	}

	void Model::copy(const Model &inModel)
	{
		Asset::copy(inModel);
		deleteMeshs();
		this->m_MaterialName = inModel.m_MaterialName;
		for (list<Mesh>::const_iterator itMesh = inModel.m_Meshes.begin();
			itMesh != inModel.m_Meshes.end();
			++itMesh)
		{
			this->m_Meshes.push_back(*itMesh);
		}
	}

	// Destructor
	Model::~Model()
	{
	}

	int Model::deleteMeshs()
	{
		int status = -1;
		this->m_Meshes.clear();
		return status;
	}

	String* Model::getMaterialName()
	{
		return &(this->m_MaterialName);
	}

	int Model::setMaterialName(String& name)
	{
		int status = -1;
		this->m_MaterialName = name;
		return status;
	}

	int Model::addMesh(Mesh* mesh)
	{
		int status = -1;
		if(mesh != NULL)
		{
			this->m_Meshes.push_back(*mesh);
			status = 0;
		}
		return status;
	}
	
	Mesh* Model::newMesh()
	{
		Mesh* mesh = NULL;
		this->m_Meshes.push_back(Mesh());
		mesh = &(this->m_Meshes.back());
		return mesh;
	}

	list<Mesh>* Model::getMeshes()
	{
		return &(this->m_Meshes);
	}
}