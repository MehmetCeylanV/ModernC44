#include <iostream>
#include <memory>

using namespace std;

class Aclass{
public:
    Aclass(){
        cout << "Aclass constructor" << endl;
    }

    void doSomething(){
        cout << "Aclass do something" << endl;
    }

    ~Aclass(){
        cout << "Aclass destructor" << endl;
    }
};

class Box{
    unique_ptr<Aclass[]> in;

public:
    Box() : in(new Aclass[2]){
    
    }
};

int main(){
    unique_ptr<Aclass> a(new Aclass());
    Box b;

    cout << "Started" << endl;

    shared_ptr<Aclass> s1(nullptr);
    {
        shared_ptr<Aclass> s2 = make_shared<Aclass>();
    
        //wait end of main scope to destroy s2
        //s1 = s2;
    }

    cout << "Finished" << endl;
}
