#include "XmlParser.h"

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

int XmlParser::GetIntVariable(std::string variable, const char*  xmlFile)
{
	file<> xml(xmlFile);
	xml_document<> doc;
	doc.parse<0>(xml.data());
	xml_node<> *node = doc.first_node();

	//Gets a particular attribute in mad node
	for (xml_attribute<> *attr = node->first_attribute();
		attr; attr = attr->next_attribute())
	{
		std::string attributeName = attr->name();
		std::string attributeValue = attr->value();

		if (!attributeName.compare(variable))
			return atoi(attributeValue.c_str());
	}

	return NULL;
}

int*  XmlParser::GetNodes(const char* xmlFile)
{
	//// Code code be done in a separate function cause its the same as above
	//
	file<> xml(xmlFile);
	xml_document<> doc;
	doc.parse<0>(xml.data());
	xml_node<> *node = doc.first_node();
	////

	int *gidArray;
	std::list<int> gidList;
	int counter = 0;

	gidArray = new int[GetIntVariable("height", xmlFile) * GetIntVariable("width", xmlFile)];

	//Get all the gids into gid array
	for (xml_node<> *iter = node->first_node("layer")->first_node()->first_node(); iter; iter = iter->next_sibling())
	{
		xml_attribute<> *attr = iter->first_attribute();
		std::string value = attr->value();
		gidArray[counter] = atoi(value.c_str());
		counter++;
	}


	return gidArray;
}
