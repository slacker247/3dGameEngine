#pragma once

/////////////////////////////////////////////////////////
/// Class: name
///
/// <author></author>
///
/// <version></version>
///
/// <summary></summary>
/////////////////////////////////////////////////////////
class Physics
{
public:
	Physics(void);
	~Physics(void);

	// these may need to return a new asset or modify the passed in one.
	int calcRagDoll(Asset riggedModel);
	int calcCollision(Asset obj1, Asset obj2);
	int calcParticles(Asset obj);
	int calcExplosion(Asset obj);
	int calcGravity(Asset obj);
};

