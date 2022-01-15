#include "MSGlang.h"
#define let auto
#define object object(_VA_LIST)
int main()

{
    let o1 = object;
    o1.setName("o1");
    cout << "Object name: " << o1.getName() << endl;
    o1.addPair("id1", "value1");
    cout << o1.getPairs().size();

    return 0;
}