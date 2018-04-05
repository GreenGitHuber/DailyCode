/***
**给一个01矩阵，求不同的岛屿的个数。

**0代表海，1代表岛，如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
**/
class Solution {
public:
    /*
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int count=0;
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        if(grid.empty()) return 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j])
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<bool>> &grid,int i,int j)
       {
           int row = grid.size();
            int col = grid[0].size();
           if(i>=row||j>=col)
           {
               return;
           }
           if(grid[i][j]==0) return;
           else
            grid[i][j]=0;
           if(j<col)
           {
               dfs(grid,i,j+1);
           }
           if(i<row)
           {
               dfs(grid,i+1,j);
           }
           if(i>0)
           {
               dfs(grid,i-1,j);
           }
           if(j>0)
           {
               dfs(grid,i,j-1);
           }
       }
};