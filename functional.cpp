#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

bool check(int x)
{
    return x%2 == 0;
};

class Functor
{
public:
    bool operator()(int x){return x%2 == 0;}
} f1;

int run(vector<int> vec, function<bool(int)> check)
{
    int count = 0;
    for (auto i : vec){
        if (check(i))
            count++;
    }
    return count;
}


int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};

    auto l = [](int x){return x%2 == 0;};
    int count = count_if(vec.begin(),vec.end(),l);

    cout << "Count: " << count << endl;    

    cout << "Count Lambda: " << run(vec,l) << endl;
    cout << "Count Functor: " << run(vec,f1) << endl;
    cout << "Count Function: " << run(vec,check) << endl;
}
