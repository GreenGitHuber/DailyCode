#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class solution
{
public:
    int coinChange(std::vector<int> coins,int amount)
    {
        std::vector<int> dp;
        for(int i=0;i<=amount;++i)
        {
            dp.push_back(-1);
        }
        dp[0]=0;
        for(int i =1;i<=amount;++i)
        {
            int tem = INT_MAX;
            for(int j =0;j<coins.size();++j)
            {
                if(coins[j]==i)
                {
                    tem =1;
                    break;
                }
                if(i-coins[j]>=0)
                {
                    if(dp[i-coins[j]]+1<tem)
                        tem = dp[i-coins[j]]+1;
                }
            }
            dp[i]=tem;
        }
        return dp[amount];

}};
int main()
{
    int coins[]={1,2,5,7,10};
    std::vector<int> v(coins,coins+5);
    int amount;
    cin>>amount;
    solution s;
    int ans = s.coinChange(v,amount);
    cout<<ans;




}