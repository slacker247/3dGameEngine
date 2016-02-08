#include <tchar.h>
#include <string>

#ifndef String

// HACK : to make a unified string class
#ifdef _UNICODE
typedef std::wstring String;
#else
typedef std::string String;
#endif
// END HACK

String newString(const char* s);
int cmpStrI(const String& stringA , const String& stringB);
double strToDbl(const String& value);
String dblToStr(double value);

String strTrim(const String& s);
String strTrimLeft(const String& s);
String strTrimRight(const String& s);

// http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

#endif