#include <Windows.h>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../SoftwareLogic/Line.h"
#include "../SoftwareLogic/SquaresCreator.h"
#include "../SoftwareLogic/Point.h"
#include "../SoftwareLogic/Square.h"
#include "../SoftwareLogic/PointsComparator.h"
#include "../SoftwareLogic/Parameters.h"
#include "SquareDisplay.h"
#include "PointsDisplay.h"
#include <algorithm>
#include <set>
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


/*
ToDO: Mettre cette fonction dans un objet.
*/


int main()
{
	mainWin.setVerticalSyncEnabled(true);
	setlocale(LC_ALL,"");

	Parameters* parameters = new Parameters();

	std::clock_t start2 = std::clock();
	std::cout << (std::clock() - start2)/(double) CLOCKS_PER_SEC << "secondes \n";
	std::vector<Square*> rectangleList;

	std::clock_t start;

	std::multiset<Point*, Point>* points = parameters->getPoints();

	//Création des cercles d'affichage

	mainWin.setFramerateLimit(FRAMELIMIT);
	float nbAffichageCercle = 0;

	PointDisplay pointDisplay(points);
	bool spacePress = false;
	bool squareFound = false;
	while (mainWin.isOpen())
	{

		pointDisplay.DisplayPoints(mainWin);

		//////////////////////////////////////////////////////////////////////////
		// Gestion des événements
		//////////////////////////////////////////////////////////////////////////
		Event event;

		//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu.
		while (mainWin.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				mainWin.close();
			}
			if(event.type == Event::MouseButtonPressed)
			{

				float x = event.mouseButton.x;
				float y = event.mouseButton.y;
				Point* newPoint = new Point(x, y);
				if (points->find(newPoint) ==  points->end())
				{
					pointDisplay.AddPointToSet(newPoint);
				}
				else
				{
					delete newPoint;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// Affichage
		//////////////////////////////////////////////////////////////////////////
		int nbRectangleCompletedDisplay = 0;
		bool flagDisplayUnusedPoint = false;


		mainWin.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			spacePress = true;
		}
		if(spacePress)
		{
			SquareDisplay* squareDisplay = new SquareDisplay();
			if (!squareFound)
			{
				squareFound = true;

				start = std::clock();

				std::multiset<Point*, Point>* unassignedPoints = new std::multiset<Point*, Point>;
   				*(unassignedPoints) = SquaresCreator::findSquares(*(parameters->getSquareList()), points);
 				SquaresCreator::findSquares(*(parameters->getSquareList()), unassignedPoints);
 				delete unassignedPoints;
				std::cout << (std::clock() - start)/(double) CLOCKS_PER_SEC << "secondes";
			}


			if (parameters->getFullblast())
			{
				flagDisplayUnusedPoint = squareDisplay->displayAllRectanglePartially(parameters->getSquareList(), mainWin); 
			}
			else
			{
				flagDisplayUnusedPoint = squareDisplay->displayRectangleOneByOne(parameters->getSquareList(), &nbRectangleCompletedDisplay,mainWin);
			}

			delete squareDisplay;
		}
		if (flagDisplayUnusedPoint)
		{
			pointDisplay.DisplayMissingPoints(mainWin);
		}
		pointDisplay.DisplayPoints(mainWin);
		mainWin.display();
	}
	//////////////////////////////////////////////////////////////////////////
	// Liberation de la mémoire
	//////////////////////////////////////////////////////////////////////////


	//delete displayedPointVector;
	for (std::multiset<Point*,Point>::iterator it = points->begin(); it != points->end(); std::advance(it,1))
	{
		if ((*it)->isUsed() == false)
		{
			delete (*it);
		}
	}
	delete parameters;

	return EXIT_SUCCESS;

}
