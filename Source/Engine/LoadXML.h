
#include<msxml.h>             //defines DOMDocument first

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>

#include "String.h"

using namespace xercesc;

#pragma once

namespace loaders
{
	class LoadXML// : public LoadModel
	{
	protected:
		xercesc::DOMDocument* m_Document;
		ErrorHandler* m_ErrHandler;
		XercesDOMParser* m_Parser;

	public:
		// Default Constructor
		LoadXML();
		// Copy Constructor
		LoadXML(const LoadXML &inLoadXML);
		// Destructor
		~LoadXML();
		
		// Loads the given xml file into memory.
		int loadXML(String* xmlFile);
		xercesc::DOMDocument* getDocument();
		float getTagContentF(String& tag);
        float getTagContentF(String& tag, xercesc::DOMDocument* data);
        float getTagContentF(String& tag, DOMElement* data);
		bool getTagContentB(String& tag);
        bool getTagContentB(String& tag, xercesc::DOMDocument* data);
        bool getTagContentB(String& tag, DOMElement* data);
		String getTagContent(String& tag);
        String getTagContent(String& tag, xercesc::DOMDocument* data);
        String getTagContent(String& tag, DOMElement* data);
		DOMElement* getTagXML(String& tag);
        DOMElement* getTagXML(String& tag, xercesc::DOMDocument* data);
        DOMElement* getTagXML(String& tag, DOMElement* data);
		DOMNodeList* getTagNodeList(String& tag);
        DOMNodeList* getTagNodeList(String& tag, xercesc::DOMDocument* data);
        DOMNodeList* getTagNodeList(String& tag, DOMElement* data);
	protected:
		void showException(const String& message);
	};
}