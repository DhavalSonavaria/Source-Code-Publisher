////////////////////////////////////////////////////////////////////
// ConvertAndStore.cpp								              //
// ver 1.1                                                        //
// Dhaval Sonavaria, CSE687 - Object Oriented Design, Spring 2019 //
////////////////////////////////////////////////////////////////////
#include "ConvertAndStore.h"
using namespace FileSystem;
ConvertAndStore::ConvertAndStore(std::string file)
{
	file_ = file;
	cf_ = new ClassFunction(file);
	std::string filename_ = Path::getName(file_);
	getDepen();
	bool write = openOutFile();
	if (write) {
		writeFile();
	}
}
std::string ConvertAndStore::returnfile()
{
	return opPath_;
}
bool ConvertAndStore::success()
{
	return success_;
}
void ConvertAndStore::getDepen()
{
	dependencies_ = cf_->retDep();
}
bool ConvertAndStore::openOutFile() {
	std::string filename_ = Path::getName(file_);
	std::string dir("..//ConvertedWebpages//");
	if (!FileSystem::Directory::exists(dir)) // it's always important to verify if the directory already exists
		FileSystem::Directory::create(dir);
	std::string outputPath = "..//ConvertedWebpages//" + filename_ + ".html"; opPath_ = outputPath;
	out_.open(outputPath, std::ofstream::out);
	if (!out_.is_open() || !out_.good()) {
		std::cout << "Error -- unable to open output file for writing "+filename_+"."<<std::endl;
		return false;
	}
	return true; success_ = true;
}
bool ConvertAndStore::writeFile() {
		std::vector<std::string> fileContent;
		HTMLTags ht; WebPage wp;
		std::vector<std::string> pretags = ht.addPreCodeHTML(filename_);
		std::ifstream ifs(file_); std::string line;
		while (ifs.is_open() && !ifs.eof() && (!ifs.fail()) && ifs.good()) {
			try {
				while (std::getline(ifs, line))
				{
					if (line.empty())
						continue;
					wp.skipSpecialChars(line);
					wp.handlecomments(line);
					wp.handlecommentsclose(line);
					fileContent.push_back(line);
				}ifs.close();
			}
			catch (std::ios_base::failure& e) {
				std::cerr << e.what() << '\n';
			}
		}
		taggedfile = cf_->AddTags(fileContent);
		for (auto i : pretags)
		{
			out_ << i << std::endl;
		}
		if (!dependencies_.empty()) {
			for (auto i : dependencies_)
			{
				out_ << i << std::endl;
			}
		}
		if (!taggedfile.empty()) {
			for (auto i : taggedfile)
			{
				out_ << i << std::endl;
			}
		}
		addClosingTags();
		out_.close();
		std::cout << filename_ + "  was successfully converted" << std::endl;
		return true; 	
}
void ConvertAndStore::addClosingTags()
{
	out_ << std::endl;
	out_ << "    </pre>" << std::endl; out_ << "  </body>" << std::endl; out_ << "</html>" << std::endl;
}
#ifdef TEST_CONVERT
int main()
{
	std::string dir = "..//FileSystem.h";
	ConvertAndStore c(dir);
	getchar();
	return 0;
}
#endif // TEST_CONVERT