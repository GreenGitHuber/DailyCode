#include<iostream>
using namespace std;
#include<vector>

int main()
{
    std::vector<int> v;
    int total =0;
    int val = 5;
    for(int i=0;i<5;i++) v.push_back(i);
    std::for_each(begin(v),end(v),[&total](int x)
    {
        total+=x;
    });
// error: expected expression
// std::for_each(begin(v),end(v),[total](int x)
//                                   ^
// 1 error generated.

    return 0;
}