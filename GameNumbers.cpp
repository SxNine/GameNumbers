#include <iostream>
#include <random>
using namespace std;
void repeat();

void ClearBuffer()
{
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
    cerr << "\nОшибка ввода. Ожидалось целое число.\n";
}

void HandleInputError(void (*func)())
{
    if (cin.fail())
    {
        ClearBuffer();
        system("pause");
        system("cls");
        func();
    }
}
void help()
{
	cout << "Компьютер загадывает число от 0 до 15 включительно. \nВы должны отгадать число, имея 5 попыток. \nКаждый ход компьютер будет вам давать подсказку.\n\n\n";
}

void Game()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 15);
	int number = dis(gen);
	int count = 5;

	for (int i = 1; i <= count; i++)
	{
		int guess;

		cout << "Попытка " << i << endl;
		cout << "Введите число: "; 
		cin >> guess; 

		HandleInputError(Game);

		if (guess > number)
		{
			cout << "\nХорошая попытка, но моё число меньше.\n\n";
		}
		else if (guess < number)
		{
			cout << "\nХмм... Моё число больше.\n\n";
		}
		else if (guess == number)
		{
			system("cls");
			cout << "\nВы выиграли :) !!\n";
			cout << "\nНажмите любую клавишу для продолжения . . .\n\n";
			cin.get();
			cin.get();
			repeat();
		}

	}
	system("cls");
	cout << "Вы проиграли :(\nЧисло, которое я загадал: " << number << endl;
	cout << "\nНажмите любую клавишу для продолжения . . .\n\n";
	cin.get();
	repeat();


}


void repeat()
{
	int yn;
	cout << "\nХотите повторить попытку? \n1. Да \n2. Выйти из игры.\nВведите цифру: "; cin >> yn;
	
	HandleInputError(repeat);

	switch (yn)
	{
	case 1:
	{
		system("cls");
		help();
		Game();
	}
	case 2:
	{
		exit(69);
		break;
	}
	default:
	{
		cout << "Некорректный ввод . . .\n";
		system("pause");
		system("cls");
		repeat();
		break;

	}
	}

}


int main()
{
	system("chcp 1251>nul");
	help();
	cout << "Я загадал число, попробуй его отгадать!\n\n";
	Game();

	return 0;

}