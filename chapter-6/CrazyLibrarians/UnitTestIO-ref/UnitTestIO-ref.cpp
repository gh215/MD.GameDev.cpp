#include "pch.h"
#include "CppUnitTest.h"
#include "..\CrazyLibrarians\czlib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIOref
{
	TEST_CLASS(UnitTestIOref)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string name("Indiana");
			istringstream in(name);
			ostringstream out;
			string prompt = "Enter Name:";
			string response = askText(prompt.c_str(), in, out);

			Assert::AreEqual(name.c_str(), response.c_str());
			Assert::AreEqual(prompt.c_str(), out.str().c_str());
		}
	};
}
