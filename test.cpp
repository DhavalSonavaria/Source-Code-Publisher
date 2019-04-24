// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<fstream>
#include <string>
#include"../../FileSystem/FileSystem.h"
using namespace FileSystem;


int main()
{
	std::cout << "Hello World!\n";
	std::string directory, file;
	
	std::cin >> directory;
	std::cin >> file;
	std::string filepath = directory + "\\" + file;
	std::cout << filepath;
	std::ifstream in("../Executive/Executive.cpp");
	File p(filepath);
	std::cout << p.exists("../ Executive/Executive.cpp" );
	std::vector<std::string> fileContent;
	for (std::string line;std::getline(in, line);)
	{
		fileContent.push_back(line);
	}
	for (auto i : fileContent) {
		std::cout << i << std::endl;
	}
	return 0;
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
