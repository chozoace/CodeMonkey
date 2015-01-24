#pragma once

#include <string>
#include <list>

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace rapidxml;

class XmlParser
{
public:
	XmlParser();
	~XmlParser();
	
	static int GetIntVariable(std::string variable, const char* xmlFile);
	static int* GetNodes(const char* xmlFile);
};

