#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Person {
public:
    Person(const char* name, int age) 
        : _name(new char[strlen(name)+1]())
          , _age(age) {
              strcpy(_name, name);
              cout << "Person(char* name, int age)" << endl;
          }

    ~Person() {
        if(_name) delete [] _name; 
        cout << "~Person()" << endl; 
    }

    void display() {
        cout << "name:" << _name << ", " << "age:" << _age << endl;
    }
private:
    char* _name;
    int _age;
};

class Employee :public Person {
public:
    Employee(const char* name, int age,const char* department, int salary) 
        : Person(name,age)
    , _department(new char[strlen(department)+1]())
          , _salary(salary) {
              strcpy(_department, department);
              cout << "Employee(char* name, int age, char* department, int salary)" << endl;
          }

    void display() {
        Person::display();
        cout << "department:" << _department << ", " << "salary:" << _salary << endl;  
    }

    int getSalary() {
        return _salary;
    }

    ~Employee() { 
        if(_department) delete [] _department;
        cout << "~Employee()" << endl; 
    }
private:
    char* _department;
    int _salary;
};

void test1() {
    Employee e1("john",20,"WXG",17000);
    Employee e2("lily",21,"TEG",15000);
    Employee e3("martin",22,"WXG",19000);
    e1.display();
    e2.display();
    e3.display();
    int avg = (e1.getSalary() + e2.getSalary() + e3.getSalary()) / 3;
    cout << "averge salary = " << avg << endl;
}

int main() {
    test1();
    return 0;
}

