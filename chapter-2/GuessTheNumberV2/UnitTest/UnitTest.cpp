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
		TEST_METHOD(AskUserCorrectInput)
		{
			int min = 1, max = 10;
			int cn = 5;
			istringstream in("2\n");
			ostringstream out;
			int result = ask_user(cn, min, max, in, out);

			Assert::AreEqual(to_string(BIG), to_string(result));
		}
		TEST_METHOD(AskUserIncorrectInput)
		{
			int min = 1, max = 10;
			int cn = 5;
			istringstream in("4\n2\n");
			ostringstream out;

			int result = ask_user(cn, min, max, in, out);

			Assert::AreEqual(to_string(BIG), to_string(result));
		}
		TEST_METHOD(AskUserMaxBorder)
		{
			int min = 1, max = 10;
			int cn = 10;
			istringstream in("3");
			ostringstream out;

			int result = ask_user(cn, min, max, in, out);

			Assert::AreEqual(to_string(CORRECT), to_string(result));
		}		
		TEST_METHOD(AskUserMinBorder)
		{
			int min = 1, max = 10;
			int cn = 1;
			istringstream in("3");
			ostringstream out;

			int result = ask_user(cn, min, max, in, out);

			Assert::AreEqual(to_string(CORRECT), to_string(result));
		}

	};
}
