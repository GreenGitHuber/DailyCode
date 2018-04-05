#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>



#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        if(len==0)
            return 0;
        if(m==0)
            return 0;
        // vector<vector<int> >dp(len+1,vector<int>(m+1,0));
        //空间复杂度o(len*m)
        // for(int i=1;i<=len;++i)
        // {
        //     for(int j = 0;j<=m;++j)
        //     {
        //         dp[i][j]=dp[i-1][j];
        //         if(j>=A[i])
        //             dp[i][j] = max(dp[i][j],dp[i-1][j-A[i]]+V[i]);
        //     }
        // }
        //使用滚动数组来优化
        vector<vector<int> >dp(2,vector<int>(m+1,0));
        for(int i=1;i<=len;++i)
        {
            for(int j = 0;j<=m;++j)
            {
                int index = i&1;
                dp[index][j]=dp[index ^ 1][j];
                if(j>=A[i])
                    dp[index][j] = max(dp[index][j],dp[index^1][j-A[i]]+V[i]);
            }
        }
        
        return dp[len&1][m];


    }
};

int main()
{
    Solution s;
    int a[]={77,22,29,50,99};
    std::vector<int> A(a,a+5);
    int b[]={92,22,87,46,90};
    std::vector<int> V(b,b+5);

    int ans=s.backPackII(100,A,V);
    cout<<ans;
    return 0;
}
