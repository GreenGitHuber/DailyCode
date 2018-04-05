#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void cutRodBottomUp(std::vector<int> const &p,int n)
{
    int r[11]={0};
    if(n==1)
    {
        r[1]= p[0];
    }
    vector<int> s(n+1, 0); // 记录每个长度最大收益时的切割位置
    
    for(int i = 2;i<=10;++i)
    {
        int max_val = INT_MIN;
        for(int j =1;j<=i;++j)
        {
            int tem = r[i - j]+p[j-1];
            if(tem>max_val)
            {
                max_val=tem;
                s[i] =j;// 记录每个长度最大收益时的切割位置
            }
        }
        r[i]=max_val;
    }
    cout << r[n] << endl;
    // 输出结果
    while (n > 0)
    {
        cout << s[n] << '\t';
        n = n - s[n];
    }
    cout << endl;
}

int main()
{
    int c[10]={1,5,8,9,10,17,17,20,24,30};
    std::vector<int> p(c,c+10);
    int n ;
    cin>>n;
    cutRodBottomUp(p,n);
    return 0;
    // cout<<ans;
}