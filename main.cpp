#include "preprocDefs.h"
int main()
{
    let i1 = object[
    key("1")=12.3,
    key("2")= 12,
    key("3")= none,
    key("4")= "3",
    values 3,true,3.2,
    key("6")= "3",
    key("7")= "3",
    object[
        key("o") = 1,
        key("m") = 2,
        key("g") = 3,
            object[
                key("lol1") = 1,
                key("lol2") = 1,
                key("lol3") = 1
            ]
    ],
    func("8"){ cout<< "Hello!";},
    key("9")= lambda{ cout<< "I am a lamda";}
    ];
   cout<<i1["6"].getValue().index()<<endl;

    i1["6"] = input("6:");
   i1.print();
   cout<<i1["6"].getValue().index()<<endl;

  
   
       return 0;
}