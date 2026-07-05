#include "student.hh"
#include <iostream>
void student::printinfo(){
    std::cout<< "studentinfo:"<<std::endl;
    std::cout<< "sno = "<<_sno<<std::endl;
    std::cout<< "name = "<<_name<<std::endl;
    std::cout<< "age = "<<_age<<std::endl;
}