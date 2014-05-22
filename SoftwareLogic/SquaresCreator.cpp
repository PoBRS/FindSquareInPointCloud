
#include "SquaresCreator.h"
#include "Point.h"
#include "PointsComparator.h"
#include "../DataDeposit/XMLReader.h"

/**
Constructeur par défaut de SquaresCreator.
*/
SquaresCreator::SquaresCreator()
{

}

/**
Destructeur de SquaresCreator.
*/
SquaresCreator::~SquaresCreator()
{

}

/**
Fonction qui recherche des valeurs possibles de Squares dans un multiset de points.
@param[in] _squareList Vecteur de Squares à remplir.
@param[in] _points Liste des Points parcourus pour identifier des Squares.
@return	pointsLeft Liste des Points non assignés à un Square.
*/
std::multiset<Point*, Point> SquaresCreator::findSquares(std::vector<Square*> &_squareList , std::multiset<Point*, Point>* &_points )
{
	for (std::multiset<Point*, Point>::const_iterator pointIterator = _points->begin(); pointIterator != _points->end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			for (std::multiset<Point*, Point>::const_iterator pointIterator2 = std::next(pointIterator); pointIterator2 != _points->end() && (*pointIterator)->isUsed() == false; std::advance(pointIterator2,1))
			{
				if ((*pointIterator2)->isUsed() == false && *(*pointIterator2) != *(*pointIterator))
				{
					float deltaY = (*pointIterator2)->getY() - (*pointIterator)->getY();
					float deltaX = (*pointIterator2)->getX() - (*pointIterator)->getX();

					if (deltaY < 0)
					{
						deltaX = 0 - deltaX;
					}

					deltaY = abs(deltaY);
					Point* searchedPoint = new Point((*pointIterator)->getX()+deltaY, (*pointIterator)->getY()-deltaX);

					std::multiset<Point*, Point>::const_iterator pointIterator3 = _points->find(searchedPoint);

					delete searchedPoint;

					if (pointIterator3 != _points->end())
					{
						if ((*pointIterator3)->isUsed() == false)
						{
							Point* searchedPoint2 = new Point((*pointIterator2)->getX()+deltaY, (*pointIterator2)->getY()-deltaX);
							std::multiset<Point*, Point>::const_iterator pointIterator4 = _points->find(searchedPoint2);
							delete searchedPoint2;
							if (pointIterator4 != _points->end())
							{
								if ((*pointIterator4)->isUsed() == false)
								{
									_squareList.push_back(new Square(*pointIterator,*pointIterator2, *pointIterator3, *pointIterator4));
									std::cout << _squareList.size() << "    " << *(*pointIterator) << " "<< *(*pointIterator2) << " "<< *(*pointIterator3) << " "<< *(*pointIterator4) << "\n";

								}
							}
						}
					}
				}
			}
		}
	}


	std::multiset<Point*, Point> pointsLeft;

	for (std::multiset<Point*, Point>::const_iterator pointIterator = _points->begin(); pointIterator != _points->end(); std::advance(pointIterator,1))
	{
		if ((*pointIterator)->isUsed() == false)
		{
			pointsLeft.insert((*pointIterator));
		}
	}

	return pointsLeft;

// En utilisant le code suivant: 997 carrés
//	for (std::multiset<Point*, Point>::const_iterator pointIterator = pointsLeft.begin(); pointIterator != pointsLeft.end(); std::advance(pointIterator,1))
//	{
//		if ((*pointIterator)->isUsed() == false)
//		{
//			for (std::multiset<Point*, Point>::const_iterator pointIterator2 = std::next(pointIterator); pointIterator2 != pointsLeft.end() && (*pointIterator)->isUsed() == false; std::advance(pointIterator2,1))
//			{
//				if ((*pointIterator2)->isUsed() == false)
//				{
//					float deltaY = (*pointIterator2)->getY() - (*pointIterator)->getY();
//					float deltaX = (*pointIterator2)->getX() - (*pointIterator)->getX();
//
//					if (deltaY < 0)
//					{
//						deltaX = 0 - deltaX;
//					}
//
//					deltaY = abs(deltaY);
//					Point* searchedPoint = new Point((*pointIterator)->getX()+deltaY, (*pointIterator)->getY()-deltaX);
//
//					std::multiset<Point*, Point>::const_iterator pointIterator3 = pointsLeft.find(searchedPoint);
//
//					delete searchedPoint;
//
//					if (pointIterator3 != pointsLeft.end())
//					{
//						if ((*pointIterator3)->isUsed() == false)
//						{
//							Point* searchedPoint2 = new Point((*pointIterator2)->getX()+deltaY, (*pointIterator2)->getY()-deltaX);
//							std::multiset<Point*, Point>::const_iterator pointIterator4 = pointsLeft.find(searchedPoint2);
//							delete searchedPoint2;
//							if (pointIterator4 != pointsLeft.end())
//							{
//								if ((*pointIterator4)->isUsed() == false)
//								{
//									_squareList.push_back(new Square(*pointIterator,*pointIterator2, *pointIterator3, *pointIterator4));
//									std::cout << _squareList.size() << "    " << *(*pointIterator) << " "<< *(*pointIterator2) << " "<< *(*pointIterator3) << " "<< *(*pointIterator4) << "\n";
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
}