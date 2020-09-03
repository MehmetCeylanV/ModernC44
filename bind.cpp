#include <iostream>
#include <functional>

using namespace std;

class Aclass{
public:
    int sum(int a, int b, int c){
        cout << "Aclass Sum: " << a << " " << b << " " << c << endl;
        return a + b + c;
    }
};

int sum(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
    return a + b + c;
}

void run(function<int(int,int)> f){
    f(20,30);
}

int main(){
    auto b_sum = bind(sum, placeholders::_2, 100, placeholders::_1);

    cout << b_sum(10,20) << endl;

    run(b_sum);

    Aclass a;
    auto b_m_sum = bind(&Aclass::sum,a,placeholders::_2, 100, placeholders::_1);

    cout << b_m_sum(30,40) << endl;
}
