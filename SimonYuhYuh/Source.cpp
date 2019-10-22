#include <Windows.h>
#include <string>
#include <iostream>
#include<time.h> 
#pragma comment(lib, "winmm.lib")
using namespace::std;
int game();
bool loop = true;
int level = 1;
int output[1000];
int speed = 500;
int input = 0;
int code;
int main() 
{
	//Used to print title
	cout << "   __________  _______  _  __\n  / __/  _/  |/  / __ \\/ |/ /\n _\\ \\_/ // /|_/ / /_/ /    / \n/___/___/_/  /_/\\____/_/|_/  \n  Watch, Remember, Repeat! \n" << endl;
	mciSendString("play sounds/iamsimon.mp3 wait", NULL, 0, NULL);
	system("CLS");
	do
	{
		cout << "1 - Start Game\n2 - How to Play\n3 - Exit";
		cin >> input;
		switch (input)
		{
		case 1:
			system("CLS");
			game();
			break;
		case 2:
			system("CLS");
			mciSendString("play sounds/simoninstructions.mp3", NULL, 0, NULL);
			cout << "Hello there. My name is Simon, and you are playing my game.";
			Sleep(6000);
			system("CLS");
			cout << "The goal of my game is to remember as many numbers as you can.";
			Sleep(5000);
			system("CLS");
			cout << "You could say that it is a simple game of Simon Says.";
			Sleep(4000);
			cout << " You would be mistaken.";
			break;
		}
	} while (loop == true);
	game();
}

int game()
{
	cout << "Now loading the memory game...";
	Sleep(3000);
	system("CLS");
	while(loop == true)
	{
		switch (level)
		{
		case 5:
			speed = 400;
			cout << "Speed increased by 100!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 10:
			speed = 350;
			cout << "Speed increased by 150!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 15:
			speed = 300;
			cout << "Speed increased by 200!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 20:
			speed = 250;
			cout << "Speed increased by 250!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 25:
			speed = 200;
			cout << "Speed increased by 300!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 50:
			speed = 150;
			cout << "Speed increased by 350!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 75:
			speed = 100;
			cout << "Speed increased by 400!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		case 100:
			speed = 50;
			cout << "Speed increased by 450!";
			mciSendString("play sounds/speedup.mp3 wait", NULL, 0, NULL);
			system("CLS");
			break;
		default:
			break;
		} //speed increase
		srand(time(0));
		output[level-1] = (rand() % 4 + 1);
		//outputting numbers
		for (int i = 0; i < level; i++)
		{
			switch (output[i])
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
		//inputting answers
		for (int i = 0; i < level; i++)
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
				Beep(250, 250);
				Beep(200, 1000);
				system("CLS");
				exit(0);
			}
		}
		level++;

	}
	return 0;
}