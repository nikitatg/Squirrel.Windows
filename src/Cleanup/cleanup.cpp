// cleanup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <atlbase.h>


int main(int argc, char** argv)
{
	if (argc > 1 && (strcmp(argv[1], "--squirrel-updated") == 0 || strcmp(argv[1], "--squirrel-install") == 0)) {
		ATL::CRegKey key;
		if (key.Open(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", KEY_WRITE) != ERROR_SUCCESS) {
			std::cout << "Can't open uninstall path in registry" << std::endl;
		}
		else {
			if (key.DeleteSubKey(L"TeleGuard") != ERROR_SUCCESS) {
				std::cout << "Can't delete TeleGuard key registry" << std::endl;
			}
		}
		if (key.Open(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\93443beb-f105-47fe-bac0-709583ac44cb_is1", KEY_WRITE) != ERROR_SUCCESS) {
			std::cout << "Can't update version in registry" << std::endl;
		}
		else {
			std::string ver = argv[2];
			std::string beta = "-beta";
			std::string betaver = ver + beta;
			key.SetStringValue(L"DisplayVersion", CA2W(betaver.c_str()));
		}
		if (strcmp(argv[1], "--squirrel-updated") == 0) {
			char filename[] = "..\\app.version";
			std::fstream fversion(filename, std::ofstream::out | std::ofstream::trunc);
			if (!fversion) {
				std::cout << "File not exist" << std::endl;
			}
			fversion << argv[2];
			fversion.close();
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
