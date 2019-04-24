/////////////////////////////////////////////////////////////////////////////
// HTMLTags.h - header file for HTMLTags.cpp                               //
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
 *A handy package whose constructor opens a .txt file from where all the necessary CSS,Javascript, HTML tags can be loaded
 * to the HTML file you want to create
 *
 * Required Files:
 * ---------------
 * -
 * Maintenance History:
 * --------------------
 * ver 1.0 : 17 March 2019
 * - first release
 */

#pragma once
#include <string>
#include<iostream>
#include<fstream>
#include<vector>

class HTMLTags
{
public:
	HTMLTags();
	std::vector<std::string> addPreCodeHTML(std::string);
	std::string addPreTag();
	~HTMLTags();
};


