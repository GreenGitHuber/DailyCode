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
     * @param A an integer matrix
     * @return  an integer
     */
    int n, m, maxL;
    int lics[1000][1000];
    int vis[1000][1000];
    int dir[4][2] = {{0, 1}, {1, 0}, {0,-1}, {-1,0}};
    vector<int> ans,res;
int dfs(vector<vector<int> >&A, int x, int y,vector<int>& ans){
        int maxLics = 0;
        vis[x][y] = 1;
        ans.push_back( A[x][y]);
        for(int i=0; i<4; ++i)
        {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
            if(A[x][y] <= A[xx][yy]) continue;
            // ans.push_back( A[xx][yy]);
            if(!vis[xx][yy])
            {
                
                maxLics = max(maxLics, dfs(A, xx, yy,ans));
                ans.pop_back();
            }
            else
            {
                ans.push_back( A[xx][yy]);
                maxLics = max(maxLics, lics[xx][yy]);
                // ans.pop_back();
            }
        }
        // ans.pop_back();
        lics[x][y] = maxLics+1;
        if(maxL < lics[x][y])
        {
            res.clear();
            res = ans;
            maxL = lics[x][y];
        }
        // ans.pop_back();

        return lics[x][y];
    } 

vector < int > mcs(vector < vector < int > > graph) {
        n = graph.size();
        if(n == 0) return ans;
        m = graph[0].size();
       // for( int i = 0; i < 1000; i++ )
       //  for( int j = 0; j < 1000; j++ )
       //      lics[i][j]=INT_MIN;

       //  for(int  i = 0; i < 1000; i++ )        //输入数据
       //      for(int j = 0; j < 1000; j++ )
       //          vis[i][j]=INT_MIN;
        memset(lics, 0, sizeof(lics));
        memset(vis, 0, sizeof(vis));
        maxL = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(!vis[i][j])
                {
                    ans.clear();
                    dfs(graph, i, j,ans);
                }
        return res;

}

};
/******************************结束写代码******************************/


int main() {
    vector < int > res;

    int _graph_rows = 0;
    int _graph_cols = 0;
    cin >> _graph_rows >> _graph_cols;
    vector< vector < int > > _graph(_graph_rows);
    for(int _graph_i=0; _graph_i<_graph_rows; _graph_i++) {
        for(int _graph_j=0; _graph_j<_graph_cols; _graph_j++) {
            int _graph_tmp;
            cin >> _graph_tmp;
            _graph[_graph_i].push_back(_graph_tmp);
        }
    }
    Solution s;

    res = s.mcs(_graph);
    for(int res_i=0; res_i <res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }
    
    return 0;

}






std::vector<std::vector<std::vector<int> > > v;
