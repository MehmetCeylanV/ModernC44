#include <iostream>

using namespace std;

class Parent {
    int number{5};
    string name{"hello"};

public:
    //delegate 
    Parent() : Parent("hello 2"){
        cout << "Parent constructor" << endl;
    }

    Parent(string name){
        this->name = name;
        cout << "String Parent contructor" << endl;
    }
};

class Child : public Parent{
public:
    Child() = default;
};

int main(){
    Child c;
}
