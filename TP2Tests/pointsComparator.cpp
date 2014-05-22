#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SoftwareLogic/PointsComparator.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define PRECISION 0.01 

namespace TP2Tests
{		
	TEST_CLASS(pointsComparatorTest)
	{
	public:		
		TEST_METHOD(A_IsFloatApproximativelyEqualDonneesValides_DevraitRetournerTrue)
		{
			PointsComparator ptc;
			Assert::AreEqual( true, ptc.isFloatApproximativelyEqual(2.02,2.02,0.2), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( true, ptc.isFloatApproximativelyEqual(2.02,2.03,0.2), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( true, ptc.isFloatApproximativelyEqual(2.02,3,1), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( true, ptc.isFloatApproximativelyEqual(2.02,2.22,0.2), L"Les nombres ne sont pas égaux.", LINE_INFO());
		}

		TEST_METHOD(B_IsFloatApproximativelyEqualDonneesInvalides_DevraitRetournerFalse)
		{
			PointsComparator ptc;
			Assert::AreEqual( false, ptc.isFloatApproximativelyEqual(2.02,2.43,0.2), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( false, ptc.isFloatApproximativelyEqual(3,11,0.2), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( false, ptc.isFloatApproximativelyEqual(2.02,2.20,0), L"Les nombres ne sont pas égaux.", LINE_INFO());
			Assert::AreEqual( false, ptc.isFloatApproximativelyEqual(2.02,23,1), L"Les nombres ne sont pas égaux.", LINE_INFO());
		}


	};
}