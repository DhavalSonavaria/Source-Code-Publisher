//#define IN_DLL
#include "pch.h"
#include "CodePublisher.h"
#include "ICodePublisher.h"
CodePublisher::CodePublisher()
{
	std::cout << " Instance of CodePublisher created";
}
CodePublisher::~CodePublisher()
{
}
void CodePublisher::LoadFiles(int argc, char * argv[])
{
	load_ = new Loader(argc, argv);
	bool ifFiles_ = load_->getFiles();
	if (!ifFiles_) { std::cout << "No files returned from Loader"; }
	filesToConvert_ = load_->returnConverterFiles();
	for (auto i : filesToConvert_)
		std::cout << i << std::endl;
}

void CodePublisher::convert()
{
	for (auto i : filesToConvert_)
	{
		std::cout << i << std::endl;
		ConvertAndStore cp(i);
		
		std::string path = Path::getFullFileSpec(cp.returnfile());
		filesToProcess.push_back(path);
		
	}
}
void CodePublisher::Start()
{
}
void CodePublisher::getcmd(int argc, char * argv[])
{
	LoadFiles(argc, argv);
	convert();
}
std::vector<std::string> CodePublisher::returnFile()
{
	return filesToProcess;
}

std::string CodePublisher::getMessage()
{
	std::string msg = "Dhaval";
	return msg;
}
ICodePublisher* ObjectFactory::createClient() {
	return new CodePublisher;
}
//#ifdef Test_CP
int main(int argc, char * argv[])
{
	CodePublisher c;
	c.LoadFiles(argc, argv);
	c.convert();
}
//#endif

