#include "preprocDefs.h"

void hello()
{
    cout << "hello"<<endl;
}

int main()
{
    let i1 = object[
    key("1")=12.3,
    key("2")= 12,
    key("3")= none,
    key("4")= "3",
    key("5")= "3",
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

    //let i2 = object [ values 1, "2", true, -3.14];


//Π.χ. Είναι legit το ακόλουθο:

// let o7 = object [ 
// values 77, "Kappa", true, lambda { /* .. */},
// object [ 
//     values 3.14, "Hello", 9 ],
// object [
//     key("x") = "Peter",
//     key("y") = none,
//     func("add") {
//     return object [
//         key("x") = self(x) + arg(x),
//         key("y") = self(y) + arg(y)
//         ];
//         }
//     ]
// ];
                    // int 1,2,3,4,5
                    // int(1),int(2)
    //auto i2 = wrapper(Object()).obj_vector.push_back(Object());

                                                    

     // store a lambda
    // std::function<void()> f_display_42 = []() { print_num(42); };
    // f_display_42();
    // ];
  
    // cout << ref(i1).getObjVector().size()<<endl;
    // i1["8"].getValue();
   
        // for(int i =0; i< i1.getObjVector().size();i++){
        // cout<<"++++"<< i1.getObjVector()[i].getID()<<endl;
        // }
//    cout<< "index:" <<i1["1"].getValue().index()<<endl;

//     i1["1"] = 13.2;
//    cout<< "index:" <<i1["1"].getValue().index()<<endl;
//     i1["1"] = "this is a string";
//    cout<< "index:" <<i1["1"].getValue().index()<<endl;
    


  
   
       return 0;
}