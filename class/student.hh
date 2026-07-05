#ifndef STUDENT_H
#define STUDENT_H

class student{
    
    private:
        int _sno;
        const char* _name;
        int _age;

    public:
    student(int sno,const char* name,int age)
    :_sno(sno),_name(name),_age(age){

    }
    void printinfo();

};

#endif