#pragma once
#include "Line.h"

/**
	Classe conteneur permettant de regrouper 4 lignes composant un carré. Aucune logique ne 
	se retrouve dans ce code.
*/
class Square
{
public:
	Square(Line* _Lines[4]);
	Square(Point* _sommetA, Point* _sommetB, Point* _sommetC, Point* _sommetD);
	Square::~Square(void);
	Line* getLignesComposition(unsigned int point) const;
private:
	Line* LinesComposition[4];
	Point* vertex[4];
};