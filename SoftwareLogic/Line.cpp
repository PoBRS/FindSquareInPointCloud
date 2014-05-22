#include "Line.h"

/**
Constructeur de Line.
@param[in] _startPoint
@param[in] _endPoint
*/
Line::Line(Point* _startPoint, Point* _endPoint)
{
	this->startPoint = _startPoint;
	this->endPoint = _endPoint;

	this->dxCurrent = 0;
	this->dxFinal = (_endPoint->getX() - _startPoint->getX());
	this->dyCurrent = 0;
	this->dyFinal = (_endPoint->getY() - _startPoint->getY());
}

/**
Destructeur de Line. Ne d�truit pas les points le composant.
*/
Line::~Line(void)
{

}

/**
Getter du premier point(Start Point) composant la ligne.
@return Le point de d�part.
*/
Point* Line::getStartPoint(void) const
{
	return this->startPoint;
}
/**
Getter du deuxi�me point(End Point) composant la ligne.
@return Le point d'arriv�
*/
Point* Line::getEndPoint(void) const
{
	return this->endPoint;
}

/**
Getter de la distance actuelle en X entre le point de d�part et la fin de la ligne.
@return La distance actuelle en X entre le point de d�part et la fin de la ligne
*/
float Line::getDxCurrent(void) const
{
	return this->dxCurrent;
}

/**
Getter de la distance finale (attendue) en X entre le point de d�part et la fin de la ligne.
@return La distance finale (attendue) en X entre le point de d�part et la fin de la ligne
*/
float Line::getDxFinal(void) const
{
	return this->dxFinal;
}

/**
Getter de la distance actuelle en Y entre le point de d�part et la fin de la ligne.
@return La distance actuelle en Y entre le point de d�part et la fin de la ligne
*/
float Line::getDyCurrent(void) const
{
	return this->dyCurrent;
}

/**
Getter de la distance finale (attendue) en Y entre le point de d�part et la fin de la ligne.
@return La distance finale (attendue) en Y entre le point de d�part et la fin de la ligne
*/
float Line::getDyFinal(void) const
{
	return this->dyFinal;
}

/**
Setter de la distance actuelle en X entre le point de d�part et la fin de la ligne.
@return La distance actuelle en X entre le point de d�part et la fin de la ligne
*/
void Line::setDxCurrent(const float dxCurrent)
{
	this->dxCurrent = dxCurrent;
}

/**
Setter de la distance actuelle en Y entre le point de d�part et la fin de la ligne.
@return La distance actuelle en Y entre le point de d�part et la fin de la ligne
*/
void Line::setDyCurrent(const float dyCurrent)
{
	this->dyCurrent = dyCurrent;
}