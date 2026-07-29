/**
 * @file atexit.cc
 * @author fuckingchen  (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-07-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
 #include<iostream>

 #include <stdlib.h>
 using namespace std;
void print(){
    cout<<"print"<<endl;
}
void test(){
    atexit(print);
}
 int main(void){
    test();


    return 0;
 }