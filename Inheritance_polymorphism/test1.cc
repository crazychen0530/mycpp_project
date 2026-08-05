#include <iostream>
#include <cstring>
using std::endl;
using std::cout;

class Person{
    
public:
    char* _name;
    int _age;
    Person(const char* name,int age): _name(new char[strlen(name)+1]),_age(age){
        strcpy(_name,name);
    }
    void display ()const{
        cout<<" name: "<<_name<<" age: "<<_age<<endl;
    }

    Person(const Person& other){
        _name = new char[strlen(other._name) + 1];
        strcpy(_name,other._name);
        _age = other._age;
    }
    Person& operator=(const Person& p1){
        if(this == &p1){
            return *this;
        }
        delete [] this->_name;
        _name = new char[strlen(p1._name) + 1];
        strcpy(_name,p1._name);
        _age = p1._age;
        return *this;
    }
    ~Person(){
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
    }
};

class Employee : public Person{
    char* _department;
    double _salary;
public:
    Employee(const char* name,int age,const char* department,double salary)
    :Person(name, age),_department(new char[strlen(department)+1]),_salary(salary){
        strcpy(_department,department);
    }
    void display()const {
        cout<<"name: "<<_name<<" age: "<<_age<<" department: "<<_department<<" salary: "<<_salary<<endl;
    }

    Employee(const Employee& other):Person(other),_department(new char[strlen(other._department) + 1]),_salary(other._salary){
        strcpy(_department,other._department);
    }
    Employee& operator=(const Employee& e1){
        if(this == &e1){
            return *this;
        }
        char* new_department = new char[strlen(e1._department) +1 ];
        strcpy(new_department,e1._department);
        Person::operator=(e1);
        delete [] this->_department;
        _department = new_department;
        _salary = e1._salary;
        return *this;
    }
    ~Employee(){
        if(_department){
            delete [] _department;
            _department = nullptr;
        }
    }
};

int main(){
    Employee e1("czy",22,"c++ dev",10000);
    e1.display();
    Employee e2 = e1;
    e2.display();
    Employee e3("ysf",52,"constructor",80000);
    e3.display();
    e3 = e1;
    cout<<" after"<<endl;
    e3.display();
    return 0;
}