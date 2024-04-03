#include "pch.h"
#include "CppUnitTest.h"
#include "..\WordKneader\WordKneader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(PermuteTest)
		{
			string in = "Difficult";
			string out;
			bool diff = false;
			for (int i = 0; i < 3; i++)
			{
				out = permute(in);
				if (out != in)
				{
					diff = true;
				}
			}
			Assert::IsTrue(diff);
		}

		TEST_METHOD(PermuteSizeTest)
		{
			string in = "Difficult";
			string out;
			out = permute(in);
			Assert::IsTrue(in.size() == out.size());
		}

		TEST_METHOD(PermuteSortTest)
		{
			string in = "Difficult";
			string out;
			out = permute(in);
			sort(in.begin(), in.end());
			sort(out.begin(), out.end());
			Assert::AreEqual(in, out);
		}
		TEST_METHOD(TestAction_Correct_NoHint)
		{
			istringstream in("wall");
			string theWord = "wall";
			string theHint = "Чувствуешь ли ты, что бьёшься головой о что-то?";

			int result = action(theWord, theHint, in);
			
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(TestGetUserGuess_Correct_Hint)
		{
			istringstream in("hint\nwall");
			string theWord = "wall";
			string theHint = "Чувствуешь ли ты, что бьёшься головой о что-то?";

			int result = action(theWord, theHint, in);

			Assert::AreEqual(1, result);
		}
		TEST_METHOD(TestGetUserIncorrectThenCorrect)
		{
			istringstream in("incorrect\nlabored");
			string theWord = "labored";
			string theHint = "Слишком медленно, не так ли?";

			int result = action(theWord, theHint, in);

			Assert::AreEqual(7, result);
		}
		TEST_METHOD(TestGetUserGuess_QuitGame)
		{
			istringstream in("quit");
			string theWord = "persistent";
			string theHint = "Продолжайте в том же духе!";
			bool usedHint = true;

			int result = action(theWord, theHint, in);

			Assert::AreEqual(0, result);
		}

	};
}
