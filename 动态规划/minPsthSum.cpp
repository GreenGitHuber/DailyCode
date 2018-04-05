#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class solution
{
public:
    int minPathSum(std::vector<std::vector<int> > & grid)
    {
        if(grid.size()==0)
        {
            return 0;
        }
        std::vector<std::vector<int> > dp(grid.size(),std::vector<int>(grid[0].size(),0));
        //初始化dp数组
        dp[0][0]=grid[0][0]
        for(int j = 1;j<grid[0].size();++j)
        {//求dp数组的第一行
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        for(int i=1 ;i<grid.size();++i)
        {//求dp数组的第一列
            dp[i][0]=grid[i][0]+dp[i-1][0];
            for(int j = 1;j<grid[0].size();++j)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];

    }
};
