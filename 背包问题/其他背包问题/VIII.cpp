/*给出一些价值不同的硬币以及它们的数量，
求这些硬币能组合成价值在1 ~ n之间的有多少。
样例
Given:
n = 10
value = [1,2,4]
amount = [2,1,1]

Return: 8
They can combine all the values in 1 ~ 8*/
#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
        // write your code here
        // int len = value.size();
        // std::vector<int> dp(n+1,0);
        // // dp[0]=1;//这一行不能要！！！！！！！！弄明白为什么
        // for(int i =0;i<len;++i)
        // {
        //     for(int j = 0;j<amount[i];++j)
        //     {
        //         for(int k = n;k>=value[i];--k)
        //         {
        //             dp[k]=max(dp[k],dp[k-value[i]]+value[i]);
        //         }
        //     }
        // }
        // int count=0;
        // for(int i=1;i<=n;++i)
        // {
        //     if(dp[i]==i)
        //         count++;
        // }
        // return count;
        /*👆上面的代码超时了！！！*/
        // 👇下面的这段代码又很难懂
        vector<bool> dp(n+1,false);

        int len = value.size();
        int res =0;
        dp[0]=true;

        for(int i = 0;i<len;++i)
        {
            vector<int> cnt(n + 1,0);
            for(int j=value[i];j<=n;++j)
            {
                if(!dp[j]&&dp[j-value[i]]&&cnt[j - value[i]] < amount[i])
                {
                    cnt[j] = cnt[j - value[i]] + 1;
                    res++;
                    dp[j] = true;
                }
            }
        }
        return res;
    }
};
int main()
{
    int n;
    cin>>n;
    int a[]={1,2,4};
    int b[]={2,1,1};
    vector<int> value(a,a+3);
    vector<int> amount(b,b+3);
    Solution s;
    int ans = s.backPackVIII(n,value,amount);
    cout<<ans;
}




