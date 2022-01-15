#ifndef MSLANG_PAIR_H
#define MSLANG_PAIR_H
#endif // MSLANG_PAIR_H
#include "mslangObject.h"
using std::cout, std::endl, std::string;

class mslangPair{

private:
    string key;
    content val;

public:

    /*
    empty constructor
    */
    mslangPair(): key(), val(){};

    /*
    *empty object contructor
        e.g. let o1 = object [
            key("test") = none,
        ]
    */
    mslangPair(string key): key(key), val(){};

    /*
        full arguments constructor
    */
   mslangPair(string key, content val): key(key),val(val){};



    // Desturactoro...
    ~mslangPair(){};

    string getKey(){
        return this->key;
    }

    content& getValue(){
        return this->val;
    }

    mslangPair& operator= (content val){
        this->val = val;
        return *this;
    }

    // mslangPair& operator= (std::vector<mslangPair> list){
    //     this->val = list;
    //     return *this;
    // }
};