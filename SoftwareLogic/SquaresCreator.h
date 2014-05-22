#pragma once
#include "Square.h"
#include <vector>
#include <set>


/**
	Classe contenant la logique permettant de retrouver les Squares dans un ensemble de points.
*/
class SquaresCreator
{
public:
	SquaresCreator(void);
	~SquaresCreator(void);

	static std::multiset<Point*, Point> findSquares(std::vector<Square*> &_squareList , std::multiset<Point*, Point>* &_points);
private:

};