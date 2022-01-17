//
// Created by Ιάσονας Νταγιάννης on 14/1/22.
//

#ifndef MSLANG_OBJECT_H
#define MSLANG_OBJECT_H
#endif // MSLANG_OBJECT_H
#include <iostream>
#include <map>
#include <any>
#include <iterator>
#include <vector>
using std::cout, std::endl, std::string;
class mslangPair;


class mslangObj{
    private:
    std::any value;
    std::vector<mslangPair> list;
    
    public:
    mslangObj():value(NULL){};
    mslangObj(std::any v):value(v),list(NULL){};
    mslangObj(std::vector<mslangPair> l): value(0),list(l){}
    ~mslangObj(){};


    std::any getValue(){
            return this->value;
}

    std::vector<mslangPair> getList(){

        return this->list;
    }


    mslangObj& operator[] (std::vector<mslangPair> v){
        this->list = v;
        return this;
    }
    

};



class mslangPair{

private:
    string key;
    mslangObj value;

public:

    /*
    empty constructor
    */
    mslangPair(): key(), value(){};

    /*
    *empty object contructor
        e.g. let o1 = object [
            key("test") = none,
        ]
    */
    mslangPair(string key): key(key), value(){};

    /*
        full arguments constructor
    */
   mslangPair(string key, mslangObj val): key(key),value(val){};



    // Desturactoro...
    ~mslangPair(){};

    string getKey(){
        return this->key;
    }

    mslangObj& getValue(){
        return this->value;
    }

    mslangPair& operator= (string val){
        this->value = val;
        return *this;
    }

    

    // mslangPair& operator= (std::vector<mslangPair> list){
    //     this->val = list;
    //     return *this;
    // }
};



