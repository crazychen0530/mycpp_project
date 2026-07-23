#include "Mylogger.hh"

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <string>

using namespace log4cpp;
Mylogger* Mylogger::_pInstance = nullptr;
Mylogger::Mylogger(): _mycat(Category::getRoot().getInstance("mycat")){
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");//d日期，c记录器名，p优先级，m消息msg，n换行符
    auto ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    auto pos = new OstreamAppender("console",&std::cout);
    pos->setLayout(ptn1);//绑定布局

    auto pfile  = new FileAppender("fileApp","chenziyou.log");
    pfile->setLayout(ptn2);

    _mycat.setPriority(Priority::DEBUG);
    _mycat.addAppender(pos);
    _mycat.addAppender(pfile);
    std::cout<<"Mylogger()"<<std::endl;
}

Mylogger::~Mylogger(){
    Category::shutdown();
    std::cout<< "~Mylogger()"<<std::endl;
}

Mylogger* Mylogger::getInstance(){
    if(nullptr == _pInstance){
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destory(){
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char* msg){
    _mycat.warn(msg);
}
void Mylogger::error(const char* msg){
    _mycat.error(msg);
}
void Mylogger::debug(const char* msg){
    _mycat.debug(msg);
}
void Mylogger::info(const char* msg){
    _mycat.info(msg);
}

