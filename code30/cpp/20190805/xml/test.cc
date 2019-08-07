 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-05 09:43:17
 ///
 
#include "tinyxml2.h"
#include <iostream>
#include <regex>
#include <string>
using std::cout;
using std::endl;
using std::string;

using namespace tinyxml2;

void test0()
{ 
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	if(doc.ErrorID()) {
		cout << "XMLDocument load file error!" << endl;
		return ;
	}

	XMLElement * itemNode = doc.FirstChildElement("rss")
		->FirstChildElement("channel")
		->FirstChildElement("item");

	do {
		XMLElement * titleNode = itemNode->FirstChildElement("title");
		const char * title = titleNode->GetText();
		cout << "title: " << title << endl;

		XMLElement * linkNode = itemNode->FirstChildElement("link");
		const char * link = linkNode->GetText();
		cout << "link: " << link << endl;

		XMLElement * contentNode = itemNode->FirstChildElement("content:encoded");
		const char * content = contentNode->GetText();
		//cout << "content: " << content << endl;

		std::regex re("<.+?>");
		
		//learning by doing
		string contentProcessed = std::regex_replace(content, re, "");
		cout << "content: " << contentProcessed << endl;

	}while(itemNode = itemNode->NextSiblingElement("item"));
}
 
int main(void)
{
	test0();
 
	return 0;
}
