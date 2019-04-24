/////////////////////////////////////////////////////////////////////////////
// DEPENDENCY.h - header file for Dependency.cpp                           //
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
 Takes dependency as input and returns an <a href tag that has the dependency link and name within.
 *
 * Required Files:
 * ---------------
 * 
 *FileSystem.h
 * Maintenance History:
 * --------------------
 * ver 1.0 : 17 March 2019
 * - first release
 */



#pragma once
#include <vector>
#include"string"
#include "iostream"
#include "../FileSystem/FileSystem.h"
class Dependency
{
public:
	using dep = std::vector<std::string>;
	Dependency(dep);
	 dep&  Dependencies() ;
	~Dependency();
	dep depen;
};

