#pragma once
#include "SFML/Graphics.hpp"
#include "../SoftwareLogic/Point.h"
#include <set>

class PointDisplay
{
public:
	PointDisplay(std::multiset<Point*, Point>* _multisetPoints);
	~PointDisplay(void);
	void DisplayPoints(sf::RenderWindow& _mainWin) const;
	void DisplayMissingPoints(sf::RenderWindow& _mainWin);
	void AddPointToSet(Point* _point);
private:
	std::vector<sf::CircleShape*>* pointDisplayVector;
	std::multiset<Point*, Point>* allPointsSet;
	float rayonMissingCercle;

};