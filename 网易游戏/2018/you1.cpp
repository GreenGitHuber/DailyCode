#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void print_tri(int n)
{
    for(int i =0 ;i<n-1;++i)
    {
        int len = n+i;
        for(int j =0;j<len;++j)
        {
            if(j==len-1 || j==len-i*2-1)
            {
                cout<<'*';
            }
            else
                cout<<'.';
        }
        cout<<endl;
    }
    for(int i=0;i<2*n-2;++i)
    {
        cout<<"*";
    }
}

int main()
{
    int n;
    cin>>n;
    print_tri(n);
    return 0;
}