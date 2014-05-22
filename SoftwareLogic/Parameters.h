#pragma once
#include "Point.h"
#include "Square.h"
#include "../DataDeposit/XMLReader.h"
#include <set>
#include <vector>

/**
	Classe façade permettant de récolter les informations quant au données importantes retrouvées
	avec le XML. Elle ne fait qu'appeller des méthodes extérieures et conserver des données.
*/
class Parameters
{
public:
	Parameters(void);
	~Parameters(void);

	void findPoints(void);
	void findFullblast(void);

	std::multiset<Point*, Point>* getPoints(void) const;
	std::vector<Square*>* getSquareList(void) const;
	bool getFullblast(void) const;
	void setSquareList(std::vector<Square*>* const squareList);

private:
	std::multiset<Point*, Point>* pointList;
	std::vector<Square*>* squareList;
	bool fullBlast;
	XMLReader* dataReader;
};