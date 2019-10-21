#include <Windows.h>
#include <string>
#include <iostream>
#pragma comment(lib, "winmm.lib")


using namespace::std;
int game();
bool loop = true;
int level = 100;
int output[1000];
int speed = 50;
int input = 0;
int code;
int main() 
{
	//Used to print title
	cout << "   __________  _______  _  __\n  / __/  _/  |/  / __ \\/ |/ /\n _\\ \\_/ // /|_/ / /_/ /    / \n/___/___/_/  /_/\\____/_/|_/  \n  Watch, Remember, Repeat! \n" << endl;
	mciSendString("open \"simon.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3 wait", NULL, 0, NULL);
	system("pause");
	system("CLS");
	game();
}

int game()
{
	switch (level)
	{
	case 5:
		speed = 400;
		break;
	case 10:
		speed = 350;
		break;
	case 15:
		speed = 300; 
		break;
	case 20:
		speed = 250;
		break;
	case 25:
		speed = 200;
		break;
	case 50:
		speed = 150;
		break;
	case 75:
		speed = 100;
		break;
	case 100:
		speed = 50;
		break;
	default:
		break;
	}
	while(loop == true)
	{
		for (int i = 0; i < 200; i++)
		{ 
		output[level-1] = (rand() % 4 + 1);
		}
		for (int i = 0; i < level; i++)
		{
			switch (output[i]) //outputting numbers
			{
				case 1:
					cout << " 1 |   \n   |  ";
					Beep(444, speed);
					break;
				case 2:
					cout << "   | 2 \n   |  ";
					Beep(345, speed);
					break;
				case 3:
					cout << "   |   \n 3 |  ";
					Beep(275, speed);
					break;
				case 4:
					cout << "   |   \n   | 4";
					Beep(225, speed);
					break;
			}
			system("CLS");
		}
		for (int i = 0; i < level; i++) //inputting answers
		{
			cin >> input;
			if (input == output[i])
			{
				cout << "Good!";
				switch (input) //outputting numbers
				{
				case 1:
					Beep(925, speed);
					break;
				case 2:
					Beep(700, speed);
					break;
				case 3:
					Beep(545, speed);
					break;
				case 4:
					Beep(450, speed);
					break;
				}
				system("CLS");
			}
			else
			{
				cout << "Game over!";
				Beep(100, 250);
				Beep(75, 1000);
				system("CLS");
				exit(0);
			}
		}
		level++;

	}
	return 0;
}