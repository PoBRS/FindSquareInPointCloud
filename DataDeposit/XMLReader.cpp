#include "XMLReader.h"
#include <cassert>
#include <string>

using namespace std;
//namespace SFML

/**
	Constructeur de XMLReader
*/
XMLReader::XMLReader(void)
{
	
}
/**
	Destructeur de XMLReader
*/
XMLReader::~XMLReader(void)
{

}
/**
	Fonction qui lit le fichier XML de paramètrage et retourne la valeur donnée
	à FullBlast
	@return fullBlastActivated Valeur donnée à FullBlast.
*/
bool XMLReader::getXMLFullBlast(void)
{
	pugi::xml_node firstNode = this->SetReader("../Parametres.xml", "Parametres");
	int fullBlastActivated = atoi(firstNode.child_value("FullBlast"));
	return fullBlastActivated;
}
/**
	Fonction qui lit le fichier XML de paramètrage et retourne la valeur donnée
	au fichier des points.
	@return filePath Le path vers le fichiers contenant les points.
*/
std::string XMLReader::getXMLFile(void)
{

	pugi::xml_node firstNode = this->SetReader("../Parametres.xml", "Parametres");
	std::string filePath = firstNode.child_value("Fichier");
	return filePath;
}
/**
	Fonction qui lit le fichier de point et garni un 
	multiset avec tous les points qu'il y trouve.
	@return pointsFromXML un multiset<Point*, PointsComparator>* qui contient tout les points.
	@see Point
	@see PointsComparator
	@see getXMLFile
*/

std::multiset<Point*,Point>* XMLReader::getXMLPoints(void)
{

	pugi::xml_node firstNode = SetReader(this->getXMLFile(), "NuageDePoints");
	std::multiset<Point*,Point>* pointsFromXML = new std::multiset<Point*,Point>();

	for (pugi::xml_node point = firstNode.child("Point"); point != nullptr; point = point.next_sibling("Point"))
	{
		float x = atof(point.child_value("X"));
		float y = atof(point.child_value("Y"));
		Point* newPoint = new Point(x, y);
		pointsFromXML->insert(newPoint);
	}

	return pointsFromXML;
}

pugi::xml_node XMLReader::SetReader(std::string _fileXMLPath, std::string _firstNode)
{
	const char* fileXMLPathToConstChar = _fileXMLPath.c_str();
	const char* firstNodeToConstChar = _firstNode.c_str();

	pugi::xml_parse_result result = this->mediaXML.load_file(fileXMLPathToConstChar);
	assert(result && "File not found");
	pugi::xml_node firstNode = this->mediaXML.child(firstNodeToConstChar);

	return firstNode;
}
