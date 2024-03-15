#include "pch.h"
#include "CppUnitTest.h"
#include "..\GameHangman\hang.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
        TEST_METHOD(TestGetWord)
        {
            string got_word = get_word();
            Assert::IsTrue(got_word == "GUESS" || got_word == "HANGMAN" || got_word == "DIFFICULT");
        }
        TEST_METHOD(TestGetInitSoFar)
        {
            string word = "HELLO";
            string soFar = get_init_soFar(word);
            Assert::AreEqual(string(word.size(), '-'), soFar);
        }
        TEST_METHOD(TestGetUserVar_NewChar) 
        {
            string used = "";
            char guess = get_user_var(used);
            Assert::AreEqual('A', guess);
        }
        TEST_METHOD(TestGetUserVar_UsedChar)
        {
            string used = "A";
            char guess = get_user_var(used);
            Assert::AreEqual('B', guess);
        }
        TEST_METHOD(TestGetUpdateSoFarNoMatch)
        {
            string word = "HELLO";
            string soFar = "-----";
            char guess = 'X';
            string updSoFar = get_upd_SoFar(word, soFar, guess);
            Assert::IsTrue("-----");
        }
        TEST_METHOD(TestGetUpdateSoFarSingleMatch)
        {
            string word = "HELLO";
            string soFar = "-----";
            char guess = 'H';
            string updSoFar = get_upd_SoFar(word, soFar, guess);
            Assert::IsTrue("H----");
        }
        TEST_METHOD(TestGetUpdateSoFarMultipleMatches)
        {
            string word = "HELLO";
            string soFar = "-----";
            char guess = 'L';
            string updSoFar = get_upd_SoFar(word, soFar, guess);
            Assert::IsTrue("--LL-");
        }
	};
}
