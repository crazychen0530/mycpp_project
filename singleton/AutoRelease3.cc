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
#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
//堆空间单例方法
class Singleton{
    
public:
    static Singleton* getInstance(){
        /*当多个线程进入if语句时
        会造成Singleton对象被创建出多个
        最终只会有一个对象的地址被_pInstance保存
        其他的对象就形成了内存泄漏*/
        if(instancep == nullptr){
            atexit(destory);
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
//初始化为空指针（懒汉式）/（饱汉式），优点：没有内存压力，需要时创建/ 缺点：无法保证多线程安全。
//Singleton* Singleton::instancep = nullptr;


//饿汉式    优点：保证多线程安全    缺点：内存压力较大
//一开始就将单例对象创建出来，即使程序中不使用这个单例对象  
Singleton* Singleton::instancep = Singleton::getInstance();
void test1(){
    //单例模式的规范写法
    Singleton::getInstance()->init(7, 8);
    Singleton::getInstance()->print();
}
int main(){
    return 0;
}