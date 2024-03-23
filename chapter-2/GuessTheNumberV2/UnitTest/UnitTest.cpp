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
			istringstream in(to_string(BIG));
			ostringstream out;
			int result = ask_user(cn, min, max, in, out);

			Assert::IsTrue(BIG == result);

			istringstream in2(to_string(SMALL));
			ostringstream out2;
			result = ask_user(cn, min, max, in2, out2);

			Assert::IsTrue(SMALL == result);

			istringstream in3(to_string(CORRECT));
			ostringstream out3;

			result = ask_user(cn, min, max, in3, out3);

			Assert::IsTrue(CORRECT == result);

		}
		TEST_METHOD(AskUserIncorrectInput)
		{
			int min = 1, max = 10;
			int cn = 5;
			istringstream in("4\n" + to_string(BIG));
			ostringstream out;
			int result = ask_user(cn, min, max, in, out);

			Assert::IsTrue(BIG == result);

			istringstream in2("4\n" + to_string(SMALL));
			ostringstream out2;
			result = ask_user(cn, min, max, in2, out2);

			Assert::IsTrue(SMALL == result);
		}

	};
}
