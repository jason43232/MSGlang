//
// Created by Ιάσονας Νταγιάννης on 14/1/22.
//

#ifndef MSG_LANG_MSGLANG_H
#define MSG_LANG_MSGLANG_H
#endif //MSG_LANG_MSGLANG_H
#include <iostream>
#include <map>
#include <any>
#include <iterator>
#include <vector>
using std::cout, std::endl, std::string;
class object
{
private:
    string name;
   std::vector<std::pair<string, string> > pairs;

public:
    object()
    {
       cout << "Object Created" << endl;
    };

    string getName(){
        return this->name;
    }
    void setName(string Name){
        this->name = Name;
    }

    std::vector<std::pair<string, string> > getPairs(){
        return this->pairs;
    }

    void addPair(string a, string b){

      this->pairs.push_back(std::make_pair(a,b));

    }
};