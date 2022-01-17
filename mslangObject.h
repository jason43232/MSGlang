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

template <typename T>
class mslangObj{
    private:
    T value;
    
    public:
    mslangObj():value(NULL){};
    mslangObj(T v):value(v){};
    ~mslangObj(){};


    T getValue(){
            return this->value;
}


    mslangObj operator[] (std::vector<mslangPair> v){
        this->value = v;
        return *this;
    }
    // mslangObj& operator[] (mslangPair v){
    //     this->value = v;
    //     return *this;
    // }

};



class mslangPair{

private:
    string key;
    mslangObj<string> cont;

public:

    /*
    empty constructor
    */
    mslangPair(): key(), cont(){};

    /*
    *empty object contructor
        e.g. let o1 = object [
            key("test") = none,
        ]
    */
    mslangPair(string key): key(key), cont(){};

    /*
        full arguments constructor
    */
   mslangPair(string key, mslangObj<string> val): key(key),cont(val){};



    // Desturactoro...
    ~mslangPair(){};

    string getKey(){
        return this->key;
    }

    mslangObj<string>& getContent(){
        return this->cont;
    }

    mslangPair& operator= (string val){
        this->cont = val;
        return *this;
    }

    

    // mslangPair& operator= (std::vector<mslangPair> list){
    //     this->val = list;
    //     return *this;
    // }
};



