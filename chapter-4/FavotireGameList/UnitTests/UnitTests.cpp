#include "pch.h"
#include "CppUnitTest.h"
#include "..\FavotireGameList\favgamelist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestAddGameNewGame)
		{
			vector<string>gameList;
			istringstream input("Dota");
			ostringstream output;
			add_game(gameList, input, output);

			Assert::AreEqual(static_cast<size_t>(1), gameList.size());
			Assert::AreEqual(std::string("Dota"), gameList[0]);
		}
        TEST_METHOD(TestAddGameExistingGame)
        {
            vector<string> gameList{"Warcraft"};
            istringstream input("Warcraft");
            ostringstream output;

            add_game(gameList, input, output);    
            /*
            Эта конструкция используется для явного приведения типа числового литерала 2 к типу size_t. 
            size_t - это беззнаковый целочисленный тип, который обычно используется для представления размеров или индексов
            */
            Assert::AreEqual(static_cast<size_t>(1), gameList.size());
        }

        TEST_METHOD(TestDeleteGameExistingGame)
        {
            vector<string> gameList{ "Dota", "Warcraft", "Warhammer" };
            istringstream input("Warcraft");
            ostringstream output;

            delete_game(gameList, input, output);          
            Assert::AreEqual(static_cast<size_t>(2), gameList.size());
            Assert::AreEqual(string("Dota"), gameList[0]);
            Assert::AreEqual(string("Warhammer"), gameList[1]);
        }

        TEST_METHOD(TestDeleteGameNonExistingGame)
        {
            vector<string> gameList{ "Dota", "Warcraft" };
            istringstream input("Warhammer");
            ostringstream output;

            delete_game(gameList, input, output);           
            Assert::AreEqual(static_cast<size_t>(2), gameList.size());
        }

        TEST_METHOD(TestPrintGameListWithGames)
        {
            vector<string> gameList{ "Dota", "Warcraft", "Warhammer" };
            ostringstream output;

            print_game_list(gameList, output);
            Assert::AreEqual(std::string("\nНа данный момент у вас 3 игр и среди них: \n Dota\n Warcraft\n Warhammer\n"), output.str());
        }

        TEST_METHOD(TestPrintGameListWithoutGames)
        {
            vector<string> gameList;
            ostringstream output;

            print_game_list(gameList, output);
            Assert::AreEqual(std::string("Извините, но в вашей библиотеке нет игр"), output.str());
        }
	};
}
