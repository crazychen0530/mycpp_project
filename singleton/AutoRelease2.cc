/**
 * @file AutoRelease2.cc 
 * @author fuckingchen(you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-07-29
 * 嵌套类+静态成员实现自动释放空间
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
using std::cout;
using std::endl;
//堆空间单例方法
class Singleton{
    class Autorelease{
    public:
        Autorelease(){
            cout<<"Autorelease()"<<endl;
        }
        ~Autorelease(){
            cout<<"~Autorelease"<<endl;
            if(instancep){
                delete instancep;
                instancep = nullptr;
            }
        }
    };
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
        static Autorelease _ar;
        int _ix;
        int _iy;

};
Singleton* Singleton::instancep = nullptr;
Singleton::Autorelease Singleton::_ar;
void test1(){
    //单例模式的规范写法
    Singleton::getInstance()->init(7, 8);
    Singleton::getInstance()->print();
}
int main(){
    return 0;
}