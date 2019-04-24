/////////////////////////////////////////////////////////////////////////////
// Loader.h - header file for Loader.cpp                                   //
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
 This package uses the DirExpN to get files from all the directories in the given path.
 * Also contains code to retrieve input from the pcl.
 *Uses regex to filter files
 * Required Files:
 * ---------------
 * CodeUtilities.h
 *StringUtilities.h
 *DirExplorerN.h
 *Display.h
 *ConvertAndStore.h
 *Processor.h
 *FileSystem.h
 * Maintenance History:
 * --------------------
 * ver 1.0 : 17 March 2019
 * - first release
 */



#pragma once
#include <iostream>
#include "../../Utilities/CodeUtilities/CodeUtilities.h"
#include "../../Utilities/StringUtilities/StringUtilities.h"
#include "../../DirExplorer-Naive/DirExplorerN.h"
#include"../FileSystem/FileSystem.h"
#include <string>
#include <filesystem>
using namespace Utilities;
using namespace FileSystem;
class Loader
{
public:
	Loader(int argc, char *argv[]);
	using files = std::vector<std::string>;
	bool getFiles();
	~Loader();
	const files& returnConverterFiles() const;
	const files& returnProcessorFiles()const;
private:
	ProcessCmdLine *pcl_;
	DirExplorerN *de_;
	std::vector<std::string> files_, filesToConvert_, filesToProcess_;
	std::string path_;

};
