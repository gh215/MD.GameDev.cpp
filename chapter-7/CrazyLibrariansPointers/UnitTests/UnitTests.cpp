#include "pch.h"
#include "CppUnitTest.h"
#include "..\CrazyLibrariansPointers\crlibpont.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIOref
{
	TEST_CLASS(UnitTestIOref)
	{
	public:

		TEST_METHOD(AskTextEnterTextTest)
		{
			string name("Indiana");
			istringstream in(name);
			ostringstream out;
			string prompt = "Enter Name:";
			string response = askText(prompt.c_str(), in, out);

			Assert::AreEqual(name.c_str(), response.c_str());
			Assert::AreEqual(prompt.c_str(), out.str().c_str());
		}
		TEST_METHOD(AskTextEnterNumberTest)
		{
			string name("Indiana");
			string num("123");
			istringstream in(num + "\n" + name);
			ostringstream out;
			string prompt = "Enter Name:";
			string err_mess = "The entered value is not a letter. Please try again.\n";
			string corr_out = prompt + err_mess + prompt;
			string response = askText(prompt.c_str(), in, out);

			Assert::AreEqual(name.c_str(), response.c_str());
			Assert::AreEqual(corr_out.c_str(), out.str().c_str());
		}
		TEST_METHOD(AskTextEnterSymbolTest)
		{
			string name("Indiana");
			string symb("!**?(*");
			istringstream in(symb + "\n" + name);
			ostringstream out;
			string prompt = "Enter Name:";
			string err_mess = "The entered value is not a letter. Please try again.\n";
			string corr_out = prompt + err_mess + prompt;
			string response = askText(prompt.c_str(), in, out);

			Assert::AreEqual(name.c_str(), response.c_str());
			Assert::AreEqual(corr_out.c_str(), out.str().c_str());
		}
		TEST_METHOD(AskNumberEnterNumberTest)
		{
			int number = 15;
			istringstream in(to_string(number));
			ostringstream out;
			string prompt = "Enter Number:";
			int response = askNumber(prompt.c_str(), in, out);

			Assert::AreEqual(number, response);
			Assert::AreEqual(prompt.c_str(), out.str().c_str());
		}
		TEST_METHOD(AskNumberEnterTextTest)
		{
			int number = 15;
			string text = "Indiana";
			istringstream in(text + "\n" + to_string(number));
			ostringstream out;
			string prompt = "Enter Number:";
			string err_mess = "The entered value is not a number. Please try again.\n";
			string corr_out = prompt + err_mess + prompt;
			int response = askNumber(prompt.c_str(), in, out);

			Assert::AreEqual(number, response);
			Assert::AreEqual(corr_out.c_str(), out.str().c_str());
		}
		TEST_METHOD(AskNumberEnterSymbolTest)
		{
			int number = 15;
			string symb = "&@#*(&!@";
			istringstream in(symb + "\n" + to_string(number));
			ostringstream out;
			string prompt = "Enter Number:";
			string err_mess = "The entered value is not a number. Please try again.\n";
			string corr_out = prompt + err_mess + prompt;
			int response = askNumber(prompt.c_str(), in, out);

			Assert::AreEqual(number, response);
			Assert::AreEqual(corr_out.c_str(), out.str().c_str());
		}
	};
}
