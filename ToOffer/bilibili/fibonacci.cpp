#include<iostream>
using namespace std;

int fibonacci(int n)
{
    int f[n];
    int f[0]=0；
    int f[1]=1;
    for(int i=2;i<n;++i)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1];

}