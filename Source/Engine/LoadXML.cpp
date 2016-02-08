#include "LoadXML.h"

namespace loaders
{
	LoadXML::LoadXML(void)
	{
		this->m_Document = NULL;
		try
		{
			XMLPlatformUtils::Initialize();
		}
		catch(const XMLException& toCatch)
		{
			// Do your failure processing here
			String message = toCatch.getMessage();
			//cout << "Error during initialization! :\n"
			//	 << message << "\n";
		}
	}

	LoadXML::~LoadXML(void)
	{
		delete m_Parser;
		delete m_ErrHandler;
		XMLPlatformUtils::Terminate();
	}


	/////////////////////////////////////////////////////////
	/// Function: loadXML
	///
	/// <summary>Loads the given xml file into memory.</summary>
	///
	/// <param>xmlFile: Full or relative path and file name to 
	/// the xml file to be parsed.</param>
	///
	/// <returns>Returns 0 for a success. Otherwise the
	/// value will be in the error lookup table: <see></see>
	/// </returns>
	/////////////////////////////////////////////////////////
	int LoadXML::loadXML(String* xmlFile)
	{
		int status = -1;
		
		m_Parser = new XercesDOMParser();
		m_Parser->setValidationScheme(XercesDOMParser::Val_Always);
		m_Parser->setDoNamespaces(true);    // optional

		m_ErrHandler = (ErrorHandler*) new HandlerBase();
		m_Parser->setErrorHandler(m_ErrHandler);

		try
		{
			XMLCh fileName[100];
			XMLString::copyString(fileName, xmlFile->c_str());
			// TODO : Check to see if the file exists.
			m_Parser->parse(fileName);
			this->m_Document = m_Parser->getDocument();
			XMLCh nodeName[100] = L"data";
			DOMNodeList* nodeList = m_Document->getElementsByTagName(nodeName);
			String msg;
			for(int i = 0; i < (int)nodeList->getLength(); i++)
			{
				DOMNode* node = nodeList->item(i);
				String value = node->getTextContent();
				msg.append(newString("Found Node: "));
				msg.append(value);
				msg.append(newString("\n"));
				//Logger::log(msg, Logger::DEBUGINFO);
			}
			status = 0;
		}
		catch (const DOMException& toCatch)
		{
			showException(toCatch.msg);
			//Logger::log(msg, Logger::DEBUGINFO);
		}
		catch(RuntimeException toCatch)
		{
			showException(toCatch.getMessage());
			//Logger::log(msg, Logger::DEBUGINFO);
		}
		catch (const XMLException& toCatch)
		{
			showException(toCatch.getMessage());
			//Logger::log(msg, Logger::DEBUGINFO);
		}
		catch (...)
		{
			//Logger::log("Unexpected Exception \n", Logger::DEBUGINFO);
		}

		return status;
	}

	xercesc::DOMDocument* LoadXML::getDocument()
	{
		return this->m_Document;
	}

	void LoadXML::showException(const String& message)
	{
		String msg;
		msg.append(newString("Exception message is: "));
		msg.append(newString("\n"));
		msg.append(message);
		msg.append(newString("\n"));
	}

	float LoadXML::getTagContentF(String& tag)
	{
		return getTagContentF(tag, this->m_Document->getDocumentElement());
	}

    float LoadXML::getTagContentF(String& tag, xercesc::DOMDocument* data)
	{
		return getTagContentF(tag, (DOMElement*)data);
	}

    float LoadXML::getTagContentF(String& tag, DOMElement* data)
	{
		float value = 0;
		String str = this->getTagContent(tag, data);
		if(str.length() > 0)
		{
			try
			{
				value = stof(str);
			}catch(...)
			{
				wprintf(L"LoadXML::getTagContentF(): Failed to parse string: %s\n", str.c_str());
			}
		}
		return value;
	}

	bool LoadXML::getTagContentB(String& tag)
	{
		return getTagContentB(tag, this->m_Document->getDocumentElement());
	}

    bool LoadXML::getTagContentB(String& tag, xercesc::DOMDocument* data)
	{
		return getTagContentB(tag, (DOMElement*)data);
	}

    bool LoadXML::getTagContentB(String& tag, DOMElement* data)
	{
		bool test = false;
		String str = this->getTagContent(tag, data);
		if(cmpStrI(str, newString("true")) == 0)
			test = true;
		return test;
	}

	String LoadXML::getTagContent(String& tag)
	{
		return getTagContent(tag, this->m_Document->getDocumentElement());
	}

	String LoadXML::getTagContent(String& tag, xercesc::DOMDocument* data)
	{
		return getTagContent(tag, (DOMElement*)data);
	}

	String LoadXML::getTagContent(String& tag, DOMElement* data)
	{
		String result = newString("");
		if(data != NULL)
		{
			XMLCh nodeName[100];
			XMLString::copyString(nodeName, tag.c_str());
			DOMNodeList* nodeList = data->getElementsByTagName(nodeName);
			if(nodeList != NULL &&
				nodeList->getLength() > 0)
			{
				result = nodeList->item(0)->getTextContent();
			}
		}
		result = strTrim(result);
		return result;
	}

	DOMElement* LoadXML::getTagXML(String& tag)
	{
		return getTagXML(tag, this->m_Document->getDocumentElement());
	}

	DOMElement* LoadXML::getTagXML(String& tag, xercesc::DOMDocument* data)
	{
		return getTagXML(tag, (DOMElement*)data);
	}

	DOMElement* LoadXML::getTagXML(String& tag, DOMElement* data)
	{
		DOMElement* result = NULL;
		if(data != NULL)
		{
			XMLCh xmlNode[100];
			XMLString::copyString(xmlNode, tag.c_str());
			DOMNodeList* nodeList = data->getElementsByTagName(xmlNode);
			if(nodeList != NULL &&
				nodeList->getLength() > 0)
			{
				//for(int i = 0; i < nodeList->getLength(); i++)
				{
					result = (DOMElement*)nodeList->item(0);
				}
			}
		}
		return result;
	}

	DOMNodeList* LoadXML::getTagNodeList(String& tag)
	{
		return getTagNodeList(tag, this->m_Document->getDocumentElement());
	}

	DOMNodeList* LoadXML::getTagNodeList(String& tag, xercesc::DOMDocument* data)
	{
		return getTagNodeList(tag, (DOMElement*)data);
	}

	DOMNodeList* LoadXML::getTagNodeList(String& tag, DOMElement* data)
	{
		DOMNodeList* result = NULL;
		if(data != NULL)
		{
			XMLCh xmlNode[100];
			XMLString::copyString(xmlNode, tag.c_str());
			DOMNodeList* nodeList = data->getElementsByTagName(xmlNode);
			if(nodeList != NULL &&
				nodeList->getLength() > 0)
			{
				result = nodeList;
			}
		}
		return result;
	}
}