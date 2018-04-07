/*多重背包问题：
第i件物品有num[i]个，*/
/*
1       //T：有T组用例
8 2     //W，N：W表示经费，N表示大米的种类
2 100 4 //接下去的N行表示 价格 重量 数量
4 100 2

*/

#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
// ZeroOneKnapsack(vector<int>& d,int i,int c)
// {
//     for(int j = W;j>=w[i];--j)
//     {
//         d[j] = max(d[j],d[j-w[i]*c]+c*v[j]);
//     }
// }

class Solution {
public:
    int dp(int W, int N, vector<int> &v, vector<int> &w,vector<int>&nums)
    {//W表示背包的重量
        vector<int> d(W + 1, 0);
        for (int i = 0; i < N; ++i)
        {
            for(int k =0;k<nums[i];++k)
            {
                //这里接下去是0-1背包问题。
                for (int j = W; j >=w[i]; --j)
                {
                    d[j] = max(d[j], d[j - w[i]] + v[i]);
                }
            }
        }
        return d[W];
    }

};

int main()
{
    int t;
    cin>>t;
    Solution s;
    while(t--)
    {
        int W ,N;
        cin>>W>>N;
        vector<int> v;
        vector<int> w;
        vector<int> nums;
        int tem = N;//这里一定要这样做不然第55行就会出错！！！
        while(tem--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            w.push_back(a);
            v.push_back(b);
            nums.push_back(c);
        }
        int ans = s.dp(W,N,v,w,nums);
        cout<<ans<<endl;
    }
}
