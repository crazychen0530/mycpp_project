#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

class TextQuery
{
public:
    void readFile(const string &filename);
    void query(const string &word);
    string dealWord(const string &word);
    void insertMapSet(const string &word, int lineNumber);
    string formatline(const std::string& str,const std::string& word);
private:
    vector<string> _lines; //每行数据存储在vector中
    map<string,set<int>> _wordNumbers; //存储单词即其行号的集合
    map<string, int> _dict; //存储每个单词即其次数
};

 //如果word中每一个单词都是一个字母即是一个合格的单词
string TextQuery:: dealWord(const string &word)
{
        for(size_t idx = 0; idx != word.size(); ++idx)
        {
            if(!isalpha(word[idx]))
            {   //只有有一位不是字母就返回空串
                return string();
            }
        }
        //满足所有的字符都是字母就返回这个word
        return word;
}


void TextQuery::insertMapSet(const string &word, int lineNumber)
{
    if(word.empty())
    {
        return;
    }
    _wordNumbers[word].insert(lineNumber);

}

 //先读到缓冲区,插入容器中,
void TextQuery::readFile(const std::string &filename)
{
        ifstream ifs(filename);
        if(!ifs){
            cerr<< "open" << filename << "fail" << endl;
            return;
        }

        string line;
        int lineNumber = 0;
        while(getline(ifs, line))
        {
            ++lineNumber;
            //lineNumber是从1开始的
            //存储的vector容器中是从0开始的
            //打印时记得每次lineNumber-1再从vector中输出
            _lines.push_back(line);
            istringstream iss(line);

            string word;
            while(iss >> word) //abc123 abc这种单词不需要统计
            {
                string newWord = dealWord(word);// 单词进行处理做处理
                insertMapSet(newWord, lineNumber);
                ++_dict[word];
            }
        }

        ifs.close();
}

std::string TextQuery::formatline(const std::string& str,const std::string& word)
{
    size_t idx = str.find(word);//you are  | very nice 
    std::string returnline = str;
    returnline.insert(idx," | ");
    returnline.insert(returnline.find(word)+ word.size(), " | ");
    return returnline;
}

void TextQuery::query(const string &word)
{
   //先查找_dict看看出现了多少次
   //再查找 _wordNumbers看其在多少行
   //然后打印行号和每行的数据
    auto it = _dict.find(word);
    if(it == _dict.end()){
        cout << "这个单词在文中没有出现" << endl;
    }else{
        cout << word << " occurs " << it->second << " times. " << endl;
        auto it2 = _wordNumbers.find(word);
        for(auto &num : it2->second)
        {
            cout << "( line" << num << ") ";
            string finalline = formatline(_lines[num - 1],word);
            cout<<finalline<<endl;
            
        }
    }

}

int main(int argc, char *argv[])
{
    
    while(1){
        std::string word;
        cin>>word;
        if(word == "-1"){
            std::cout<<"program is stop~"<<std::endl;
            break;
        }
        string queryWord(word);
        TextQuery tq;
        tq.readFile("china_daily.txt");
        tq.query(queryWord);
    }
   
    return 0;
}