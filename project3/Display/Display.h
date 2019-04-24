////////////////////////////////////////////////////////////////////
// Display.h        								              //
// ver 1.0                                                        //
// Dhaval Sonavaria, CSE687 - Object Oriented Design, Spring 2019 //
////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * This Package is used by the executive to display results on the command line
 * The purpose of the project is to give enogh proof to satisfy all requirements
 * Required Files:
 * ---------------
 * Display.cpp
 *
 * ver 1.0 : 13 Feb 2019
 * - first release
 *
 */


#pragma once
#include<string>
#include<vector>
class Display
{
public:
	Display();
	void Requirement1();
	void Requirement2();
	void Requirement3();
	void Requirement4();
	void Requirement5();
	void Requirement6(std::vector<std::string> files,std::vector<std::string> filesToConvert);
	void Requirement7();
	void Requirement8();

};

