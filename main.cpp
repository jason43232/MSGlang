#include "preprocDefs.h"

int add()
{
    cout << "hello"<<endl;
    return 0;
}

int main()
{
    let i1 = object[key("Den htan")=12];
    auto i1 = wrapper(object())[key("Den htan")=12];

    wrapper(object()) EXPECTS(object) object("den htan") setValue 12
    let i2 = object(object("key2","work") );
    let i3 = object("key3",&add);
    let i4 = object("overloaded")= "YEAAAHHA";

    // let i5 = object[ values val1, val2, val3... ];
    // values -->  val1, val2, val3 ]

     cout << std::get<string>(i4.getValue())<<endl;


  //cout << std::get<string>(i2.getValue());

    let w1 = wrapper {i1,i2,i3,i4};

    return 0;
}