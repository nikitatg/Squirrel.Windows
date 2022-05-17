// cleanup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atlbase.h>


int main(int argc, char** argv)
{
	if (argc > 1 && (strcmp(argv[1], "--squirrel-updated") == 0 || strcmp(argv[1], "--squirrel-install") == 0)) {
		ATL::CRegKey key;
		if (key.Open(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", KEY_WRITE) != ERROR_SUCCESS) {
			std::cout << "Can't open uninstall path in registry" << std::endl;
		}
		if (key.DeleteSubKey(L"TeleGuard") != ERROR_SUCCESS) {
			std::cout << "Can't delete TeleGuard key registry" << std::endl;
		}
	}
	else {
		std::cout << "No param. Skipping" << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
