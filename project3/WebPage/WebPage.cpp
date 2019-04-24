#include "WebPage.h"



WebPage::WebPage()
{
}

void WebPage::skipSpecialChars(std::string & line)
{
	size_t pos = line.npos; while ((pos = line.find('<')) != line.npos) line.replace(pos, 1, "&lt;");
	while ((pos = line.find('>')) != line.npos) line.replace(pos, 1, "&gt;");
}



void WebPage::handlecommentsclose(std::string & line)
{
	size_t pos = line.find('*');
	if (pos == line.npos) return;
	if (pos == line.size() - 1) return;
	if (line[pos + 1] == '/')
	{
		line += "</div>";
	}
	return;
}

void WebPage::handlecomments(std::string & line)
{
	size_t pos = line.find('/');
	if (pos == line.npos) return;
	if (pos == line.size() - 1) return;
	if (line[pos + 1] == '/')
	{
		line.replace(pos, 1, "<div class =\"toggleComments\">/"); line += "</div>";
	}
	if (line[pos + 1] == '*')
	{
		line.replace(pos, 1, "<div class =\"toggleComments\">/");
	}
}


WebPage::~WebPage()
{
}