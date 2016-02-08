#include <list>

#include "String.h"
#include "Asset.h"
#include "Mesh.h"

using namespace std;

#pragma once

namespace assets
{
	class Model : public Asset
	{
	protected:
		String m_MaterialName;
		list<Mesh> m_Meshes;

	public:
		// Default Constructor
		Model();
		// Copy Constructor
		Model(const Model &inModel);
		virtual Model& operator=( const Model& rhs );
	    virtual Model* clone() const;
		virtual void copy(const Model &inModel);
		// Destructor
		~Model();
		
		int deleteMeshs();
		String* getMaterialName();
		int setMaterialName(String& name);
		int addMesh(Mesh* mesh);
		Mesh* newMesh();
		list<Mesh>* getMeshes();
	};
}