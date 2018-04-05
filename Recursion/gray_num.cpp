#include <math.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个二进制的差异。

给定一个非负整数 n ，表示该代码中所有二进制的总数，请找出其格雷编码顺序。一个格雷编码顺序必须以 0 开始，并覆盖所有的 2n 个整数。*/
class Solution {
public:
    /**
     * @param n: a number
     * @return: Gray code
     */
    vector<int>result;
    // bool end=false;
    set<int> set_tem;
    int count=1;
    
    void fanzhuan(int id,int n)
     {
        result.push_back(id);
        set_tem.insert(id);
        // if(count>pow(2,n))
        // return;
        for(int i=0;i<n;i++)
        {
            int tem = id^(1<<i);
            if(set_tem.find(tem)!=set_tem.end())
            {
                continue;
            }
            else
            {
                id = tem;
                set_tem.insert(id);
                
                count++;
                fanzhuan(id,n);
            }
            
        }
        return;
     }
    vector<int> grayCode(int n) {
        // write your code here
        fanzhuan(0,n);
        return result;
        
    }
};
int main()
{
    int a;
    cin>>a;
    Solution s;
    int num = pow(2,a);
    vector<int >result(num);
    result = s.grayCode(a);
    for(int i=0;i<num;i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;


}