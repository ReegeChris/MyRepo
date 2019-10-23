#include <iostream>
#include <Windows.h>
using namespace std;


	int main() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(color, 13);
	
	
	
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

	
	
	
	
	
	
	
	SetConsoleTextAttribute(color, 10);
	cout << "      ______\n";
	cout << "     /      | \n";
	cout << "    /       | \n";
	cout << "   /   1    | \n";
	cout << "  /         |   \n";
	cout << " /__________| \n";
	SetConsoleTextAttribute(color, 15);
	cout << "               SIMON \n";
	SetConsoleTextAttribute(color, 14);
	cout << "  __________\n";
	cout << "  \\         | \n   \\        | \n    \\   3   | \n     \\      |\n      \\_____| \n";
	cout << "\n\n\n\n"; 
	
	system("pause");
	return 0;
	
}

	
	