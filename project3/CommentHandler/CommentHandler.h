#pragma once
#include <string>
#include<iostream>
class CommentHandler
{
	using line = std::string;
public:
	CommentHandler(std::string);
	void HandleSingle();
	int FindSubstringIndex(const std::string*, const std::string*);
	void HandleMultiOpen();
	void HandleMultiClose();
	const line& ReturnLine() const;
	~CommentHandler();
private:
	line line_;
	line spano = "<span";
	line spanc = "</span>";
};

