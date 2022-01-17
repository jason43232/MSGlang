#include "preprocDefs.h"

int add()
{
    cout << "hello"<<endl;
    return 0;
}

int main()
{
    let i1 = object("Den htan",12);
    let i2 = object(object("key2","work") );
    let i3 = object("key3",&add);
    let i4 = object("overloaded")= "YEAAAHHA";
   

     cout << std::get<string>(i4.getValue())<<endl;


  //cout << std::get<string>(i2.getValue());

    let w1 = wrapper {i1,i2,i3,i4};


    //o1.insert("key1", static_cast<string>("value1") );
    //o1.insert(std::pair<string,string>("key1","value"));
    return 0;
}