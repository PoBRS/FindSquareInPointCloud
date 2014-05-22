#include "Parameters.h"

/**
Constructeur de Parameters.
*/
Parameters::Parameters(void)
{
	this->dataReader = new XMLReader();
	this->squareList = new std::vector<Square*>();
	this->findFullblast();
	this->findPoints();
}

/**
Destructeur de Parameters.
*/
Parameters::~Parameters(void)
{
	delete this->dataReader;

	for (std::vector<Square*>::iterator it = this->squareList->begin(); it != this->squareList->end(); std::advance(it,1))
	{
		delete (*it);
	}
	delete this->squareList;
	delete this->pointList;
}

/**
Obtient la liste de points de XMLReader et conserve les données dans une variable membre.
C'est une sorte de Setter appellé automatiquement à la création de Parameters.
*/
void Parameters::findPoints(void)
{
	this->pointList = this->dataReader->getXMLPoints();
}

/**
Getter de la liste de points.
@return La liste de points.
*/
std::multiset<Point*, Point>* Parameters::getPoints() const
{
	return this->pointList;
}

/**
Obtient la valeur de la variable membre FullBlast avec XMLReader.
C'est une sorte de Setter appellé automatiquement à la création de Parameters.
*/
void Parameters::findFullblast()
{
	this->fullBlast = dataReader->getXMLFullBlast();
}

/**
Getter de la valeur de FullBlast.
@return La valeur de FullBlast.
*/
bool Parameters::getFullblast() const
{
	return this->fullBlast;
}

/**
Setter de la liste de Squares retrouvés pour conservation.
@param[in] squareList
*/
void Parameters::setSquareList(std::vector<Square*>* const squareList)
{
	this->squareList = squareList;
}

/**
Getter de la valeur de SquareList (liste des Squares retrouvés).
@return La valeur de SquareList.
*/
std::vector<Square*>* Parameters::getSquareList() const
{
	return this->squareList;
}