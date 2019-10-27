#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h> 
#include <conio.h>
#include <sstream>
#pragma comment(lib, "winmm.lib")
using namespace::std;
int game();
bool loop = true, alive = true, skiptitle = false;
int level = 1, highscore = 0, speed = 500, input = 0, output[1000];
string text = "", name = "";
int code;
int main()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // Variable named color is created which gains acces to the list of colors in C++
	if (skiptitle != true)
	{
		SetConsoleTextAttribute(color, 13);  // Sets the text color to purple.  
		// ASCII art designed for group name. The ASCII art for the group name consist of these keys on the keyboard: '_', '(', ')', '/', '\\',
		cout << "         ____  _\n";
		cout << "        / __ \\(_) _________\n";
		cout << "       / /_/ / / ____/ ___/\n";
		cout << "      /____ /  (__  |__  )\n";
		cout << "     /_/ __///____/ ____/\n";
		cout << "        / __ \\____  ____  _____\n";
		cout << "       / /_/ / __ \\/ __ \\/  __/\n";
		cout << "      / ____/ /_/ / /_/ / /\n";
		cout << "     /_/ ___\\____/\\____/_/     __           __  _\n";
		cout << "        / __ \\_________   ____/ /_  _______/ /_(_)___  ____  _____\n";
		cout << "       / /_/ / ___ / __\\/  __  / / / / ___/ __/ / __ \\/ __ \\/ ___/\n";
		cout << "      / ____/ /   / /_//  /_/ / /_/ / /__/ /_/ / /_/ / / / (__  )\n";
		cout << "     /_/   /_/    \\___/\\__,__/\\__,_/\\___/\\__/_/\\____/_/ /_/____/\n";
		SetConsoleTextAttribute(color, 15); // sets the text color back to white
		cout << "\t\t\t\t\t\t\t\t     Presents...";
		Sleep(4000);
		system("CLS");
		cout << "   __________  _______  _  __\n  / __/  _/  |/  / __ \\/ |/ /\n _\\ \\_/ // /|_/ / /_/ /    / \n/___/___/_/  /_/\\____/_/|_/  \n  Watch, Remember, Repeat! \n" << endl; // Title of game
		mciSendString("play sounds/iamsimon.mp3 wait", NULL, 0, NULL); // all mciSendString lines are used to play Simon's voice throughout the game
	}

	fstream scorefile("highscore.txt"); //obtains updated highscore info to display
	while (getline(scorefile, text))
	{
		stringstream geek(text);
		geek >> highscore;
	}
	scorefile.close();
	fstream namefile("name.txt"); //obtains updated highscore info to display
	namefile >> name;
	namefile.close();
	loop = true;
	do
	{
		system("CLS");
		cout << "HIGH SCORE: " << name << " - Level " << highscore << "\n\n1 - Start Game\n2 - How to Play\n3 - Exit" << endl; // This prints the current highscore as well as the main menu
		cin >> input;
		switch (input) //switch decisions are used in most of the game's menus
		{
		case 1:
			system("CLS");
			game();
			break;
		case 2:
			system("CLS");
			mciSendString("play sounds/simoninstructions.mp3", NULL, 0, NULL);
			//Prints a transcript of the audio.
			cout << "Hello there. My name is Simon, and you are playing my game. \nThe goal of my game is to remember as many numbers as you can.\nYou could say that it is a simple game of Simon Says. You would be mistaken. \nInput the numbers in the order that you see them appear on the screen.\nYou can input the numbers by pressing 1, 2, 3, or 4 and then pressing enter. Simple enough, right?\nJust kidding. One mistake and you're history.\nAlso, I like to speed things up as the game goes longer. After all, an easy game is never fun.\nBut what do I know about fun? I'm just a computer. \nA computer with a brain!\nSo are you up for the challenge known as Simon?\nOr is your human mind too scared?\n\n\n";
			system("pause");
			mciSendString("stop sounds/simoninstructions.mp3", NULL, 0, NULL);
			break;
		case 3:
			mciSendString("play sounds/goodbye.mp3 wait", NULL, 0, NULL);
			exit(0);
		default:
			cout << "Invalid input. Please try again." << endl;
			Sleep(1000);
			break;
		}
	} while (loop == true);
}

int game()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	level = 1;
	cout << "Now loading the memory game..."; //fake loading screen to really make it feel like an 80s computer game (make it feel like it came out the same time as the original game)
	Sleep(3000);
	system("CLS");
	cout << "Ready?" << endl;
	mciSendString("play sounds/ready.mp3 wait", NULL, 0, NULL);
	Sleep(1000);
	cout << "Go!";
	mciSendString("play sounds/go.mp3 wait", NULL, 0, NULL);
	Sleep(500);
	system("CLS");
	while (loop == true)
	{
		switch (level)
		{
		case 1:
			speed = 500;
			break;
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
		output[level - 1] = (rand() % 4 + 1);
		//outputting numbers
		for (int i = 0; i < level; i++)
		{
			switch (output[i])
			{
			case 1:
				SetConsoleTextAttribute(color, 10);
				cout << "      ______";
				SetConsoleTextAttribute(color, 15);
				cout << "    ______\n";
				SetConsoleTextAttribute(color, 10);
				cout << "     /      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |     \\\n";
				SetConsoleTextAttribute(color, 10);
				cout << "    /       | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |      \\\n";
				SetConsoleTextAttribute(color, 10);
				cout << "   /    1   | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |       \\\n";
				SetConsoleTextAttribute(color, 10);
				cout << "  /         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        \\\n";
				SetConsoleTextAttribute(color, 10);
				cout << " /__________|";
				SetConsoleTextAttribute(color, 15);
				cout << "   |_________\\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  __________";
				SetConsoleTextAttribute(color, 15);
				cout << "SIMON";
				SetConsoleTextAttribute(color, 15);
				cout << "__________\n ";
				SetConsoleTextAttribute(color, 15);
				cout << " \\         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |         /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   \\        |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    \\       |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |       /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     \\      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |      /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "      \\_____| ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |_____/\n";
				Beep(444, speed);
				break;
			case 2:
				SetConsoleTextAttribute(color, 15);
				cout << "      ______";
				SetConsoleTextAttribute(color, 4);
				cout << "    ______\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     /      |";
				SetConsoleTextAttribute(color, 4);
				cout << "   |     \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    /       | ";
				SetConsoleTextAttribute(color, 4);
				cout << "  |      \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   /        | ";
				SetConsoleTextAttribute(color, 4);
				cout << "  |   2   \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  /         |";
				SetConsoleTextAttribute(color, 4);
				cout << "   |        \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << " /__________|";
				SetConsoleTextAttribute(color, 4);
				cout << "   |_________\\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  __________";
				SetConsoleTextAttribute(color, 15);
				cout << "SIMON";
				SetConsoleTextAttribute(color, 15);
				cout << "__________\n ";
				SetConsoleTextAttribute(color, 15);
				cout << " \\         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |         /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   \\        |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    \\       |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |       /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     \\      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |      /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "      \\_____| ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |_____/\n";
				Beep(345, speed);
				break;
			case 3:
				SetConsoleTextAttribute(color, 15);
				cout << "      ______";
				SetConsoleTextAttribute(color, 15);
				cout << "    ______\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     /      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |     \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    /       | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |      \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   /        | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |       \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  /         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << " /__________|";
				SetConsoleTextAttribute(color, 15);
				cout << "   |_________\\\n";
				SetConsoleTextAttribute(color, 6);
				cout << "  __________";
				SetConsoleTextAttribute(color, 15);
				cout << "SIMON";
				SetConsoleTextAttribute(color, 15);
				cout << "__________\n ";
				SetConsoleTextAttribute(color, 6);
				cout << " \\         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |         /\n";
				SetConsoleTextAttribute(color, 6);
				cout << "   \\        |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        /\n";
				SetConsoleTextAttribute(color, 6);
				cout << "    \\   3   |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |       /\n";
				SetConsoleTextAttribute(color, 6);
				cout << "     \\      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |      /\n";
				SetConsoleTextAttribute(color, 6);
				cout << "      \\_____| ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |_____/\n";
				Beep(275, speed);
				break;
			case 4:
				SetConsoleTextAttribute(color, 15);
				cout << "      ______";
				SetConsoleTextAttribute(color, 15);
				cout << "    ______\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     /      |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |     \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    /       | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |      \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   /        | ";
				SetConsoleTextAttribute(color, 15);
				cout << "  |       \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  /         |";
				SetConsoleTextAttribute(color, 15);
				cout << "   |        \\\n";
				SetConsoleTextAttribute(color, 15);
				cout << " /__________|";
				SetConsoleTextAttribute(color, 15);
				cout << "   |_________\\\n";
				SetConsoleTextAttribute(color, 15);
				cout << "  __________";
				SetConsoleTextAttribute(color, 15);
				cout << "SIMON";
				SetConsoleTextAttribute(color, 1);
				cout << "__________\n ";
				SetConsoleTextAttribute(color, 15);
				cout << " \\         |";
				SetConsoleTextAttribute(color, 1);
				cout << "   |         /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "   \\        |";
				SetConsoleTextAttribute(color, 1);
				cout << "   |        /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "    \\       |";
				SetConsoleTextAttribute(color, 1);
				cout << "   |   4   /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "     \\      |";
				SetConsoleTextAttribute(color, 1);
				cout << "   |      /\n";
				SetConsoleTextAttribute(color, 15);
				cout << "      \\_____| ";
				SetConsoleTextAttribute(color, 1);
				cout << "  |_____/\n";
				Beep(225, speed);
				break;
			}
			system("CLS");
			SetConsoleTextAttribute(color, 15);
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
				mciSendString("play sounds/gameover.mp3 wait", NULL, 0, NULL);
				system("CLS");
				alive = false;
				cout << "Final Score: " << level << endl;
				Sleep(1500);
				fstream myfile("highscore.txt");
				while (getline(myfile, text))
				{
					stringstream geek(text);
					geek >> highscore;
					if (highscore < level)
					{
						cout << "YOU HAVE THE NEW HIGH SCORE!";
						mciSendString("play sounds/highscore.mp3 wait", NULL, 0, NULL);
						Beep(1030, 100);
						Beep(1030, 1250);
						fstream myfile;
						myfile.open("highscore.txt");
						myfile << level;
						myfile.close();
						system("CLS");
						while (loop == true)
						{
							cout << "Please type a 3-character name here: ";
							cin >> text;
							if (text.length() != 3)
							{
								cout << "Please make the name 3 characters!";
								Sleep(1000);
								system("CLS");
							}
							else
							{
								fstream myfile;
								myfile.open("name.txt");
								myfile << text;
								myfile.close();
								loop = false;
							}
						}

					}
				}
				myfile.close();
				system("CLS");
				i = level;
			}
		}
		if (alive == true)
		{
			level++;
		}
		else
		{
			while (alive == false)
			{
				cout << "GAME OVER:\n1.) Try Again\n2.) Back to Main Menu\nPlease pick an option: ";
				cin >> input;
				switch (input)
				{
				case 1:
					alive = true;
					system("CLS");
					game();
					break;
				case 2:
					alive = true;
					skiptitle = true;
					system("CLS");
					main();
					break;
				default:
					cout << "Invalid choice. Please try again.";
					Sleep(1000);
					system("CLS");
					break;
				}
			}
		}

	}
	return 0;
}