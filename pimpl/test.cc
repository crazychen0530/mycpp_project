#include "Line.hh"
#include <iostream>
#include <utility>
using std::cout;
using std::endl;

void test0(){
    Line ll(1,2,3,4);
    ll.PrintLine();
}

int main(){
    test0();
    return 0;
}