#include <iostream>
using namespace std;

class A{};
class Y{};
class X{};
class Z: public Y, public X, public virtual A {};
class B: public virtual A {};
class C: public B{};
class D: public Z, public C {};


int main()
{
    
    return 0;
}