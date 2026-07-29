#include <iostream>
using std::cout;
using std::endl;
//堆空间单例方法
class Singleton{
public:
    static Singleton* getInstance(){
        if(instancep == nullptr){
            instancep = new Singleton(1,2);
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
    ~Singleton(){
        cout<< "~Singleton()"<<endl;
    }
    //从本类中被删除，保证无法在类内也赋值复制
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;

    void print() const{
        cout<<"("<<this->_ix<<","<<this->_iy<<")"<<endl;
    }
    private:
        Singleton(int x,int y = 0):_ix(x),_iy(y){
            cout<<"Singleton(int,int)"<<endl;

        }
        static Singleton* instancep;
        int _ix;
        int _iy;

};
Singleton* Singleton::instancep = nullptr;

class AutoRelease{
public: 
    AutoRelease(Singleton* p):_p(p){
        cout<<"AutoRelease(Singleton)"<<endl;
    }

    ~AutoRelease(){
        cout<<"~AutoRelease"<<endl;
        if(_p){
            delete _p;
            _p = nullptr;
        }
    }
private:
    Singleton* _p;
};

void test1(){
    //单例模式的规范写法
    AutoRelease autorelease(Singleton::getInstance());
}
int main(){
    test1();
    return 0;
}