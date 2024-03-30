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
    cerr << "\n������ �����. ��������� ����� �����.\n";
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
	cout << "��������� ���������� ����� �� 0 �� 15 ������������. \n�� ������ �������� �����, ���� 5 �������. \n������ ��� ��������� ����� ��� ������ ���������.\n\n\n";
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

		cout << "������� " << i << endl;
		cout << "������� �����: "; 
		cin >> guess; 

		HandleInputError(Game);

		if (guess > number)
		{
			cout << "\n������� �������, �� �� ����� ������.\n\n";
		}
		else if (guess < number)
		{
			cout << "\n���... �� ����� ������.\n\n";
		}
		else if (guess == number)
		{
			system("cls");
			cout << "\n�� �������� :) !!\n";
			cout << "\n������� ����� ������� ��� ����������� . . .\n\n";
			cin.get();
			cin.get();
			repeat();
		}

	}
	system("cls");
	cout << "�� ��������� :(\n�����, ������� � �������: " << number << endl;
	cout << "\n������� ����� ������� ��� ����������� . . .\n\n";
	cin.get();
	repeat();


}


void repeat()
{
	int yn;
	cout << "\n������ ��������� �������? \n1. �� \n2. ����� �� ����.\n������� �����: "; cin >> yn;
	
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
		cout << "������������ ���� . . .\n";
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
	cout << "� ������� �����, �������� ��� ��������!\n\n";
	Game();

	return 0;

}