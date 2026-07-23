#include "Mylogger.hh"
#include <execution>
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

using namespace log4cpp;

Mylogger::Mylogger(): _mycat(Category::getRoot().getInstance("mycat")){
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");//d日期，c记录器名，p优先级，m消息msg，n换行符
    auto ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    auto pos = new OstreamAppender("console",&std::cout);
}