#pragma once
#include "pugixml.hpp"
#include <string>
#include <set>
#include "../SoftwareLogic/Point.h"
#include "../SoftwareLogic/PointsComparator.h"

//namespace SFML
struct comparePoints {
    bool operator() (const Point* A, const Point* B) const{
        if (*A<*B)
		{
			return true;
		}
		return false;
    }
};
class XMLReader
{
public:
	XMLReader(void);
	~XMLReader(void);
	 bool getXMLFullBlast(void);
	 std::string getXMLFile(void);
	 std::multiset<Point*,Point>* getXMLPoints(void);
	

private:
		pugi::xml_node SetReader(std::string _fileXMLPath, std::string _firstNode);
		//std::string fileXMLPath;
		//std::string firstNode;
		pugi::xml_document mediaXML;

};