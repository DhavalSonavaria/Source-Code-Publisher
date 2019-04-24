#include "CommentHandler.h"



CommentHandler::CommentHandler(std::string Line)
{
	line_ = Line;
	std::cout << line_;
	std::string single = "/";std::string open = "\ ";;std::string close = "*";
	if (line_.find(single))
	{
		std::cout << "first";
		HandleSingle();
	}
	if (line_.find(open))
	{
		std::cout << "second";
		HandleMultiOpen();
	}	
	if (line_.find(close)) 
	{
		std::cout << "third";
		HandleMultiClose();
	}
}

void CommentHandler::HandleSingle()
{
	size_t found = line_.find("//");
	std::cout << found;
	line_.insert(found, spano);
	line_ = line_ + spanc;
}

int CommentHandler::FindSubstringIndex(const std::string *parentstring, const std::string *substring)
{
		int e = 0, indx = -1;
		const char *parentcstring = parentstring->c_str();
		const char *csubstring = substring->c_str();

		for (int i = 0; i < strlen(parentcstring); i++) {
			if (parentcstring[i] == csubstring[e]) {
				if (e == 0)
					indx = i;
				e++;
				if (e == strlen(csubstring)) {
					return indx;
				}
				else {
					e = 0;
				}
			}
		}
		return -1;
}
void CommentHandler::HandleMultiOpen()
{
	size_t found = line_.find("\*");
	if (found != std::string::npos) 
		line_.insert(found, spano);
		line_ = line_ + spanc;
	
}
void CommentHandler::HandleMultiClose()
{

}
const CommentHandler::line & CommentHandler::ReturnLine() const
{
	return line_;
}
CommentHandler::~CommentHandler()
{
}
int main()
{
	std::string st = ("This is a test");
	CommentHandler ch(st);
	std::cout<< ch.ReturnLine();getchar();
	return 0;
	
}
