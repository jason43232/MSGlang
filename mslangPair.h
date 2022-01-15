#ifndef MSLANG_PAIR_H
#define MSLANG_PAIR_H
#endif // MSLANG_PAIR_H
#include "mslangObject.h"
using std::cout, std::endl, std::string;

class mslangPair{
// overload =

private:
    string key;
    value val;

public:

    //empty constructor
    mslangPair(): key(), val(){};

    /*
    *empty object contructor
        e.g. let o1 = object [
            key("test") = none,
        ]
    */
    mslangPair(string key): key(key), val(){}

    //
    ~mslangPair(){};

    string getKey(){
        return this->key;
    }

    value getValue(){
        return this->val;
    }



};