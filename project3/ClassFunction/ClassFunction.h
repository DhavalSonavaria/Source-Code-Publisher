/////////////////////////////////////////////////////////////////////////////
// ClassFunction.h - header file for ClassFunction.cpp                     //
// ver 1.0                                                                 //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    HP Spectre, Core i7, Windows 10 SP1                        //
// Application: OOD project 2		                                       //
// Author:      Dhaval Kumar Sonavaria, Syracuse University                //
//              (315) 314-0983, dhsonava@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 This package uses the Parser to get all the dependencies as well as the class and function information.
 *
 * Required Files:
 * ---------------
 * Parser.h
 *FileSystem.h
 * Maintenance History:
 * --------------------
 * ver 1.0 : 17 March 2019
 * - first release
 */
#pragma once
#include<string>
#include<vector>
#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../Dependency/Dependency.h"
using namespace CodeAnalysis;
using namespace FileSystem;
class ClassFunction
{
	using dependecies = std::vector<std::string>;
	using CFData = std::vector<CodeAnalysis::data*>;
public:
	ClassFunction(std::string);
	~ClassFunction();
	dependecies& retDep();
	std::vector<std::string> AddTags(std::vector<std::string>);
private:
	std::vector<CodeAnalysis::data*> CFData_;
	std::vector<std::string> dependencies_;
};