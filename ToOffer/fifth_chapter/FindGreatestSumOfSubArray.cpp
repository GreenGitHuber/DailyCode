#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    int sum=-1000;//表示很小的一个数
    int cur_sum =0;
    for(int i = 0;i<array.size();++i)
    {
        if(cur_sum<=0)
        {
            cur_sum=array[i];//舍弃之前的数字
        }
        else
        {
            cur_sum+=array[i];
        }
        if(cur_sum>sum)
        {
            sum=cur_sum;
        }
    }
    return sum;
    }
};

int main()
{
    int i;
    cin>>i;
    std::vector<int> array(i);
    for(int j=0;j<i;j++)
    {
        int a;
        cin>>a;
        array.push_back(a);
    }
    Solution s;
    int res = s.FindGreatestSumOfSubArray(array);
    cout<<res;
    return 0;

}