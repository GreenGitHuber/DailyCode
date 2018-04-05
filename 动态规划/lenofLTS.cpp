#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class solution
{
public:
    //方法一，使用动态规划的思想
    // int lenofLIS(std::vector<int> &nums)
    // {
    //     int LIS = INT_MIN;
    //     int len = nums.size();
    //     std::vector<int> dp(len+1,0);
    //     dp[0]=0;
    //     for(int i =1;i<=len;++i)
    //     {
    //         int tem = INT_MIN;
    //         for(int j=0;j<i;++j)
    //         {
    //             if(nums[j]<nums[i]&&dp[j]>tem)
    //             {
    //                 tem = dp[j];
    //             }
    //         }
    //         dp[i]=tem+1;
    //         if(dp[i]>LIS)
    //         {
    //             LIS=dp[i];
    //         }
    //     }
    //     return LIS;

    // }

    //方法2:使用栈的思想 n^2
    int lenofLIS(std::vector<int> &nums)
    {
        std::vector<int> stack;
        stack.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            int tem = nums[i];
            if(tem >stack.back())//vector的最后一个元素可以利用back（）这个函数
                stack.push_back(tem);
            else
            {
                for(int j = 0;j<stack.size();++j)
                {
                    if(tem<=stack[j])//这里是<=，这样得到的结果是严格上升的；如果改为<,那么是不严格的上升
                    {
                        stack[j]=tem;
                        break;
                    }
                }

            }
            
        }
        return stack.size();
    }
};

int main()
{
    int nums[]={1,3,2,3,1,4};
    std::vector<int> v(nums,nums+6);
    solution s;
    int ans = s.lenofLIS(v);
    cout<<ans;

}