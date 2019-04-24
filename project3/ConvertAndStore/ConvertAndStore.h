/////////////////////////////////////////////////////////////////////////////
// ConvertAndStore.h - header file for Convert and store                   //
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
 * This package contains a .h and a .cpp file that can be used to convert a file to a html file
 * It uses the filestream for this purpose
 * A file is converted to a vector and then the AddTags function adds the HTML tags.
 *Added function to check comments and add the necessary HTML tags
 * Required Files:
 * ---------------
 * ConvertAndStore.cpp
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 13 Feb 2019
 * - first release
 * ver 1.1 : 17 March 2019
 *- second release
 */
#pragma once
#include<iostream>
#include<vector>
#include "../ClassFunction/ClassFunction.h"
#include<fstream>
#include "../Dependency/Dependency.h"
#include<string>
#include "../../FileSystem/FileSystem.h"
#include"../HTMLTags/HTMLTags.h"
#include"../WebPage/WebPage.h"
class ConvertAndStore
{
public:using files = std::vector<std::string>;
	   ConvertAndStore(std::string file);
	   bool success();
	   std::string returnfile();
private:
	files GUIfiles;
	std::vector<std::string> fileContent, taggedfile; files dependencies_;
	void getDepen();bool openOutFile();bool writeFile();
	bool success_;std::string opPath_;
	std::string filename_; std::string file_;
	ClassFunction *cf_;
	std::ifstream in_;
	std::ofstream out_;
	void addClosingTags();
};
