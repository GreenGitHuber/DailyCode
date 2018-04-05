#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

int sum(int n)
{
    int sum =0;
    for (int i =1;i<=n;++i)
    {
        if(i<10)
        {
           sum+=i; 
        }
        else
        {
            int tem = i;
            while(tem!=0)
            {
                int end = tem%10;
                cout<<end;
                sum+=end;
                tem = tem/10;
            }
        }
        
    }
    return sum;
}

int count(int begin,int end)
{
    int count =0;
    for(int i = begin;i<=end;++i)
    {
        int tem_sum = sum(i);
        if(tem_sum % 3 ==0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int begin,end;
    cin>>begin>>end;
    int ans = count(begin,end);
    
    cout<<ans;
    return 0;

}