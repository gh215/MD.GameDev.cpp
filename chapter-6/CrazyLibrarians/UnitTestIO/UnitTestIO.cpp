#include "pch.h"
#include "CppUnitTest.h"
#include "..\CrazyLibrarians\czlib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIO
{
	TEST_CLASS(UnitTestIO)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string name("Indiana");
			istringstream in(name);
			ostringstream out;
			string prompt = "Enter Name:";
			set_io_streams(&in, &out);
			string response = askText(prompt.c_str());

			Assert::AreEqual(name.c_str(), response.c_str());
			Assert::AreEqual(prompt.c_str(), out.str().c_str());
		}
	};
}
