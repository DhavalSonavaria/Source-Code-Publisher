#include "ClassFunction.h"
ClassFunction::ClassFunction(std::string file)
{
	CodeAnalysis::useParser up(file);
	std::string name = Path::getName(file) + ".html";
	std::vector<std::string> temp = up.returnStatements();
	//dependencies_ = up.returnStatements();
	for (auto i : temp) {
		i = "<a href =\"" + i + ".html" + "\">" + i + "</a>";
		dependencies_.push_back(i);
	}
	CFData_ = up.returnData();
}
ClassFunction::~ClassFunction()
{
}
ClassFunction::dependecies & ClassFunction::retDep()
{
	return dependencies_;
}
std::vector<std::string> ClassFunction::AddTags(std::vector<std::string> fileContent)
{
	for (auto i : CFData_)
	{
		unsigned int startline = i->start - 1; unsigned int endline = i->end; std::vector<std::string>::size_type sz = fileContent.size();
		if (i->type == "class")
		{
			if (sz > startline)
				fileContent.insert(fileContent.begin() + startline, "<span class=\"toggleClassDisplay\">");
			if (sz > endline)
				fileContent.insert(fileContent.begin() + endline, "</span>");
		}
		if (i->type == "function") 
		{
			if (sz > startline)
				fileContent.insert(fileContent.begin() + startline, "<span class=\"toggleMethodContents\">");
			if (sz > endline)
				fileContent.insert(fileContent.begin() + endline, "</span");
		}
	}
	return fileContent;
}
#ifdef TEST_CF
void main()
{
	ClassFunction cf("../Loader/Loader.h");
	getchar();
}
#endif // TEST_CF