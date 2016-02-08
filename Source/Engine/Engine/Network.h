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
class Network
{
public:
	Network(void);
	~Network(void);

	int connect(string dest);
	int listen(int port);

	int send(string data);
	string receive();
};

