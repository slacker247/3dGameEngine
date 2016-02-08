
#include "String.h"

// NOT THREAD SAFE!!!
String newString(const char* s)
{
	
	int length = strlen(s);
	String ws;
	if(length > 0)
	{
		wchar_t* buf = new wchar_t[ length ];
		size_t num_chars = mbstowcs( buf, s, length );
		ws.assign( buf, num_chars );
		delete buf;
	}
	else
		ws.assign(L"");
    return ws;
}

int cmpStrI(const String& stringA , const String& stringB)
{
	int status = 0;
	status = _wcsicmp(stringA.c_str(), stringB.c_str());
	return status;
}

double strToDbl(const String& value)
{
	double retVal = 0;
	try
	{
		retVal = stod(value);
	}
	catch(...)
	{
	}
	return retVal;
}

String dblToStr(double value)
{
	String retVal = newString("");
	try
	{
		char buf[255];
		buf[0] = '\0';
		sprintf(buf, "%f", value);
		retVal = newString(buf);
	}
	catch(...)
	{
	}
	return retVal;
}

const String WHITESPACE = newString(" \n\r\t");

String strTrim(const String& s)
{
	String retVal;
	bool test = false;
	for(int i = 0; i < WHITESPACE.length(); i++)
	{
		if(s.find(WHITESPACE[i]) != String::npos)
		{
			test = true;
			i = 10;
		}
	}
	if(test)
	{
		retVal = strTrimLeft(s);
		retVal = strTrimRight(retVal);
	}
	else
		retVal = s;
    return retVal;
}

String strTrimLeft(const String& s)
{
	String retVal;
    size_t startpos = s.find_first_not_of(WHITESPACE);
	if(startpos != String::npos)
	{
		retVal = s.substr(startpos);
	}
	else
	{
		retVal = s;
	}
    return retVal;
}

String strTrimRight(const String& s)
{
	String retVal;
    size_t endpos = s.find_last_not_of(WHITESPACE);
	if(endpos != String::npos)
	{
		retVal = s.substr(0, endpos+1);
	}
	else
	{
		retVal = s;
	}
    return retVal;
}