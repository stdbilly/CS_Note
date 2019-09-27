 ///
 /// @file    mvc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-13 11:08:32
 ///
 
#include <iostream>
#include <string>
#include <map>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::unique_ptr;

class Student
{
public:
	Student(int id, const string & name)
	: _id(id)
	, _name(name)
	{}

	int id() const {	return _id;	}
	string name() const {	return _name;	}	
private:
	int _id;
	string _name;
};

class View
{
public:
	View(Student * pstu = nullptr)
	: _pstu(pstu)
	{}

	void reset(Student * pstu)
	{	_pstu = pstu;	}

	virtual void show()
	{
		cout << "id:" << _pstu->id() << endl
			 << "name:" << _pstu->name() << endl;
	}
protected:
	Student * _pstu;
};

class SubView
: public View
{
public:
	void show() override
	{
		cout << "{id:" << _pstu->id() 
			 << ", name:" << _pstu->name()
			 << "}" << endl;
	}
};

class Controller
{
public:

	void attach(const Student & stu)
	{
		auto it = _students.find(stu.id());
		if(it == _students.end()) {
			_students.insert(std::make_pair(stu.id(), stu));
		}
	}

	void detach(int id)
	{
		auto it = _students.find(id);
		if(it != _students.end()) {
			_students.erase(id);
		}
	}

	void show(View * view)
	{
		for(auto & elem : _students) {
			view->reset(&elem.second);
			view->show();	
		}
	}

private:
	map<int, Student> _students;
};
 
int main(void)
{
	Controller controller;
	controller.attach(Student(100, "Jackie"));
	controller.attach(Student(101, "John"));
	controller.attach(Student(102, "Marry"));
	unique_ptr<View> myview(new View());
	controller.show(myview.get());

	cout << endl;

	unique_ptr<View>  myview2(new SubView);
	controller.show(myview2.get());

	return 0;
}
