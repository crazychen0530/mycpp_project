#ifndef MY_LOGGER_HH
#define MY_LOGGER_HH

#include <log4cpp/Category.hh>



#define addPrifix(msg) std::string("[").append(__FILE__) \
            .append(" : ").append(__func__) \
            .append(" : ").append(std::to_string(__LINE__)) \
            .append(" ] ").append(msg).c_str()

#define LogWarn(msg) Mylogger::getInstance()->warn(addPrefix(msg))
#define LogInfo(msg) Mylogger::getInstance()->info(addPrefix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(addPrefix(msg))
#define Logerror(msg) Mylogger::getInstance()->error(addPrefix(msg))

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


#endif