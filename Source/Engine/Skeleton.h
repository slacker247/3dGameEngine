#pragma once

namespace assets
{
	class Skeleton
	{
	public:
		// Default Constructor
		Skeleton();
		// Copy Constructor
		Skeleton(const Skeleton &inSkeleton);
		virtual Skeleton& operator=( const Skeleton& rhs );
	    virtual Skeleton* clone() const;
		virtual void copy(const Skeleton &inSkeleton);
		// Destructor
		~Skeleton();
	};
}