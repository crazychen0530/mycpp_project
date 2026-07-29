#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
//堆空间单例方法
class Singleton{
public:
    static Singleton* getInstance(){
        pthread_once(&once,init_r);
        return instancep;
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
    static void destory(){
        if(instancep){
            delete instancep;
            instancep = nullptr;
            cout<<"delete heap"<<endl;
        }
    }
    static void init_r(){
        instancep = new Singleton(1,2);
        atexit(destory);
    }
    Singleton(int x,int y = 0):_ix(x),_iy(y){
        cout<<"Singleton(int,int)"<<endl;

    }
    static Singleton* instancep;
    static pthread_once_t once ;
    int _ix;
    int _iy;

};
Singleton* Singleton::instancep = nullptr;
pthread_once_t Singleton::once = PTHREAD_ONCE_INIT;
void test1(){
    //单例模式的规范写法
    Singleton::getInstance();
    Singleton::getInstance()->init(7, 8);
    Singleton::getInstance()->print();
}
int main(){
    test1();
    return 0;
}