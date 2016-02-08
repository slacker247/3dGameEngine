#pragma once

namespace assets
{
	class Bone
	{
	public:
		// Default Constructor
		Bone();
		// Copy Constructor
		Bone(const Bone &inBone);
		virtual Bone& operator=( const Bone& rhs );
	    virtual Bone clone() const;
		virtual void copy(const Bone &inBone);
		// Destructor
		~Bone();
	};
}