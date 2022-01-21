//
// Created by Ιάσονας Νταγιάννης on 14/1/22.
//

#ifndef MSLANG_Object_H
#define MSLANG_Object_H
#endif // MSLANG_Object_H
#include <iostream>
#include <map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <iterator>
#include <vector>
#include <variant>
using std::cout, std::endl, std::string, std::vector;

class Object;
typedef std::variant<
    int, 
    double,
    bool, 
    string, 
    Object*,
    std::function<void(void)> > 
    myType;

class Object{
private:
    string id;
    vector<Object> list;
    myType value;

public:

    Object(){
        cout<<"Default Object constructor called!"<<endl;
    };
    Object(string Id,int i){ 
        this->id = Id;
        this->value = i;
   cout<< "this is an int Object:  " << this->id << " : "<<
   std::get<int>(this->value) <<endl;
    };
    Object(string Id){ 
         this->id = Id;
        cout<<"ID only " << this->id << " : "<<endl;
        
    };
    Object(string Id,string s){ 
         this->id = Id;
        this->value=s;
        cout<<"this is a string Object: " << this->id << " : "<< std::get<string>(this->value)<<endl;
        
    };
    Object( Object *o){
        this->value=o;
        cout<<"this is an Object: "<<endl;
        
    };
    Object(string Id,std::function<int(void)> f){
         this->id = Id;
        this->value=f;
        cout << "This is a function malfunction: " <<endl;
    }
    ~Object(){};

    auto getValue(){
        return this->value;
    }

    auto getID(){
        return this->id;
    }
    auto getList(){
        return this->list;
    }
    void setValue(myType v){
        this->value = v;
        cout<< "New value set for Object : "<< this->getID()<<endl;
    }

    void setID(string v){
       this->id=v;
       cout<< "New id set for Object : "<< this->getID()<<endl;
    }

    

    Object& operator= (string v){
        cout<< "INDEX:::"<< this->value.index()<<endl;
        if(this->value.index()!= -1){
            cout<< "Object found but already has value"<<endl;
            /*
            TODO: find a way to change type of value
            */
        }
        return *this;
    }
    Object& operator= (int value){
         cout<<"Overloaded="<<endl;
         this->value=value;
         cout<<"Value of: "<<this->id<< " updated to--> "<<std::get<int>(this->value)<<endl;
         return *this;
    }
    Object& operator= (Object* value){
         this->value=value;
         return *this;
    }
    Object& operator= (double value){
         this->value=value;
         cout<<"Value of: "<<this->id<< " updated to--> "<<std::get<double>(this->value)<<endl;
         return *this;
    }
    Object& operator= (long int value){
         this->value= "NaN";
         return *this;
    }
    Object& operator= (std::function<void(void)> f){
         this->value= f;
         return *this;
    }

        Object& operator, (Object o){
        cout<<"overloaded COMMA"<<endl;
        if(this->list.size() == 0) list.push_back(*this);
         this->list.push_back(o); 
        return *this;
    }
   
};


class wrapper{
    private:

    vector<Object> obj_vector;

    public:
    wrapper(){
        cout<< " Im not even a wrapper though!" << endl;
    };

    wrapper(Object o){
        cout<<"Wrapper constructor with Object args"<<endl;
    };
    ~wrapper(){};

    Object& find(string id){

        for (auto it = begin (this->obj_vector); it != end (this->obj_vector); ++it) {
            // cout<< it->getID()<<endl;
          if(it->getID() == id){
              return *it;
          }   
        }
                cout<<"Object with id: "<< id<< " not found!"<< endl;
            exit(1);
        }
       
    
    vector<Object> getObjVector(){
        return this->obj_vector;
    }
    wrapper& getReference(){
         return *this;
     }

    wrapper& operator[](Object o){
        cout<<"Overloaded[]"<<endl;
       this->obj_vector= o.getList() ;
         return *this;
    }
    Object& operator[](string objID){
        cout<<"Find : "<< objID <<endl;
         return find(objID);
    }
};
