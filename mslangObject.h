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
class wrapper;

typedef std::variant<int, string, bool, double> myval;
    
typedef std::variant<
    int, 
    double,
    bool, 
    string, 
    Object*,
    std::function<void(void)> > 
    myType;



class Object {
private:

    int arrayIndex=0;
    string id;
    vector<Object> list;
    myType value;

public:

    Object(){
    };
    Object(string Id,int i){ 
        this->id = Id;
        this->value = i;
    };
    Object(string Id){ 
         this->id = Id;
    
        
    };
    Object(string Id, myType t){ 
         this->id = Id;
         this->setValue(t);
    };

    Object(string Id,string s){ 
         this->id = Id;
        this->value=s;
    };

    Object( Object *o){
        this->value=o;
    };

    Object(string Id,std::function<void(void)> f){
        this->id = Id;
        this->value=f;
    };

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
    }

    void setID(string v){
       this->id=v;
    }

   int getArrayIndex(){
        return this->arrayIndex;
    }

    void setArrayIndex(int x){
        this->arrayIndex=x;
    }
    void setList(vector<Object> l){
       this->list=l;
    }

    Object& operator= (myType t){

        this->setValue(t);
        if(t.index()==3){
            //string
        }
        else if(t.index()==4){
            //object
        }
        else if(t.index()==5){
            //method
        }
        
        return *this;
    }

    Object& operator= (int value){
         this->value=value;
         return *this;
    }
    Object& operator= (double value){
         this->value=value;
         return *this;
    }

    Object& operator= (long int value){
         this->value= "NaN";
         return *this;
    }

        Object& operator, (Object o){
        if(this->list.size() == 0) list.push_back(*this);
         this->list.push_back(o); 
        return *this;
    }

        Object& operator, (myType val){
            Object newObj(std::to_string(arrayIndex));
            this->arrayIndex++;
            newObj = val;
            this->list.push_back(newObj);
            return *this;
        }   
    
   
};


class wrapper : public Object{
    private:

    vector<Object> obj_vector;

    public:
    wrapper(){
    
    };

    wrapper(Object o){
   
    };
    ~wrapper(){};

    Object& find(string id){

        for (auto it = begin (this->obj_vector); it != end (this->obj_vector); ++it) {
            
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
       
       this->obj_vector= o.getList() ;
         return *this;
    }

 
    Object& operator[](string objID){
         return find(objID);
    }

    wrapper& operator, (Object o){
        
            this->getList().insert(this->getList().end(),o.getList().begin(), o.getList().end());
            return *this;
    }
        
    void print(){
        cout << "Object [";
         for(int i =0; i< this->getObjVector().size();i++){
            switch(this->getObjVector()[i].getValue().index()){

                case 0:
                
        cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << std::get<int>(this->getObjVector()[i].getValue());
                    break;


                case 1 :
                 cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << std::get<double>(this->getObjVector()[i].getValue());
                    break;
                case 2:      
       cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << std::get<bool>(this->getObjVector()[i].getValue());
                break;
                case 3:
                    cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << std::get<string>(this->getObjVector()[i].getValue());
                    break;
                case 4:
                 cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << " Object ";
                    break;
                case 5:
                   cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
        << " Method ";
                    break;
                default:
                    cout<<"\""<<this->getObjVector()[i].getID()<<"\" : "
                 << "NaN ";
                    break;
            }
            cout<<", ";
        }
        cout<<"]"<<endl;
    }
};


std::istream& operator >>(std::istream& in, myType& v){
        switch (v.index()){
            case 0: 
            int i;
                in >> i;
               v=i;
                break;
            case 1:
            double d;
            in>>d;
            v=d;
                break;
        
            case 2:
               bool b;
               in>>b;
               v=b;  
                break;
            case 3:
            string s;
            in>>s;
            v=s;    
                break;
        }
    return in;
    }

namespace helpers{
    void hello()
{
    cout << "hello"<<endl;
}
myType getInput(string s){
        cout<< s;
       myType in;
        std::cin >> in;
        return in;
        }

}
