#include "Tamagotchi.h"

/* Псевдокод
Создать тамагочи
Если пользователь не собирается завершить игру
Представить ему меню с вариантами выбора
Если пользователь хочет выслушать тамагочи
Предложить тамагочи что-то сообщить
Если пользователь хочет покормить тамагочи
Предложить тамагочи поесть
Если пользователь хочет поиграть с тамагочи
Предложить тамагочи поиграть
*/

Critter::Critter(int hunger, int boredom):
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void help(ostream& output)
{
	output << "\nCritter Caretaker\n\n";
	output << "0 - Quit\n";
	output << "1 - Check your critter\n";
	output << "2 - Feed your critter\n";
	output << "3 - Play with your critter\n";
	output << "4 - Wait\n";
	output << "5 - Check your critter's hunger and boredom\n";
	output << "6 - Help" << endl;
}

void player_choice(Critter& crit, istream& input, ostream& output)
{
	output << "\nWelcome to the Critter Caretaker! Please, choose one option below.\n\n";
	output << "0 - Quit\n";
	output << "1 - Check your critter\n";
	output << "2 - Feed your critter\n";
	output << "3 - Play with your critter\n";
	output << "4 - Wait\n";
	output << "5 - Check your critter's hunger and boredom\n";
	output << "6 - Help" << endl;
	int choice;
	do
	{
		output << "\nYour choice: ";
		input >> choice;
		switch (choice)
		{
		case 0:
			output << "Goodbye! See ya next time!\n";
			break;
		case 1:
			crit.Talk(output);
			break;
		case 2:
			crit.Eat(output, 4);
			break;
		case 3:
			crit.Play(output, 4);
			break;
		case 4:
			crit.Wait();
			break;
		case 5:
			cout << "_______________" << endl;
			output << "Hunger: " << crit.GetHunger() << endl;
			output << "Boredom: " << crit.GetBoredom() << endl;
			crit.ShowHunger(output);
			crit.ShowBoredom(output);
			cout << "_______________" << endl;
			break;
		case 6:
			help();
			break;
		default:
			output << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

int Critter::GetBoredom() const
{
	return m_Boredom;
}

void Critter::Talk(ostream& output)
{
	output << "I'm a critter and I feel ";
	int mood = GetMood();
	if (mood > 15)
	{
		output << "mad.\n";
	}
	else if (mood > 10)
	{
		output << "frustrated.\n";
	}
	else if (mood > 5)
	{
		output << "okay.\n";
	}
	else
	{
		output << "happy.\n";
	}
	PassTime();
}

void Critter::Eat(ostream& output, int food)
{
	output << "Bruuppp... Sorry!\n";
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	PassTime();
}

void Critter::Play(ostream& output, int fun)
{
	output << "Wheeeee!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	PassTime();
}

void Critter::Wait(ostream& output)
{
	output << "You've been waiting for a while..." << endl;
	PassTime();
}

void Critter::ShowHunger(ostream& output)
{
	output << "I'm feeling ";
	if (m_Hunger >= 12) 
	{
		output << "extremely hungry. ";
	}
	else if (m_Hunger >= 9) 
	{
		output << "very hungry. ";
	}
	else if (m_Hunger >= 5) 
	{
		output << "hungry. ";
	}
	else if (m_Hunger >= 3) 
	{
		output << "a bit hungry. ";
	}
	else {
		output << "not hungry at all. ";
	}
}

void Critter::ShowBoredom(ostream& output)
{
	if (m_Boredom >= 12) 
	{
		output << "\nI'm extremely bored.\n";
	}
	else if (m_Boredom >= 9) 
	{
		output << "\nI'm very bored.\n";
	}
	else if (m_Boredom >= 5) 
	{
		output << "\nI'm bored.\n";
	}
	else if (m_Boredom >= 3) 
	{
		output << "\nI'm a bit bored.\n";
	}
	else {
		output << "\nI'm not bored at all.\n";
	}
}
