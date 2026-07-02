#include <iostream>
namespace Myspace{
    void swap(int &a,int& b);
}

int main(){
    int a = 10;
    int b = 5;
    Myspace::swap(a,b);
    std::cout<<a<<std::endl<<b;
    return 0;
}