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
			Critter crit(5, 3); // Initial values of hunger and boredom
			istringstream input("2\n4\n0\n"); // User Input: Feed, Wait, Exit

			player_choice(crit, input);

			// Checking for tamagotchi status changes. 
			Assert::IsTrue(crit.GetHunger() == 3); // Hunger must decrease
		}
		TEST_METHOD(TestTamagotchi_BoredomDecrease)
		{
			Critter crit(5, 3);
			istringstream input("3\n4\n0\n"); // User Input: Play, Wait, Exit

			player_choice(crit, input);

			Assert::IsTrue(crit.GetBoredom() == 2); // Boredom should decrease
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

			// Check that the output is as expected
			Assert::IsTrue(output.str().find("I'm feeling hungry.\n") != string::npos);
		}
		TEST_METHOD(TestTamagotchi_FuncEat)
		{
			Critter crit(5, 3);
			ostringstream output;
			crit.Eat(output, 4);

			Assert::IsTrue(crit.GetHunger() == 2);
		}
		TEST_METHOD(TestTamagotchi_FuncPlay)
		{
			Critter crit(5, 3);
			ostringstream output;
			crit.Play(output, 3);

			Assert::IsTrue(crit.GetBoredom() == 1);
		}
		TEST_METHOD(TestTamagotchi_FuncTalk)
		{
			Critter crit(0, 0);
			ostringstream output;
			for (int i = 0; i < 6; i++)
			{
				crit.Wait();
			}
			crit.Talk(output);
			Assert::AreEqual("I'm a critter and I feel frustrated.\n", output.str().c_str());
		}
		TEST_METHOD(TestTamagotchi_FuncShowHunger)
		{
			Critter crit(15, 3);
			ostringstream output;

			crit.ShowHunger(output);

			Assert::IsTrue(output.str() == "I'm feeling extremely hungry.\n");
		}
		TEST_METHOD(TestTamagotchi_FuncShowBoredom)
		{
			Critter crit(5, 10);
			ostringstream output;

			crit.ShowBoredom(output);

			Assert::IsTrue(output.str() == "I'm very bored.\n");
		}

	};
}
