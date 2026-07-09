#include<iostream>
using namespace std;
void change(int* x){
    *x = 100;
}
int main(){
    int a = 1;
    cout <<"a = "<<a<<endl;
    change(&a);
    cout<<"after change: a= "<<a<<endl;
    return 0;
}
