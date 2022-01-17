//
// Created by Ιάσονας Νταγιάννης on 14/1/22.
//

#ifndef MSLANG_OBJECT_H
#define MSLANG_OBJECT_H
#endif // MSLANG_OBJECT_H
#include <iostream>
#include <map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <iterator>
#include <vector>
#include <variant>
using std::cout, std::endl, std::string, std::vector;

class object {
private:
    string id;

    std::variant<
    int, 
    double, 
    string, 
    object*,
    std::function<void(void)> >
    value;

public:

    object(){};
    object(string Id,int i){ 
        this->id = Id;
        this->value = i;
   cout<< "this is an int object:  " << this->id << " : "<<
   std::get<int>(this->value) <<endl;
    };
    object(string Id){ 
         this->id = Id;
        cout<<"ID only " << this->id << " : "<<endl;
        
    };
    object(string Id,string s){ 
         this->id = Id;
        this->value=s;
        cout<<"this is a string object: " << this->id << " : "<< std::get<string>(this->value)<<endl;
        
    };
    object( object *o){
        this->value=o;
        cout<<"this is an object: "<<endl;
        
    };
    object(string Id,std::function<int(void)> f){
         this->id = Id;
        this->value=f;
        cout << "This is a function malfunction: " <<endl;
    }
    ~object(){};

    auto getValue(){
        return this->value;
    }

    object& operator= (string value){
        this->value=value;
        return *this;
    }
    object& operator= (int value){
         this->value=value;
         return *this;
    }
    object& operator= (object* value){
         this->value=value;
         return *this;
    }
    object& operator= (double value){
         this->value=value;
         return *this;
    }
    // object& operator= ()
};


class wrapper {
    private:

    std::vector<object> obj_vector;

    public:
    wrapper(){
        cout<< " Im not even a wrapper though!" << endl;
    };
    wrapper(std::initializer_list<object> li):obj_vector(li){
     cout << this->obj_vector.at(0).getValue().index() << endl;
     cout << this->obj_vector.at(1).getValue().index() << endl;
     cout << this->obj_vector.at(2).getValue().index() << endl;
     cout << this->obj_vector.at(3).getValue().index() << endl;
    };
    ~wrapper(){};
    
};








// class mslangPair;
// typedef std::vector<mslangPair> pairVector;
// class mslangObj{
//     private:
//     std::any std_value;
//     pairVector list;
    
//     public:
//     mslangObj():list(NULL){};
//     mslangObj(std::any a): std_value(a){};
//     mslangObj(pairVector l): list(l){};
//     ~mslangObj(){};


    
//     std::any getStdValue(){
//       return  this->std_value ;
  
//     }
//     pairVector getList(){

//         return this->list;
//     }

//     mslangObj& operator[] (pairVector v){
//         this->list=v;
//         return *this;
//     }
//     mslangObj& operator[] (mslangPair *v){
//         this->list.push_back(*v);
//         return *this;
//     }




// };



// class mslangPair{

// private:
//     string key;
//     mslangObj value;

// public:
//     mslangPair(): key(), value(){};
//     mslangPair(string key): key(key), value(){};
//    mslangPair(string key, mslangObj val): key(key),value(val){};
//     ~mslangPair(){};

//     string getKey(){
//         return this->key;
//     }

//     mslangObj& getValue(){
//         return this->value;
//     }

//     mslangPair& operator= (mslangObj *val){
//         this->value = *val;
//         return *this;
//     }
//     mslangPair& operator= (string *val){
//         this->value = (mslangObj)*val;
//         return *this;
//     }
   
//     mslangPair& operator= (int val){
//         this->value = (mslangObj)val;
//         return *this;
//     }


// };