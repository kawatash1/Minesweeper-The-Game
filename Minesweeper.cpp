
#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>

using namespace std;


class Saper {
public:
	void Game() {
		Title();
		HiddenFieldGeneration();
		MinesGeneration(0);
		NumGeneration();
		FieldGeneration();
		ShowField();
		cout << endl << endl;
		while (!lose && !win) {
			gamePlay();
		}
		if (lose) {
			system("CLS");
			ShowHiddenField();
			cout << endl << "You lose :(\n\n\n\n\n\n\n\n\n\n\n";
		}
		else cout << endl << "You won! :)\n\n\n\n\n\n\n\n\n\n\n";
	}

protected:
	bool lose = false;
	bool win = false;

private:

	char field9x9[9][9]{};
	char hidden_field[9][9]{};

	int bombPosX = 0;
	int bombPosY = 0;
	int bombCounter;


	int count = 0;
	string user_line;

	int correct_answers=0;
	void Title() {
		//system("color F5");
		cout << "\n						MINESWEEPER";
		cout << "\n\nPress any button to start the game..";
		_getch();
		system("CLS");
		system("color 7");
	}


	void FieldGeneration() {					//генерация игрового поля
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9;j++) {
				field9x9[i][j] = ' ';
			}
		}
	}

	void HiddenFieldGeneration() {					//генерация скрытого поля
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9;j++) {
				hidden_field[i][j] = '0';
			}
		}
	}

	void ShowField() {						//показать игровое поле
		cout << endl;
		cout << " ";
		for (int i = 0; i < 9; i++) {
			cout << " " << (char)(i + 65);
		}
		cout << endl;
		for (int i = 0; i < 9; i++) {
			cout << i + 1 << "|";
			for (int j = 0; j < 9;j++) {
				cout << field9x9[i][j] << "|";
			}
			cout << endl << " - - - - - - - - - -" << endl;
		}
	}


	void ShowHiddenField() {					//показать скрытое поле
		cout << " ";
		for (int i = 0; i < 9; i++) {
			cout << " " << (char)(i + 65);
		}
		cout << endl;
		for (int i = 0; i < 9; i++) {
			cout << i + 1 << "|";
			for (int j = 0; j < 9;j++) {

				cout << hidden_field[i][j] << "|";
			}
			cout << endl << " - - - - - - - - - -" << endl;
		}
	}


	void MinesGeneration(int count) {				//генерация мин
		for (int i = count; i < 9; i++) {
			bombPosX = rand() % 9;
			bombPosY = rand() % 9;
			if (hidden_field[bombPosY][bombPosX]) { hidden_field[bombPosY][bombPosX] = '*'; }
			else {
				count = i;
				MinesGeneration(count);
			}
		}
		bombCounter = 9;
	}


	void NumGeneration() {						//генерация цифр вокруг мины
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9;j++) {
				if (hidden_field[i][j] == '*') {

					if (i > 0)			{	if (hidden_field[i - 1][j] != '*') { hidden_field[i - 1][j]++; }}

					if (i > 0 && j > 0) {	if (hidden_field[i - 1][j - 1] != '*') { hidden_field[i - 1][j - 1]++; }}

					if (i > 0 && j < 8) {	if (hidden_field[i - 1][j + 1] != '*') { hidden_field[i - 1][j + 1]++; }}

					if (j > 0)			{	if (hidden_field[i][j - 1] != '*') { hidden_field[i][j - 1]++; }}

					if (j < 8)			{	if (hidden_field[i][j + 1] != '*') { hidden_field[i][j + 1]++; } }

					if (i < 8 && j > 0)	{	if (hidden_field[i + 1][j - 1] != '*') { hidden_field[i + 1][j - 1]++; } }

					if(i < 8)			{	if (hidden_field[i + 1][j] != '*') { hidden_field[i + 1][j]++; }}

					if(i < 8 && j < 8)	{	if (hidden_field[i + 1][j + 1] != '*') { hidden_field[i + 1][j + 1]++; }}
				}
			}
		}
	}



	void gamePlay() {
		string user_line;
		char byX;
		char byY;
		int choice = 0;
		cout << "(1) - put / remove a flag\n(2) - open cell\n";
		while (choice < 1 || choice > 2) { cin >> choice; }
		cout << "\n	Remaining mines: " << bombCounter << "\n(Enter the cell position according to the a1 principle)\n";
		cin >> user_line;
		while (user_line.length() != 2 || ((int)user_line[0] < 97 || (int)user_line[0] > 105) || ((int)user_line[1] < 49 || (int)user_line[1] > 57))
		{
			cout << "\Enter the correct position of the cell.\n";
			cin >> user_line;
		}

		byX = user_line[0];
		byY = user_line[1];
		byX -= 97;
		byY -= 49;

		switch (choice) {

		case 1:
			if (field9x9[(int)byY][(int)byX] == 'F') { field9x9[(int)byY][(int)byX] = ' '; bombCounter++; }
			else
			{
				field9x9[(int)byY][(int)byX] = 'F';
				if (hidden_field[(int)byY][(int)byX] == '*') { 
					cout << "You've set the flag correctly!"; 
					correct_answers++; 
					Sleep(2000); }
				bombCounter--;
			}
			break;

		case 2:
			field9x9[(int)byY][(int)byX] = hidden_field[(int)byY][(int)byX];
			if(hidden_field[(int)byY][(int)byX] == '0')
			{

				if ((int)byX > 0) {
					field9x9[(int)byY][(int)byX - 1] = hidden_field[(int)byY][(int)byX - 1];
					if ((int)byY > 0) 
						field9x9[(int)byY - 1][(int)byX - 1] = hidden_field[(int)byY - 1][(int)byX - 1];
				}

				if ((int)byY > 0) {
					field9x9[(int)byY - 1][(int)byX] = hidden_field[(int)byY - 1][(int)byX];
					if((int)byX < 8)
					field9x9[(int)byY - 1][(int)byX + 1] = hidden_field[(int)byY - 1][(int)byX + 1];
				}

				if ((int)byX < 8) {
					field9x9[(int)byY][(int)byX + 1] = hidden_field[(int)byY][(int)byX + 1];
					if((int)byY < 8)
					field9x9[(int)byY + 1][(int)byX + 1] = hidden_field[(int)byY + 1][(int)byX + 1];
				}

				if ((int)byY < 8) {
					field9x9[(int)byY + 1][(int)byX] = hidden_field[(int)byY + 1][(int)byX];
					if ((int)byX > 0)
					field9x9[(int)byY + 1][(int)byX - 1] = hidden_field[(int)byY + 1][(int)byX - 1];
				}

			}

			if (field9x9[(int)byY][(int)byX] == '*') { lose = true; }
			break;
		}
		system("CLS");
		ShowField();

		if (correct_answers == 9) { win = true; }
		if (correct_answers == 8) {
			int opened=0;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9;j++) {
					if (hidden_field[i][j] == field9x9[i][j])
						opened++;
				}
			}
			if (opened == 81) { win = true; }
		}
	}

};


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	Saper newgame;
	newgame.Game();
}
