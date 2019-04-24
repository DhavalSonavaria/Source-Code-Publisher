/////////////////////////////////////////////////////////////////////////////////////////////
// Shim.h       : Uses Factory and ICodePublisher to communicate with the Code Publisher   //                 																				   //	
// Application    : CSE-687 Spring 2019 project 3                                          //
// Platform       : Visual Studio 2017 Community Edition                                   //
//                  Windows 10 Professional 64-bit, HP Spectre                             //
// Author         : Dhaval Kumar Sonavaria, Syracuse University                            //
//                  315-314-0983 dhsonava@syr.edu                                          //
//Build Requirements: ICodePublisher.h                                                     //
//Build Information: Build as dll for it to be recognised in the C# project                //
//Version History: Version 1.0                                                             //
//Release date: 4/22/19                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include"../Executive/ICodePublisher.h"
#include <string.h>
#include <iostream>
using namespace System;
using namespace System::Collections::Generic;


public ref class Translator {
public:
	Translator();
	~Translator();

	void Start();
	void SendCmd(List<String^>^ args);
	List<String^>^ returnFile();
	String^ getMessage();
private:
	std::string sysStrToStdStr(String^ str);

	String^ stdStrToSysStr(const std::string& str);

	ICodePublisher* client;
};
