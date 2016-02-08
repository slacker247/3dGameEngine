#include "Asset.h"

namespace assets
{

	Asset::Asset(void)
	{
		this->m_Name = newString("");
		this->m_LastFrame = NULL;
		this->m_CurrentMatrix.loadIdentity();
		this->m_Matrix.loadIdentity();
		this->m_OffsetMatrix.loadIdentity();
		this->m_GroupName = newString("");
		this->m_HasLastFrame = false;
		this->m_Type = -1;
	}

	// Copy Constructor
	Asset::Asset(const Asset &inAsset)
	{
		copy(inAsset);
	}

	Asset& Asset::operator=( const Asset& rhs )
	{
		copy(rhs);
		return *this;
	}

	Asset* Asset::clone() const
	{
		return new Asset(*this);
	}

	void Asset::copy(const Asset &inAsset)
	{
		this->m_Matrix = inAsset.m_Matrix;
		this->m_OffsetMatrix = inAsset.m_OffsetMatrix;
		this->m_Name = inAsset.m_Name;
		this->m_Type = inAsset.m_Type;
		this->m_GroupName = inAsset.m_GroupName;
		this->m_Animation = inAsset.m_Animation;
	}

	Asset::~Asset(void)
	{
	}
	
	int Asset::getType()
	{
		return this->m_Type;
	}

	int Asset::setType(int type)
	{
		int status = -1;
		this->m_Type = type;
		return status;
	}

	String* Asset::getName()
	{
		return &(this->m_Name);
	}

	int Asset::setName(String& name)
	{
		int status = -1;
		this->m_Name = name;
		return status;
	}

	String* Asset::getGroupName()
	{
		return &(this->m_GroupName);
	}

	int Asset::setGroupName(String& name)
	{
		int status = -1;
		this->m_GroupName = name;
		return status;
	}

	int Asset::setMatrix(math::Matrix* matrix)
	{
		int status = -1;
		if(matrix != NULL)
		{
			// copy operation
			this->m_Matrix = *matrix;
			this->m_CurrentMatrix = *matrix;
			status = -1;
		}
		return status;
	}

	math::Matrix* Asset::getMatrix(int frame)
	{
		math::Matrix* matrix = &(this->m_Matrix);
		KeyFrame* kf = this->m_Animation.getFrame(frame);
		if(kf != NULL)
		{
			matrix = kf->getMatrix();
			m_LastFrame = kf;
			m_HasLastFrame = true;
		}
		else if(m_LastFrame != NULL &&
				m_HasLastFrame)
		{
			matrix = m_LastFrame->getMatrix();
		}
		return matrix;
	}

	int Asset::setOffsetMatrix(math::Matrix* matrix)
	{
		int status = -1;
		if(matrix != NULL)
		{
			this->m_OffsetMatrix = *matrix;
			status = 0;
		}
		return status;
	}

	math::Matrix* Asset::getOffsetMatrix()
	{
		return &(this->m_OffsetMatrix);
	}

	Animation* Asset::getAnimtation()
	{
		return &(this->m_Animation);
	}

	int Asset::setAnimation(Animation* anim)
	{
		int status = -1;
		if(anim != NULL)
		{
			this->m_Animation = *anim;
			status = 0;
		}
		return status;
	}
}
