#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/Category.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

void test0(){
    //1.设置布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    //2.设置目的地
    OstreamAppender* pos = new OstreamAppender("console",&cout);
    pos->setLayout(ptn1);
    
    //创建记录器
    Category& cat = Category::getInstance("cate");
    cat.setPriority(Priority::WARN);
    cat.addAppender(pos);

    cat.error("this is an error msg");
    Category::shutdown();
}

int main(void){
    test0();
    return 0;
}