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
class wrapper;
    
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
        cout<<"\nDefault Object constructor called!"<<endl;
    };
    Object(string Id,int i){ 
        this->id = Id;
        this->value = i;
   cout<< "\nthis is an int Object:  " << this->id << " : "<<
   std::get<int>(this->value) <<endl;
    };
    Object(string Id){ 
         this->id = Id;
        cout<<"\nID only " << this->id << " : "<<endl;
        
    };
    Object(string Id, myType t){ 
         this->id = Id;
         this->setValue(t);
        cout<<"\nID only " << this->id << " : "<<endl;
        
    };
    Object(string Id,string s){ 
         this->id = Id;
        this->value=s;
        cout<<"\nthis is a string Object: " << this->id << " : "<< std::get<string>(this->value)<<endl;
        
    };
    Object( Object *o){
        this->value=o;
        cout<<"\nthis is an Object: "<<endl;
        
    };
    Object(string Id,std::function<void(void)> f){
        this->id = Id;
        this->value=f;
        cout << "\nThis is a function malfunction: " <<endl;
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
        cout<< "New value set for Object : "<< this->getID()<<endl;
    }

    void setID(string v){
       this->id=v;
       cout<< "New id set for Object : "<< this->getID()<<endl;
    }

   int getArrayIndex(){
        return this->arrayIndex;
    }

    void setArrayIndex(int x){
        this->arrayIndex=x;
    }
    void setList(vector<Object> l){
       this->list=l;
       cout<< "FUUUUUUUUCK"<<endl;
    }

    Object& operator= (myType t){

        this->setValue(t);
        if(t.index()==3){
            //string
            cout<<"Value of: "<<this->id<< " updated to-->"<<std::get<string>(this->value) <<endl;
        }
        else if(t.index()==4){
            //object
            cout<<"Value of: "<<this->id<< " updated to--> object"<<endl;
        }
        else if(t.index()==5){
            //method
            cout<<"Value of: "<<this->id<< " updated to--> method"<<endl;
        }
        
        return *this;
    }

    Object& operator= (int value){
         this->value=value;
         cout<<"Value of: "<<this->id<< " updated to--> "<<std::get<int>(this->value)<<endl;
         return *this;
    }
    Object& operator= (double value){
         this->value=value;
         cout<<"Value of: "<<this->id<< " updated to--> "<<std::get<double>(this->value)<<endl;
         return *this;
    }

    // Object& operator= (string v){
    //     if(this->value.index() != -1){
    //         cout<< "Object found but already has value"<<endl;
    //        Object temp = Object(this->getID(),v);
    //        *this = temp;

    //     }
    //     return *this;
    // }
    // Object& operator= (Object* value){
    //      this->value=value;
    //      return *this;
    // }
    // Object& operator= (std::function<void(void)> f){
    //      this->value= f;
    //      return *this;
    // }
    Object& operator= (long int value){
        cout<< "-"<<endl;
         this->value= "NaN";
         return *this;
    }

        Object& operator, (Object o){
        cout<<" OPERATION: Object, Object"<<endl;
        if(this->list.size() == 0) list.push_back(*this);
         this->list.push_back(o); 
        return *this;
    }

        Object& operator, (myType val){
        cout<<"OPERATION: Object, myType"<<endl;
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
        cout<< " Im not even a wrapper though!" << endl;
    };

    wrapper(Object o){
        cout<<"Wrapper constructor with Object args"<<endl<<endl;
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
        cout<<"wrapper[Object]"<<endl;
       this->obj_vector= o.getList() ;
         return *this;
    }

 
    Object& operator[](string objID){
         return find(objID);
    }

    wrapper& operator, (Object o){
            cout<< "OPERATION: Object, Wrapper"<<endl;
            this->getList().insert(this->getList().end(),o.getList().begin(), o.getList().end());
            return *this;
    }

        
    void print(){
         for(int i =0; i< this->getObjVector().size();i++){

            switch(this->getObjVector()[i].getValue().index()){

                case 0:
                case 2:
        cout<<this->getObjVector()[i].getID()<<" : "
        << std::get<int>(this->getObjVector()[i].getValue())<<endl;
                    break;


                case 1 :
                 cout<<this->getObjVector()[i].getID()<<" : "
        << std::get<double>(this->getObjVector()[i].getValue())<<endl;
                    break;
            
                case 3:
                    cout<<this->getObjVector()[i].getID()<<" : "
        << std::get<string>(this->getObjVector()[i].getValue())<<endl;
                    break;
                case 4:
                 cout<<this->getObjVector()[i].getID()<<" : "
        << " Object "<<endl;
                    break;
                case 5:
                   cout<<this->getObjVector()[i].getID()<<" : "
        << " Method "<<endl;
                    break;
                default:
                    cout<<this->getObjVector()[i].getID()<<" : "
                 << "NaN "<<endl;
                    break;
            }
        }
    }
};

namespace helpers{
    void hello()
{
    cout << "hello"<<endl;
}
myType getInput(string s){
        cout<< s;
       myType in = std::cin.get();
        return in;
    };
}