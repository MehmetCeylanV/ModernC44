#include <iostream>

using namespace std;

class Parent{
public:
    virtual void something(){

    }
};

class SubClass: public Parent{

};

class SubClass2: public Parent{

};

int main(){
    Parent* p = new Parent();
    SubClass* s = new SubClass();
    SubClass2* s2 = new SubClass2();

    //Good boy
    SubClass* x = dynamic_cast<SubClass*>(p);

    if (x == nullptr){
        cout << "Invalid Cast" << endl;
    }
    else{
        cout << "Succesfull Cast" << endl;
    }

    //Maybe
    SubClass* y = static_cast<SubClass*>(p);

    if (y == nullptr){
        cout << "static_cast Invalid Cast" << endl;
    }
    else{
        cout << "static_cast Succesfull Cast" << endl;
    }

    //Do not do that
    SubClass2* z = reinterpret_cast<SubClass2*>(s2);

    if (z == nullptr){
        cout << "reinterpret_cast Invalid Cast" << endl;
    }
    else{
        cout << "reinterpret_cast Succesfull Cast" << endl;
    }
}
