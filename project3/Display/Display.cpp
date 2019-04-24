////////////////////////////////////////////////////////////////////
// Display.cpp      								              //
// ver 1.0                                                        //
// Dhaval Sonavaria, CSE687 - Object Oriented Design, Spring 2019 //
////////////////////////////////////////////////////////////////////

#include "pch.h"
#include<string>
#include <iostream>
#include "Display.h"
Display::Display(){	
}

void Display::Requirement2()
{std::cout << "Uses the standard streams libraries for all I/O and operators new and delete for memory management."<<"\n\n";}
void Display::Requirement3()
{std::cout << "provides Executive, Converter, and Display packages. The Executive package accepts the path from the user as well as a pattern  "<<"\n\n";}
void Display::Requirement1()
{std::cout << "Cautions: Since the software is based on the parser which handles code written in the usual way There might be errors in placement of certain tags" << "\n\n";
std::cout << "Uses Visual Studio 2017 and its C++ Windows Console Projects, as provided in the ECS computer labs."<<"\n\n";}
void Display::Requirement4()
{
	std::cout << "the path and pattern entered by the user is:" << "\n\n";
    }
void Display::Requirement5()
{
	std::cout<<"\n\n" << "Displays an error message on the command line if no files are found" << std::endl << std::endl;
}
void Display::Requirement6(std::vector<std::string> files,std::vector<std::string>filesToConvert)
{
	if (files.empty()) {
		std::cout << "Error:no files found in the given path" << std::endl;
	}
		else
	{std::cout << "Converts each matched file to a webpage and stores it in the folder ConvertedWebpages" << std::endl<<std::endl;
	std::cout << "\n\n";
		std::cout << "The searched files are:"<< std::endl;
		for (auto i : files) {
			std::cout << i << std::endl;}}
	if (filesToConvert.empty()) {
		std::cout << "Error:no files found matching the given pattern" << std::endl;}
		else{
		std::cout << "The files matching the Regular expression are:"<< std::endl;
		for (auto i : filesToConvert)
		{std::cout << i << std::endl;}}}
void Display::Requirement7()
{std::cout << "displays, in a child process, each converted file, waiting for the child to exit before displaying the next file.";}
void Display::Requirement8()
{std::cout << "Includes an automated testing unit that shows a step by step demonstration of the project";}



