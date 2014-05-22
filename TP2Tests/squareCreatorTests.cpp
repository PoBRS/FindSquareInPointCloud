#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SoftwareLogic/Point.h"
#include "../SoftwareLogic/SquaresCreator.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define PRECISION 0.01 

namespace TP2Tests
{		
	TEST_CLASS(squareCreatorTests)
	{
	private:
		bool IsEqualSquareListSize(int valeur, std::vector<Square*> &squareList)
		{
			return squareList.size() == valeur;
		}
	public:		
		TEST_METHOD(A_FindSquaresCarreDroitValide_DevraitRetournerListeCarreSize2)
		{
			std::vector<Square*> squareList;
			std::multiset<Point*, Point>* points = new std::multiset<Point*, Point>;
			SquaresCreator squaresCreator;
			Point* newPoint0 = new Point(397.28, 406.78);
			Point* newPoint1 = new Point(438.14, 327);
			Point* newPoint2 = new Point(384.8, 380.42);
			Point* newPoint3 = new Point(384.8, 327);
			Point* newPoint4 = new Point(397.28, 356.4);
			Point* newPoint5 = new Point(346.9, 356.4);
			Point* newPoint6 = new Point(438.14, 380.42);
			Point* newPoint7 = new Point(346.9, 406.78);

			points->insert(newPoint0);
			points->insert(newPoint1);
			points->insert(newPoint2);
			points->insert(newPoint3);
			points->insert(newPoint4);
			points->insert(newPoint5);
			points->insert(newPoint6);
			points->insert(newPoint7);

			squaresCreator.findSquares(squareList,points);
			delete points;
			Assert::AreEqual( true, IsEqualSquareListSize(2,squareList), L"Le nombre de carrés retrouvés ne correspond pas au total attendu.", LINE_INFO());
		}


		TEST_METHOD(B_FindSquaresCarreAvecRotationValide_DevraitRetournerListeCarreSize2)
		{
			std::vector<Square*> squareList;
			std::multiset<Point*, Point>* points = new std::multiset<Point*, Point>;
			SquaresCreator squaresCreator;
			Point* newPoint0 = new Point(608.72, 444.3);
			Point* newPoint1 = new Point(384.8, 380.42);
			Point* newPoint2 = new Point(151.8, 322.4);
			Point* newPoint3 = new Point(93.8, 555.304);
			Point* newPoint4 = new Point(424.22, 252.2);
			Point* newPoint5 = new Point(654.7, 471.9);
			Point* newPoint6 = new Point(326.78, 613.34);
			Point* newPoint7 = new Point(686.8, 467.22);
			Point* newPoint8 = new Point(429.6, 477.28);
			Point* newPoint9 = new Point(636.32, 494.82);
			Point* newPoint10 = new Point(659.24, 416.7);

			points->insert(newPoint0);
			points->insert(newPoint1);
			points->insert(newPoint2);
			points->insert(newPoint3);
			points->insert(newPoint4);
			points->insert(newPoint5);
			points->insert(newPoint6);
			points->insert(newPoint7);
			points->insert(newPoint8);
			points->insert(newPoint9);
			points->insert(newPoint10);
			squaresCreator.findSquares(squareList,points);
			delete points;
			Assert::AreEqual( true, IsEqualSquareListSize(2,squareList), L"Le nombre de carrés retrouvés ne correspond pas au total attendu.", LINE_INFO());

		}

		
		TEST_METHOD(C_FindSquaresCarreDonneesInvalides_DevraitRetournerListeCarreSize0)
		{
			std::vector<Square*> squareList;
			std::multiset<Point*, Point>* points = new std::multiset<Point*, Point>;
			SquaresCreator squaresCreator;

			Point* newPoint0 = new Point(12, 3);
			Point* newPoint1 = new Point(12, 8);
			Point* newPoint2 = new Point(88, 7777);
			Point* newPoint3 = new Point(55, 555.304);
			Point* newPoint4 = new Point(3123, 6756);
			Point* newPoint5 = new Point(62345, 32);
			Point* newPoint6 = new Point(21, 22222);
			Point* newPoint7 = new Point(34, 8786);

			points->insert(newPoint0);
			points->insert(newPoint1);
			points->insert(newPoint2);
			points->insert(newPoint3);
			points->insert(newPoint4);
			points->insert(newPoint5);
			points->insert(newPoint6);
			points->insert(newPoint7);

			squaresCreator.findSquares(squareList,points);
			delete points;
			Assert::AreEqual( true, IsEqualSquareListSize(0,squareList), L"Le nombre de carrés retrouvés ne correspond pas au total attendu.", LINE_INFO());

		}

	};
}