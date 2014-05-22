#include "PointsDisplay.h"

PointDisplay::PointDisplay(std::multiset<Point*, Point>* _multisetPoints)
{
	this->rayonMissingCercle = 0.0;
	this->pointDisplayVector = new std::vector<sf::CircleShape*>;

	for(std::multiset<Point*, PointsComparator>::const_iterator it = _multisetPoints->begin(); it != _multisetPoints->end(); std::advance(it,1))
	{
		sf::CircleShape* pointToDisplay = new sf::CircleShape(0.5);
		pointToDisplay->setPosition((*it)->getX(),(*it)->getY());
		this->pointDisplayVector->push_back(pointToDisplay);
	}

	this->allPointsSet = _multisetPoints;
}
PointDisplay::~PointDisplay(void)
{
	for (std::vector<sf::CircleShape*>::iterator it = this->pointDisplayVector->begin(); it != this->pointDisplayVector->end(); std::advance(it,1))
	{
		delete (*it);
	}
	delete pointDisplayVector;
}

void PointDisplay::DisplayPoints(sf::RenderWindow& _mainWin) const
{
	for(std::vector<sf::CircleShape*>::iterator it = this->pointDisplayVector->begin(); it != this->pointDisplayVector->end(); std::advance(it,1))
	{
		_mainWin.draw(*(*it));
	}
}
void PointDisplay::AddPointToSet(Point* _point)
{
	this->allPointsSet->insert(_point);
	sf::CircleShape* pointToDisplay = new sf::CircleShape(0.5);
	pointToDisplay->setPosition(_point->getX(),_point->getY());
	this->pointDisplayVector->push_back(pointToDisplay);

}
void PointDisplay::DisplayMissingPoints(sf::RenderWindow& _mainWin)
{
	for(std::multiset<Point*, PointsComparator>::const_iterator it = this->allPointsSet->begin(); it != this->allPointsSet->end(); std::advance(it,1))
	{
		if ((*it)->isUsed() == false)
		{
			sf::CircleShape cercle(this->rayonMissingCercle);
			cercle.setOutlineThickness(1);
			cercle.setOutlineColor(sf::Color::Red);
			cercle.setFillColor(sf::Color::Transparent);
			float posX = (*it)->getX() - this->rayonMissingCercle;
			float posY = (*it)->getY() - this->rayonMissingCercle;
			cercle.setPosition(posX,posY);
			_mainWin.draw(cercle);
		}
	}
	if (this->rayonMissingCercle < 50)
	{
		this->rayonMissingCercle += 1.0;
	}
}