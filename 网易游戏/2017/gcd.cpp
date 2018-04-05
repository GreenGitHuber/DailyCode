#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
gcd(a, b) = gcd(b, a mod b)（前提条件是假设a > b 且 r = a mod b, r 不为0
*/
int gcd(int a,int b)
{
    int small = a>b ? b:a;
    int big = a+b-small;
    int m = big % small;
    if(m==0)
    {
        return small;
    }
    else
    {
        return gcd(small,m);
    }

}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=gcd(a,b);
    cout<<ans;
    return 0;
}

/*在已经算出整数a、b的最大公约数的基础上，我们可以通过下面的公式来求出它们的最小公倍数

lcm(a, b) = (a * b)/gcd(a, b)
*/