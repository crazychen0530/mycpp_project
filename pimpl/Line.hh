#ifndef __LINE_HH_
#define __LINE_HH_

class Line{
public: 
    Line(int x1,int y1,int x2,int y2);
    ~Line();
    //提供给客户的功能。
    void PrintLine() const;//打印line信息
private:
    class LineImpl;//类的向前声明
    LineImpl* _pimpl;
};


#endif