#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Aclass{
private:
    const int SIZE = 10;
    int* arr{nullptr};

public:
    Aclass(){
        cout << "Default Constructor" << endl;
        arr = new int[SIZE]{};
    }

    Aclass(int i){
        cout << "Parametarized Constructor" << endl;
        arr = new int[SIZE]{};
        for(int i = 0; i < SIZE; i++){
            arr[i] = 5 * i;
        }
    }

    Aclass(const Aclass& other){
        cout << "Copy Constructor" << endl;
        memcpy(arr,other.arr,SIZE*sizeof(int));
    }

    Aclass (Aclass&& other){
        cout << "Move Constructor" << endl;
        arr = other.arr;
        other.arr = nullptr;
    }

    Aclass& operator=(const Aclass& other){
        cout << "Assigment Operator" << endl;
        arr = new int[SIZE];
        memcpy(arr,other.arr,SIZE*sizeof(int));
        return *this;
    }

    Aclass& operator=(Aclass&& other){
        cout << "Move Assigment Operator" << endl;
        delete[] arr;
        arr = other.arr;
        other.arr = nullptr;
        return *this;
    }

    ~Aclass(){
        cout << "Destructor" << endl;
        delete[] arr;
    }

    friend ostream& operator<<(ostream& out, const Aclass& test);
};

ostream& operator<<(ostream& out, const Aclass& test){
    cout << "Operator << Aclass" << endl;
    return out;
}

Aclass getClass(){
    return Aclass();
}

void test(const Aclass& value){
    cout << "Lvalue function" << endl;
}

void test(Aclass&& value){
    cout << "Rvalue function" << endl;
}

int main(){

    Aclass a = getClass();

    cout << a;

    //r_reference
    //Aclass&& r_a = getClass();

    test(a);
    test(getClass());
    test(Aclass());

    Aclass m;
    m = getClass();

    vector<Aclass> vec;
    vec.push_back(Aclass());

    return 0; 
}
