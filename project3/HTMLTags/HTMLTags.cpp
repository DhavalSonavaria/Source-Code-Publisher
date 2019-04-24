#include "HTMLTags.h"



HTMLTags::HTMLTags()
{
}

std::vector<std::string> HTMLTags::addPreCodeHTML(std::string filename)
{
	std::cout << filename;
	std::ifstream in("..//HTMLdata.txt");
	std::vector<std::string> data;
	std::string line;
	while (in.good()) {
		while (std::getline(in, line))
			data.push_back(line);
	}
	std::string title = "<h3>" + filename + "</h3>";
	data.push_back(title);
	return data;
}

std::string HTMLTags::addPreTag()
{
	std::string last = "</span></pre></body></html>";
	return last;
}
HTMLTags::~HTMLTags()
{
}
//#ifdef TEST_TAGS
//int main()
//{
//	HTMLTags ab;
//	std::vector<std::string> test = ab.addPreCodeHTML("Test.cpp");
//	for (auto i : test)
//		std::cout << i;
//	getchar();
//}
//#endif // DEBUG