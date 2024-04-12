#include "pch.h"
#include "CppUnitTest.h"
#include "..\TamagotchiNewMenu\Tamagotchi.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:		
		TEST_METHOD(TestTamagotchi_HungerDecrease)
		{
            Critter crit(5, 3); // Начальные значения голода и скуки
            istringstream input("2\n4\n0\n"); // Ввод пользователя: Покормить, Подождать, Выход

            player_choice(crit, input);

            // Проверка изменения состояния тамагочи
            Assert::IsTrue(crit.GetHunger() < 5); // Голод должен уменьшиться
		}
        TEST_METHOD(TestTamagotchi_BoredomDecrease)
        {
            Critter crit(5, 3); 
            istringstream input("3\n4\n0\n"); // Ввод пользователя: Поиграть, Подождать, Выход

            player_choice(crit, input);

            Assert::IsTrue(crit.GetBoredom() < 3); // Скука должна уменьшиться
        }
        TEST_METHOD(TestTamagotchi_WaitIncrease)
        {
            Critter crit(5, 3); 
            istringstream input("4\n0\n"); 

            player_choice(crit, input);

            Assert::IsTrue(crit.GetBoredom() == 4); 
            Assert::IsTrue(crit.GetHunger() == 6); 
        }
        TEST_METHOD(TestTamagotchi_FeelingsExpression)
        {
            Critter crit(5, 3);
            ostringstream output;
            crit.ShowHunger(output);

            // Проверка, что вывод соответствует ожидаемому
            Assert::IsTrue(output.str().find("I'm feeling") != string::npos);
        }
	};
}
