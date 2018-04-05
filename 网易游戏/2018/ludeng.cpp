#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int  fix(string &road,int index,int len)
{
    if(len <0)
        return 0;
    if(index>=len)
        return 0;
    else 
    {
        if(road[index]=='X')
            return fix(road,index+1,len);
        else
        {
            return 1+fix(road,index+3,len);
        }
    }
}



int main()
{
    int case_num;
    cin>>case_num;
    for(int i=0;i<case_num;++i)
    {
        int len;
        cin>>len;
        string road;
        cin>>road;
        int ans = fix(road,0,len);
        cout<<ans<<endl;
    }
}