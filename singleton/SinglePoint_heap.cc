#include <iostream>
using std::cout;
using std::endl;
//堆空间单例方法
class Point{
public:
    static Point* getInstance(){
        if(instancep == nullptr){
            instancep = new Point(1,2);
        }
        return instancep;
    }
    static void destory(){
        if(instancep){
            delete instancep;
            instancep = nullptr;
        }
    }
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
    ~Point(){
        cout<< "~Point()"<<endl;
    }
    //从本类中被删除，保证无法在类内也赋值复制
    Point(const Point & rhs) = delete;
    Point & operator=(const Point & rhs) = delete;

    void print() const{
        cout<<"("<<this->_ix<<","<<this->_iy<<")"<<endl;
    }
    private:
        Point(int x,int y = 0):_ix(x),_iy(y){
            cout<<"Point(int,int)"<<endl;

        }
        static Point* instancep;
        int _ix;
        int _iy;

};
Point* Point::instancep = nullptr;

void test1(){
    //单例模式的规范写法
    Point::getInstance();
}
int main(){
    return 0;
}