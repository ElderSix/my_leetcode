#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> x;
    //reserve 函数分配出来的内存空间，只是表示vector可以利用这部分内存，但vector不能有效地访问这些内存空间，
    //访问的时候就会出现越界现象，导致程序崩溃
    x.reserve(10);
    fill_n(x.begin(), 0, 42);
    for(auto t = x.begin(); t != x.end(); t++){
        cout<<*t;
    }
    cout<<endl;
    cout<<x.size()<<endl;
}