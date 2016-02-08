#pragma once

/////////////////////////////////////////////////////////
/// Class: Renderer
///
/// <author></author>
///
/// <version></version>
///
/// <summary></summary>
/////////////////////////////////////////////////////////
class Renderer
{
public:
	Renderer(void);
	~Renderer(void);

	string prop(string propName);
	int setProp(string propName, string value);
	int render(Asset object);

};

