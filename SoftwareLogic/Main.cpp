#include "MyRectangle.h"
#include <Windows.h>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Line.h"
#include "Point.h"
#include "pugixml.hpp"
#include "XMLReader.h"
#include <algorithm>
#include <set>
#include "PointsComparator.h"
#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <vld.h>



#define LARGEUR 1024
#define HAUTEUR 780
#define FRAMELIMIT 60

#define ORIGINE_Y 100
#define ORIGINE_X 300
#define SOMMET 150

//namespace SFML
using namespace sf;

//La fenêtre principale

RenderWindow mainWin(VideoMode(LARGEUR, HAUTEUR, 32), "Lab 6 - Rectangle");

void displayAllPoints(std::vector<CircleShape>* _pointsVector)
{
	for (std::vector<CircleShape>::const_iterator pointIterator = _pointsVector->begin(); pointIterator != _pointsVector->end(); std::advance(pointIterator,1))
	{
		mainWin.draw(*pointIterator);
	}
}

bool displayAllRectanglePartially(std::vector<MyRectangle*>* _rectangleVector)
{
	bool areRectangleDisplayCompleted = false;
	for (std::vector<MyRectangle*>::iterator rectangleIterator = _rectangleVector->begin(); rectangleIterator != _rectangleVector->end(); std::advance(rectangleIterator,1))
	{
		areRectangleDisplayCompleted = (*rectangleIterator)->Display(mainWin, FRAMELIMIT);
	}
	return areRectangleDisplayCompleted;
}

bool displayRectangleOneByOne(std::vector<MyRectangle*>* _rectangleVector, int* _nbRectangleCompletedDisplay)
{
	for (unsigned int i = 0; i < _rectangleVector->size(); i++)
	{
		if (i < *_nbRectangleCompletedDisplay)
		{
			_rectangleVector->at(i)->Display(mainWin, 0);
		}
		else if (i == *_nbRectangleCompletedDisplay)
		{
			bool isRectangleDisplayCompleted = _rectangleVector->at(i)->Display(mainWin, FRAMELIMIT);
			if (isRectangleDisplayCompleted)
			{
				(*_nbRectangleCompletedDisplay)++;
			}
		}

	}
	return (*_nbRectangleCompletedDisplay == _rectangleVector->size()); // true if all displayed. if not: false;
	
}
void displayCircleMissingPoint(std::multiset<Point*, Point>* _multisetPoints, double _rayon)
{
	for(std::multiset<Point*, Point>::const_iterator pointIterator = _multisetPoints->begin(); pointIterator != _multisetPoints->end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			CircleShape cercle(_rayon);
			cercle.setOutlineThickness(1);
			cercle.setOutlineColor(Color::Red);
			cercle.setFillColor(Color::Transparent);
			float posX = (*pointIterator)->getX() - _rayon;
			float posY = (*pointIterator)->getY() - _rayon;
			cercle.setPosition(posX,posY);
			mainWin.draw(cercle);
		}
	}
}
/*
	ToDO: Mettre cette fonction dans un objet.
*/


int main()
{
	mainWin.setVerticalSyncEnabled(true);
	setlocale(LC_ALL,"");

	XMLReader xmlReader;
	bool fullBlast = xmlReader.getXMLFullBlast();
	std::clock_t start2 = std::clock();
	std::multiset<Point*, Point>* points = xmlReader.getXMLPoints();
	std::cout << (std::clock() - start2)/(double) CLOCKS_PER_SEC << "secondes \n";
	std::vector<MyRectangle*> rectangleList;

	std::clock_t start;
	start = std::clock();

	for (std::multiset<Point*, PointsComparator>::const_iterator pointIterator = points->begin(); pointIterator != points->end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			for (std::multiset<Point*, PointsComparator>::const_iterator pointIterator2 = std::next(pointIterator); pointIterator2 != points->end() && (*pointIterator)->isUsed() == false; std::advance(pointIterator2,1))
			{
				if ((*pointIterator2)->isUsed() == false)
				{
					float deltaY = (*pointIterator2)->getY() - (*pointIterator)->getY();
					float deltaX = (*pointIterator2)->getX() - (*pointIterator)->getX();

					if (deltaY < 0)
					{
						deltaX = 0 - deltaX;
					}

					deltaY = abs(deltaY);
					Point* searchedPoint = new Point((*pointIterator)->getX()+deltaY, (*pointIterator)->getY()-deltaX);

					std::multiset<Point*, Point>::const_iterator pointIterator3 = points->find(searchedPoint);

					delete searchedPoint;

					if (pointIterator3 != points->end())
					{
						if ((*pointIterator3)->isUsed() == false)
						{
							Point* searchedPoint2 = new Point((*pointIterator2)->getX()+deltaY, (*pointIterator2)->getY()-deltaX);
							std::multiset<Point*, Point>::const_iterator pointIterator4 = points->find(searchedPoint2);
							delete searchedPoint2;
							if (pointIterator4 != points->end())
							{
								if ((*pointIterator4)->isUsed() == false)
								{
									rectangleList.push_back(new MyRectangle(*pointIterator,*pointIterator2, *pointIterator3, *pointIterator4));
									std::cout << rectangleList.size() << "    " << *(*pointIterator) << " "<< *(*pointIterator2) << " "<< *(*pointIterator3) << " "<< *(*pointIterator4) << "\n";
								}
							}
						}
					}
				}
			}
		}
	}
	

	std::multiset<Point*, PointsComparator> pointsLeft;

	for (std::multiset<Point*, Point>::const_iterator pointIterator = points->begin(); pointIterator != points->end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			pointsLeft.insert((*pointIterator));
		}
	}
	for (std::multiset<Point*, Point>::const_iterator pointIterator = pointsLeft.begin(); pointIterator != pointsLeft.end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			for (std::multiset<Point*, Point>::const_iterator pointIterator2 = std::next(pointIterator); pointIterator2 != pointsLeft.end() && (*pointIterator)->isUsed() == false; std::advance(pointIterator2,1))
			{
				if ((*pointIterator2)->isUsed() == false)
				{
					float deltaY = (*pointIterator2)->getY() - (*pointIterator)->getY();
					float deltaX = (*pointIterator2)->getX() - (*pointIterator)->getX();

					if (deltaY < 0)
					{
						deltaX = 0 - deltaX;
					}

					deltaY = abs(deltaY);
					Point* searchedPoint = new Point((*pointIterator)->getX()+deltaY, (*pointIterator)->getY()-deltaX);

					std::multiset<Point*, Point>::const_iterator pointIterator3 = pointsLeft.find(searchedPoint);

					delete searchedPoint;

					if (pointIterator3 != pointsLeft.end())
					{
						if ((*pointIterator3)->isUsed() == false)
						{
							Point* searchedPoint2 = new Point((*pointIterator2)->getX()+deltaY, (*pointIterator2)->getY()-deltaX);
							std::multiset<Point*, Point>::const_iterator pointIterator4 = pointsLeft.find(searchedPoint2);
							delete searchedPoint2;
							if (pointIterator4 != pointsLeft.end())
							{
								if ((*pointIterator4)->isUsed() == false)
								{
									rectangleList.push_back(new MyRectangle(*pointIterator,*pointIterator2, *pointIterator3, *pointIterator4));
									std::cout << rectangleList.size() << "    " << *(*pointIterator) << " "<< *(*pointIterator2) << " "<< *(*pointIterator3) << " "<< *(*pointIterator4) << "\n";
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout << (std::clock() - start)/(double) CLOCKS_PER_SEC << "secondes";


	//Création des cercles d'affichage
	std::vector<CircleShape>* displayedPointVector = new std::vector<CircleShape>;
	for(std::multiset<Point*, PointsComparator>::const_iterator pointIterator = points->begin(); pointIterator != points->end(); std::advance(pointIterator,1))
	{
		CircleShape pointToDisplay(0.5);
		pointToDisplay.setPosition((*pointIterator)->getX(),(*pointIterator)->getY());
		displayedPointVector->push_back(pointToDisplay);
	}
	mainWin.setFramerateLimit(FRAMELIMIT);
	int nbAffichageCercle = 0;
	while (mainWin.isOpen())
	{

		//////////////////////////////////////////////////////////////////////////
		// Gestion des événements
		//////////////////////////////////////////////////////////////////////////
		Event event;

		//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
		while (mainWin.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				mainWin.close();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// Affichage
		//////////////////////////////////////////////////////////////////////////
		int nbRectangleCompletedDisplay = 0;
		bool flagDisplayUnusedPoint = false;


		mainWin.clear();
		displayAllPoints(displayedPointVector);
		
		if (fullBlast)
		{
			flagDisplayUnusedPoint = displayAllRectanglePartially(&rectangleList);	
		}
		else
		{
			flagDisplayUnusedPoint = displayRectangleOneByOne(&rectangleList, &nbRectangleCompletedDisplay);
		}

		if (flagDisplayUnusedPoint)
		{
			displayCircleMissingPoint(points, std::min(0.5 + nbAffichageCercle,50.0));
			nbAffichageCercle++;
		}

		
		mainWin.display();
	}

	//////////////////////////////////////////////////////////////////////////
	// Liberation de la mémoire
	//////////////////////////////////////////////////////////////////////////
	for (std::vector<MyRectangle*>::iterator rectangleIterator = rectangleList.begin(); rectangleIterator != rectangleList.end(); std::advance(rectangleIterator,1))
	{
		delete *rectangleIterator;
	}
	for(std::multiset<Point*, PointsComparator>::const_iterator pointIterator = points->begin(); pointIterator != points->end(); std::advance(pointIterator,1))
	{
		if (!(*pointIterator)->isUsed())
		{
			delete *pointIterator;
		}
	}
	delete displayedPointVector;
	delete points;
	return EXIT_SUCCESS;

}
