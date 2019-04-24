/////////////////////////////////////////////////////////////////////////////////////////////
// ICodePublisher.h       : methods to use the facilities of the CodePublisher by the      //
//							translator for c# GUI                                          //                 																				   //	
// Application    : CSE-687 Spring 2019 project 3                                          //
// Platform       : Visual Studio 2017 Community Edition                                   //
//                  Windows 10 Professional 64-bit, HP Spectre                             //
// Author         : Dhaval Kumar Sonavaria, Syracuse University                            //
//                  315-314-0983 dhsonava@syr.edu                                          //
//Build Requirements: ICodePublisher.h , CodePublisher.h, Executive.cpp, shim.h, shim.cpp  //
//Build Information: Override methods in CodePublisher and build as static library         //
//Version History: Version 1.0                                                             //
//Release date: 4/22/19                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#ifdef IN_DLL
#define DLL_DECL __declspec(dllexport)
#else
#define DLL_DECL __declspec(dllimport)
#endif
#include <string>
#include<vector>
class ICodePublisher
{
public:
	virtual void Start() = 0;
	virtual void getcmd(int argc, char* argv[]) = 0;
	virtual std::vector<std::string> returnFile() = 0;
	virtual std::string getMessage() = 0;
	virtual ~ICodePublisher() {};
};
extern "C" {
	// Instantiates CodePublisher* as ICodePublisher*
	struct ObjectFactory {
		// See CodePublisher.cpp for implementation
		DLL_DECL ICodePublisher* createClient();
	};
}
