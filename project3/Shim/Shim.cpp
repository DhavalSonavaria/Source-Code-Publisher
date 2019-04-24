/////////////////////////////////////////////////////////////////////////////////////////////
// Shim.cpp       : Uses Factory and ICodePublisher to communicate with the Code Publisher //     
// ver 1.0                                                                                 //
//																						   //	
// Application    : CSE-687 Spring 2019 project 3                                          //
// Platform       : Visual Studio 2017 Community Edition                                   //
//                  Windows 10 Professional 64-bit, HP Spectre                             //
// Author         : Dhaval Kumar Sonavaria, Syracuse University                            //
//                  315-314-0983 dhsonava@syr.edu                                          // 
/////////////////////////////////////////////////////////////////////////////////////////////
#include "Shim.h"
using namespace System::Text;
// -----< Shim constructor - instantiates ICodePublisher------------------
Translator::Translator() {
	Console::Write("\n  Shim created");
	ObjectFactory factory;
	client = factory.createClient();
	Console::Write("\n  Shim instantiated CppClient as ICppClient*");}
Translator::~Translator() {
	delete client;Console::Write("\n  Shim destroyed\n\n");}
void Translator::Start()
{client->Start();}
void Translator::SendCmd(List<String^>^ args)
{
	int argc = args->Count;
	char ** argv = new char*[argc];
	for (int i = 0; i < argc; i++)
	{std::string arg = sysStrToStdStr(args[i]);
		argv[i] = new char[args[i]->Length];
		strcpy_s(argv[i], args[i]->Length + 1, arg.c_str());}
	client->getcmd(argc, argv);
	delete[] argv;}
String^ Translator::getMessage() {
	return stdStrToSysStr(client->getMessage());}
List<String^>^ Translator::returnFile()
{std::vector<std::string> cFiles = client->returnFile();
	List<String^>^ files = gcnew List<String^>();
	std::vector<std::string>::size_type size = cFiles.size();
	for (unsigned i = 0; i < size; i++)
	{String^ arg = stdStrToSysStr(cFiles[i]);
		files->Add(arg);
	}return files;}
String^ Translator::stdStrToSysStr(const std::string& str) {
	return gcnew String(str.c_str());}
std::string Translator::sysStrToStdStr(String^ str) {
	std::string temp;
	for (int i = 0; i < str->Length; ++i)
		temp += char(str[i]);
	return temp;}
