#include "Loader.h"
Loader::Loader(int argc, char * argv[])
{
	pcl_ = new ProcessCmdLine(argc, argv);
	preface("Command Line: ");
	pcl_->showCmdLine();
	std::cout << std::endl;
	de_ = new DirExplorerN(pcl_->path());
	for (auto patt : pcl_->patterns())
		de_->addPattern(patt);
	if (pcl_->hasOption("s"))
		de_->recurse();
	bool res = de_->search();
}
bool Loader::getFiles()
{
	de_->showStats();
	files_ = de_->filesList();
	filesToConvert_ = files_;
	std::vector<std::string> directories = de_->dirsList();
	if (!filesToConvert_.empty())
		return true;
	else {
		std::cout << "\n no files found matching regular expression\n"; return false;
	}
}
const Loader::files & Loader::returnConverterFiles() const
{
	return filesToConvert_;
}
const Loader::files & Loader::returnProcessorFiles() const
{
	return filesToProcess_;
}
Loader::~Loader()
{
	delete pcl_;
	delete de_;
}
#ifdef TEST_LOAD
int main(int argc, char * argv[])
{
	Loader load(argc, argv);
	load.getFiles();
	std::vector<std::string> files = load.returnConverterFiles();
	for (auto i : files)
		std::cout << i << std::endl;
	std::getchar();
	return 0;
}
#endif