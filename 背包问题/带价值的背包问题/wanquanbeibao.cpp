/*完全背包问题：
就是说每个物品有无限种可能性；
这一问题的状态转移方程是：
for(j:0->W)
    f[j]=max(f[j],f[j-w[i]]+v[i])
f[i][j] = max(f[i-1][j],f[i][j-w[i]]+v[i]);
*/

#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

/*
输入样例：
1
10 110 //E F ；E表示存钱罐为空的重量，F表示装满以后的重量
2      //表示硬币的种类
1 1     //接下去的几行是硬币的面值和重量
30 50
*/

class Solution {
public:
    int dp(int W, int N, vector<int> &v, vector<int> &w)
    {//W表示背包的重量
        vector<int> d(W + 1, 1000000);
        d[0] =0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = w[i]; j <= W; ++j)
            {
                d[j] = min(d[j], d[j - w[i]] + v[i]);
            }
            // ZeroOneKnapsack(d,v,w,i,W);
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
        int e ,f;
        cin>>e>>f;
        int n;//货币的种类
        cin>>n;
        vector<int> v;
        vector<int> w;
        int tem = n;//这里一定要这样做不然第55行就会出错！！！
        while(tem--)
        {
            int a,b;
            cin>>a>>b;
            v.push_back(a);
            w.push_back(b);
        }
        int ans = s.dp(f-e,n,v,w);
        cout<<ans<<endl;
    }
}
