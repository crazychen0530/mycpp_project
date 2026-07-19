#include <iostream>
using std::cout;
using std::endl;
class Base{
private:
    int _n;
public:
    Base(const int& n):_n(n){};
    Base& operator+(const Base& B){
        _n += B._n;
        return *this; 
    }
    bool operator==(int res){//_n ==9 res == 5
        return !(_n == res);
    }
};

int main(void){
    int i = 2;
    int j = 7;
    Base x(i);
    Base y(j);
    cout<< (x+y == j - i)<< endl;
    return 0;
}