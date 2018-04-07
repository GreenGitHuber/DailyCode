/*0-1背包问题！！
这一问题的状态转移方程是：
for(j:W->0)
    f[j]=max(f[j],f[j-w[i]]+v[i])
f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);*/


#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
/*T表示有多少组用例，
接下去的三行分别表示：
N W（物品的种类和背包的容量）
背包的价值 1 4 5 2 7
物品的重量 5 4 7 2 6
*/
class Solution {
public:
    // void ZeroOneKnapsack(vector<int> &d, vector<int> &v, vector<int> &w, int i, int W)
    // {
    //     for (int j = W; j >= w[i]; --j)
    //     {
    //         d[j] = max(d[j], d[j - w[i]] + v[i]);
    //     }
    // }

    int dp(int W, int N, vector<int> &v, vector<int> &w)
    {//W表示背包的重量
        vector<int> d(W + 1, 0);
        for (int i = 0; i < N; ++i)
        {
            for (int j = W; j >= w[i]; --j)
            {
                d[j] = max(d[j], d[j - w[i]] + v[i]);
            }
            // ZeroOneKnapsack(d,v,w,i,W);
        }
        return d[W];
    }

};


int main(int argc, char const *argv[])
{
    int  T;
    cin >> T;
    Solution s;
    while (T)
    {
        int N, W;
        cin >> N >> W;
        std::vector<int> v;
        std::vector<int> w;
        int i = N;
        int j = N;
        while (i)
        {
            int a;
            cin >> a;
            v.push_back(a);
            i--;
        }
        while (j)
        {
            int a;
            cin >> a;
            w.push_back(a);
            j--;
        }
        int ans = s.dp(W, N, v, w);
        cout << ans << endl;
        T--;
    }
    system("pause");
    return 0;
}