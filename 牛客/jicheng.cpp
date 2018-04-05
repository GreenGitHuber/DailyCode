#include<iostream>
using namespace std;

class Base
{
public:
    int c;
    Base():a(10),b(3),c(12){};
    void GetA()
    {
        cout<<a;    
    }
private:
    int a;
    int b;
};

class Derive:public Base
{
public:
    // void GetprivateA()
    // {//编译不通过，因为a是Base的私有成员，所以继承类不能访问
    //     cout<<a;
    // }
    void GetC()
    {
        cout<<c;
    }
    
};
class Derive2:private Base
{
public:
    // void GetprivateA()
    // {//编译不通过，因为a是Base的私有成员，所以继承类不能访问
    //     cout<<a;
    // }
    void GetC()
    {
        cout<<c;
    }
    
};


int main()
{
    Base a;
    cout<<a.c<<endl;
    a.GetA();
    Derive d;
    cout<<d.c<<endl;
    d.GetC();
    Derive2 d2;
    cout<<d2.c<<endl;
    // d.GetprivateA();    
    return 0;
}