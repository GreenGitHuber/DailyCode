#include <iostream>
#include <vector>
using namespace std;
/*
给出 n 个物品, 以及一个数组, nums[i]代表第i个物品的大小, 
保证大小均为正数并且没有重复, 正整数 target 表示背包的大小, 找到能填满背包的方案数。
每一个物品可以使用无数次

给出候选物品集合 [2,3,6,7] 和 target 7,
返回 2；
7
2 2 3
*/
class Solution {
public:
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int len = nums.size();
        vector<int>dp(target+1,0);
        //dp[0]=0;
        dp[0]=1;
        for(int i = 0;i<len;++i)
        {
            for(int j = nums[i];j<=target;++j)
            {
                // if(nums[i]==j)
                // {
                //     dp[j]++;
                // }
                // else if(nums[i]<j)
                // {
                //     dp[j]+=dp[j-nums[i]];
                // }
                dp[j]+=dp[j-nums[i]];
            }
            
        }
        return dp[target];
    }
};

int main()
{
    int target;
    cin>>target;
    int a;
    vector<int> nums;
    while(cin>>a)
    {
        nums.push_back(a);
    }
    Solution s;
    int ans = s.backPackIV(nums,target);
    cout<<ans;
    return 0;
}