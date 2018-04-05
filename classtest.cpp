#include<iostream>
using namespace std;

class A
{
public:
    void fun_c()
    {
        int i=1;
        cout<<"func_c"<<endl;
    }
    A()
    {
        cout<<"construct function"<<endl;
    }
    static void fun_a()
    {
        cout<<"func_a"<<endl;
    }
};
int main()
{
    A a;
}