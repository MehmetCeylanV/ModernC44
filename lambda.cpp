#include <iostream>

using namespace std;

class A 
{
private:
    int a{0};
    int b{1};
public:
    void something()
    {
        [this](){cout << "Class A: "<< a << b << endl;}();
    }
};


void test(void (*func)(string))
{
    func("Mehmet");
}

int main()
{
    //without return
    auto l = [](string name){cout << "Hello "<< name << "\n" << endl;};

    //with return
    auto sum = [](double a, double b) -> double {
        return a + b;
    };

    cout << "Sum: " << sum(1,2) << endl;

    //function pointer
    test(l);

    int a = 0;
    int b = 1;
    int c = 2;

    //Capture a and b by value
    auto f1 = [a,b](){cout << a << b << endl;};

    //Capture all local variables by value
    auto f2 = [=](){cout << a << b << c << endl;};

    //Default capture all local variables by value but c by reference
    auto f3 = [=,&c]{cout << a << b << c << endl; c = 3;};

    //Default capture all variables by reference
    auto f4 = [&]{a = 4; b = 4; c = 4;};

    f1();
    f2();
    f3();
    cout << a << b << c << endl;
    f4();
    cout << a << b << c << endl;

    A an_a;
    an_a.something();

    return 0;
}
