#include "preprocDefs.h"

/*

TODO KEYWODS
- key 
    ---ME OVERLOADINGGG---
	

    px. key(id)=val
        key(id)=lambda{return val;}
        map.at(id) = val

- object
- values
- none
- self
- arg
- ref
- func
- lamda


!   name = *xidiamas
!   let -->> mallon auto
!   key("id") = value ->>>> dhiourgei pair (string "id", any value)
*id === string
*key : value {int, string, double, bool, function, object}

* vector ,Args ->> vector.pushback(arg)
*Object operator,(){}

    key(x)=y
   newObj.addPair(make_pair( string "x",std::any y));

   let name = object[] -> auto name = object(pair...Args){ this.addPair}


   func : {}


template<typename ...Args>
void printer(Args&&... args)
{
    (std::cout << ... << args) << '\n';
}

stin main:
printer(1, 2, 3, "abc");

output: 123abc

condition ? result_if_true : result_if_false

 */
int main()

{

    // object test;
    // test.addPair("works", "yes");

    let o1 = object;
    int * test = none;

    o1->addPair("id1", "value1");

    auto it = o1->getPairs()->begin();
    string pClass1 = it->first;
    string pClass2 = it->second;
    cout<< pClass1 << " : " << pClass2 <<endl;

    return 0;
}