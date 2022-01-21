#include "preprocDefs.h"

int add()
{
    cout << "hello"<<endl;
    return 0;
}

int main()
{
    let i1 = object[
    key(1)=12,
    key(2) = "XYNNN",
    key(3)= none,
    key(4)= "3",
    key(5)= "3",
    key(6)= "3",
    key(7)= "3",
    key(8)= &add
    ];
  
  cout << ref(i1).getObjVector().size()<<endl;

   
        for(int i =0; i< i1.getObjVector().size();i++){
        cout<<"++++"<< i1.getObjVector()[i].getID()<<endl;
        }

/*  

*/


   cout<< "index:" <<i1["1"].getValue().index()<<endl;

    i1["1"] = 13.2;
   cout<< "index:" <<i1["1"].getValue().index()<<endl;
    i1["1"] = "this is a string";
   cout<< "value:" <<i1["1"].getValue().index()<<endl;
   
   cout<< "value:" <<std::get<string>( i1["1"].getValue())<<endl;

    return 0;
}