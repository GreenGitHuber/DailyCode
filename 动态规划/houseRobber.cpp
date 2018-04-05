#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

/*
例子：
Given [3, 8, 4], return 8.

题目要求从n个房屋中找出一些房屋取走里面财产，找到财产最大的总值，限制条件是不能有相邻的房屋同时被偷盗。
*/
/*
设money[i]表示为抢劫第i个房子可以获得的最大的财富
状态转移方程可以如下：
money[i] = max(money[i-1], money[i-2] + A[i])
*/
int houserobber(vector<int> house)
{
    int len = house.size();
    if(len==0)
        return 0;
    if(len==1)
        return house[0];
    // if(len==2)
    //     return house[0]>house[1]?house[0]:house[1];
    // else
    // {
    //     int money[100]={0};
    //     money[0] = house[0];
    //     money[1] =max(house[0],house[1]);
    //     for(int i= 2;i<len;++i)
    //     {
    //         money[i] = max(money[i-2]+house[i],money[i-1]);
    //     }
    //     return money[len-1];
    // }
    // 辅助数组
    long long money[3] = {0};
    money[0] = 0;
    money[1] = A[0];
    
    // 动态规划步骤
    for (int i = 2; i <= n; i++)
    {
        money[2] = max(A[i-1] + money[0], money[1]);
        money[0] = money[1];
        money[1] = money[2];
    }
    
    return money[2];
    
}

int main()
{
    int len;
    cin>>len;
    vector<int> house;
    for(int i = 0;i<len;++i)
    {
        int a;
        cin>>a;
        house.push_back(a);
    }
    int ans = houserobber(house);
    cout<<ans;
}