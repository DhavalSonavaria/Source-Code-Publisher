#include<string>
class WebPage
{
public:
	WebPage();
	void skipSpecialChars(std::string& line);
	void handlecommentsclose(std::string &line);
	void handlecomments(std::string &line);
	~WebPage();
};
