#include "pch.h"
#include "..\GuessTheNumberV2\gtn.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(NumGenTest)
		{
			int ng = num_gen(1, 100);
			Assert::IsTrue(ng >= 1 && ng <= 100);
		}
		TEST_METHOD(NumGenNegTest)
		{
			int ng = num_gen(-100, -1);
			Assert::IsTrue(ng <= -1 && ng >= -100);
		}
		TEST_METHOD(NumGenZeroTest)
		{
			int ng = num_gen(0, 0);
			Assert::IsTrue(ng == 0);
		}
		TEST_METHOD(BordReductTest)
		{
			int min = 1, max = 100;
			bord_reduct(50, BIG, min, max);
			Assert::AreEqual(1, min);
			Assert::AreEqual(49, max);

			min = 1, max = 100;
			bord_reduct(50, SMALL, min, max);
			Assert::AreEqual(51, min);
			Assert::AreEqual(100, max);
		}

	};
}
