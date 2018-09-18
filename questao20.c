//use garbage collection
#include "gc.hpp"
using namespace agm::gc;

//include some STL class for demonstrating the global use of operator 'new'
#include <list>
using namespace std;

//a class that is not automatically finalized
class Foo {
public:
};

//a class that is automatically finalized
class Bar : public Object {
public:
};

//main
int main()
{
    //allocate a Foo object with macro GC_NEW 
    //because it is not automatically finalized
    Foo *obj1 = GC_NEW(Foo)();

    //allocate an STL list that is not automatically finalized;
    //nodes will be freed by the collector
    list<INT> *obj2 = new list<INT>;

    //allocate a Bar object with operator 'new' 
    //that is automatically finalized
    //since it inherits from Object
    Bar *obj3 = new Bar;
}
