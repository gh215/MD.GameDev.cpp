#include "pch.h"
#include "CppUnitTest.h"
#include "..\WordKneader\WordKneader.h"
#include <algorithm>

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
	};
}
