#include "mslangObject.h"

 #define let auto
 #define object wrapper(Object())
 #define none __null
 #define key(x) Object(x)
 #define ref(x) x.getReference()
 #define func(x) Object(x) = []()
 #define lambda []()
 #define values Object(),
 #define input(x) helpers::getInput(x)

