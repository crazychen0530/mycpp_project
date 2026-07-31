#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
bool checkorder(int num,char** argv){
    if(num != 2){
        std::cerr<<"warn order"<<std::endl<<"usage : "<<argv[0]<<" yourfile";
        return false;
    }
    return true;
    
}
int main(int argc,char* argv[]){
    if(!checkorder(argc, argv)){
        return 1;
    }
    std::string filename = argv[1];
    std::ifstream inputfile(filename);
    std::ofstream outputfile("frequency.txt");
    if(!inputfile.is_open()){
        std::cerr<<"open file "<<argv[1]<<"failed"<<std::endl;
        return 1;
    }
    std::string line;
    std::map<std::string,int> frequency_map;
    while(std::getline(inputfile,line)){
        std::istringstream getword(line);
        std::string word;
        while(getword >> word){
            if(frequency_map.count(word)){
                frequency_map[word]++;
            }else{
                frequency_map.insert(std::make_pair(word, 1));
            }
        }
    }
    for(auto& ele : frequency_map){
        outputfile<<ele.first<<" times : "<<ele.second<<std::endl;
    }
    return 0;
}