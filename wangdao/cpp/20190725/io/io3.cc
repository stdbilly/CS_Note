 ///
 /// @file    io3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-25 16:23:09
 ///
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

//做格式转换:
//	> 把其他类型的数据转换成字符串
//	> 把字符串转换成其他类型数据

void printStreamStatus(stringstream & ifs)
{
	cout << "ifs's badbit = " << ifs.bad() << endl;
	cout << "ifs's failbit = " << ifs.fail() << endl;
	cout << "ifs's eofbit = " << ifs.eof() << endl;
	cout << "ifs's goodbit = " << ifs.good() << endl;
}

void test0()
{
	stringstream ss;
	int number1 = 100;
	int number2 = 101;

	//当成字符串输出流使用
	ss << "number1= " << number1
	   << " number2= " << number2; 
	string line = ss.str();
	cout << line;

	string key;
	int value;
	
	while(!ss.eof()) {
		//当成字符串输入流使用
		ss >> key >> value;
		printStreamStatus(ss);
		cout << key << " --> " << value << endl; 
	}
}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}


void readConfig(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "ifstream open file " << filename << " error!" << endl;
		return;
	}

	string line;
	struct Info
	{
		Info(const string & k, const string &v)
		: key(k)
		, value(v)
		{}

		string key;
		string value;
	};

	vector<Info> config;
	while(getline(ifs, line)) {
		istringstream iss(line);	
		string key, value;
		while(!iss.eof()) {
			iss >> key >> value;	
			config.push_back(Info(key, value));
		}
	} 

	for(auto & info : config) {
		cout << info.key << " --> " << info.value << endl;
	}
}

void test1()
{
	string filename = "server.conf";
	readConfig(filename);
}
 
int main(void)
{
	//test0();
	test1();

	return 0;
}
