#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
我们令c[i][j]表示Xi和Yj的最长公共子序列的长度，那么可以得到以下关系：
*/
int LCS(string &X,string &Y)
{
    int len1 = X.length();
    int len2 = Y.length();
    std::vector<std::vector<int> > c(len1+1,vector<int>(len2+1,0));


    for(int i =0;i<len1; ++i)
    {
        c[i][0] = 0;
    }

    for(int j =0;j<len2; ++j)
    {
        c[0][j] = 0;
    }
    //动态规划
    for(int i = 1;i<=len1;++i)
    {
        for(int j=1;j<=len2;++j)
        {
            if(X[i-1]==Y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }

    return c[len1][len2];
}

int main()
{
    string x,y;
    cin>>x>>y;
    int ans= LCS(x,y);
    cout<<ans;
    return 0;
}


