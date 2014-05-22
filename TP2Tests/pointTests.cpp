#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SoftwareLogic/Point.h"
#include "../SoftwareLogic/SquaresCreator.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define PRECISION 0.01 

namespace TP2Tests
{		
	TEST_CLASS(pointTests)
	{
	public:		
		TEST_METHOD(A_OperateurPlusPetit_EntrePointPlusPetitEtPointPlusGrand_DevraitRetournerTrue)
		{
			Point pointA(3,5);
			Point pointB(3,6);
			Point pointC(4,1);
			Assert::AreEqual( true, pointA < pointB, L"Le premier point n'est pas plus petit.", LINE_INFO());
			Assert::AreEqual( true, pointB < pointC, L"Le premier point n'est pas plus petit.", LINE_INFO());
			Assert::AreEqual( true, pointA < pointC, L"Le premier point n'est pas plus petit.", LINE_INFO());

		}


		TEST_METHOD(B_OperateurPlusPetit_EntrePointPlusGrandEtPointPlusPetit_DevraitRetournerFalse)
		{

			Point pointA(3,5);
			Point pointB(3,6);
			Point pointC(4,1);

			Assert::AreEqual( false, pointC < pointA,L"Le premier point devrait être plus grand.", LINE_INFO());
			Assert::AreEqual( false,pointB < pointA, L"Le premier point devrait être plus grand.", LINE_INFO());
			Assert::AreEqual( false,pointA < pointA, L"Le premier point devrait être plus grand.", LINE_INFO());

		}

		TEST_METHOD(A_OperateurEgal_EntrePointsApproximativementEgaux_DevraitRetournerTrue)
		{

			Point pointA(3,5);
			Point pointB(3,5);
			Point pointC(4,1);
			Point pointD(4.1,1.19);

			Assert::AreEqual( true, pointA == pointB, L"Le premier point n'est pas plus petit.", LINE_INFO());
			Assert::AreEqual( true, pointC == pointC, L"Le premier point n'est pas plus petit.", LINE_INFO());
			Assert::AreEqual( true, pointC == pointD, L"Le premier point n'est pas plus petit.", LINE_INFO());

		}

		TEST_METHOD(B_OperateurEgal_EntrePointsInegaux_DevraitRetournerFalse)
		{

			Point pointA(3,5);
			Point pointB(7,5);
			Point pointC(4,1);
			Point pointD(4,2);
			Point pointE(4.1,1.21);
				
			Assert::AreEqual( false, pointA == pointB, L"Le premier point devrait être plus grand.", LINE_INFO());
			Assert::AreEqual( false, pointC == pointD, L"Le premier point devrait être plus grand.", LINE_INFO());
			Assert::AreEqual( false, pointC == pointE, L"Le premier point devrait être plus grand.", LINE_INFO());
		}
	};
}