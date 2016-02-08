
#include "String.h"
#include "Matrix.h"
#include "Animation.h"

#pragma once

namespace assets
{
	class Asset
	{
	public:
		static const int CAMERA = 0;
		static const int TYPE_TARGET = 7;
		static const int LIGHT = 1;
		static const int MATERIAL = 2;
		static const int MODEL = 3;
		static const int SOUND = 4;
		static const int TEXTURE = 5;
		static const int GROUP = 6;

	protected:
		math::Matrix m_Matrix;
		math::Matrix m_OffsetMatrix;
		math::Matrix m_CurrentMatrix;
		String m_Name;
		String m_GroupName;
		int m_Type;
		Animation m_Animation;
		KeyFrame* m_LastFrame;
		bool m_HasLastFrame;

	public:
		Asset(void);
		// Copy Constructor
		Asset(const Asset &inAsset);
		virtual Asset& operator=( const Asset& rhs );
	    virtual Asset* clone() const;
		virtual void copy(const Asset &inAsset);
		~Asset(void);

		int getType();
		int setType(int type);
		String* getName();
		int setName(String& name);
		String* getGroupName();
		int setGroupName(String& name);
		int setMatrix(math::Matrix* matrix);
		math::Matrix* getMatrix(int frame = 0);
		int setOffsetMatrix(math::Matrix* matrix);
		math::Matrix* getOffsetMatrix();

		Animation* getAnimtation();
		int setAnimation(Animation* anim);
	};
}
