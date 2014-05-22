#include "Square.h"
#include "SFML/Graphics.hpp"


/**
Constructeur de Square. Utilise 4 lignes pour faire son rectangle.
@param[in] _Lines[4] Un tableau de 4 pointeurs de Line.
@see Line
*/
Square::Square(Line* _Lines[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->LinesComposition[i] = _Lines[i];
	}
}

/**
Constructeur de Square. Utilise 4 points pour faire son rectangle.
@param[in] _vertexA Premier point. Il servira de point de départ pour l'affichage.
@param[in] _vertexB Deuxième point.
@param[in] _vertexC Troisième point.
@param[in] _vertexD Quatrième point. Il servira de point final pour l'affichage.
@see Point
@see Display
*/
Square::Square(Point* _vertexA, Point* _vertexB, Point* _vertexC, Point* _vertexD)
{
	this->vertex[0] = _vertexA;
	this->vertex[1] = _vertexB;
	this->vertex[2] = _vertexC;
	this->vertex[3] = _vertexD;

	for (int i = 0; i < 4; i++)
	{
		this->vertex[i]->setUsed(true);
	}

	this->LinesComposition[0] = new Line(_vertexA, _vertexB);
	this->LinesComposition[1] = new Line(_vertexA, _vertexC);
	this->LinesComposition[2] = new Line(_vertexB, _vertexD);
	this->LinesComposition[3] = new Line(_vertexC, _vertexD);
}

/**
Destructeur de Rectangle. Supprime les lignes et les vertex.
*/
Square::~Square(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->LinesComposition[i];
	}
	for (int i = 0; i < 4; i++)
	{
		delete this->vertex[i];
	}
}

/**
Fonction qui retourne une ligne composant le Square.
@return Une ligne "i" composant le Square.
*/
Line* Square::getLignesComposition(unsigned int point) const
{
	return this->LinesComposition[point];
}