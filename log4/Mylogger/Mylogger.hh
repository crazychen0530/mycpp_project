#ifndef MY_LOGGER_HH
#define MY_LOGGER_HH

#include <log4cpp/Category.hh>

class Mylogger
{
public: 
    void warn(const char* msg);
    void error(const char* msg);
    void debug(const char* msg);
    void info(const char* msg);
    static Mylogger* getInstance();
    static void destory();
    Mylogger(const Mylogger&) = delete;
    Mylogger& operator=(const Mylogger&) = delete;
private:
    Mylogger();
    ~Mylogger();
private:
    log4cpp::Category& _mycat;
    static Mylogger* _pInstance;
};

Mylogger* Mylogger::_pInstance = nullptr;
#endif