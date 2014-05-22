#pragma once
#include "Point.h"
#include "Square.h"
#include "../DataDeposit/XMLReader.h"
#include <set>
#include <vector>

/**
	Classe fa�ade permettant de r�colter les informations quant au donn�es importantes retrouv�es
	avec le XML. Elle ne fait qu'appeller des m�thodes ext�rieures et conserver des donn�es.
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