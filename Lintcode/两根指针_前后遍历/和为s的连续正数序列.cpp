#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        assert(sum>2);
        // if(sum<3)
        //     return NULL;
        vector<vector<int> > ans;
        int small = 1;
        int big = 2;
        int tem_sum = small+big;
        while(small<(sum+1)/2)
        {
            if(tem_sum<sum)
            {
                big++;
                tem_sum +=big;
            }
            else if(tem_sum>sum)
            {
                tem_sum -=small;
                small++;
            }
            else
            {
                vector<int> item;
                for(int i =small;i<=big;++i)
                {
                    item.push_back(i);
                }
                ans.push_back(item);
                //下面两句话第一次写的时候就忘记写了，造成了死循环！！！
                tem_sum -=small;
                small++;

            }
        }
        return ans;
    }
};

int main()
{
    int sum;
    cin>>sum;
    Solution s;
    vector<vector<int> > ans;
    ans = s.FindContinuousSequence(sum);
    return 0;

}