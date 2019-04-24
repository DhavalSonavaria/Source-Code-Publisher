#pragma once
//#define IN_DLL
#include "pch.h"
#include <iostream>
#include "../../Utilities/CodeUtilities/CodeUtilities.h"
#include "../../Utilities/StringUtilities/StringUtilities.h"
#include "../../DirExplorer-Naive/DirExplorerN.h"
#include "../ConvertAndStore/ConvertAndStore.h"
#include "../Loader/Loader.h"
#include <string>
#include <filesystem>
#include <Windows.h>
#include"ICodePublisher.h"
using namespace CodeAnalysis;
using namespace Utilities;
using namespace FileSystem;

class CodePublisher : public ICodePublisher
{

public:
	using files = std::vector<std::string>;
	CodePublisher();
	~CodePublisher();
	void LoadFiles(int argc, char *argv[]);
	void convert();
	//<!-------- ICodePublisher Methods ---------------------!>
	void  Start() override;
	void getcmd(int argc, char *argv[]) override;
	std::vector<std::string> returnFile() override;
	std::string getMessage() override;

private:
	Loader *load_;
	std::vector<std::string> filesToConvert_;
	std::vector<std::string> filesToProcess;

	files dependencies;
};

