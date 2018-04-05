#include<iostream>
using namespace std;

class Solution
{
public:
    void swap(int &a,int &b)
    {
        int tem = a;
        a=b;
        b=tem;
    }
    void maopao(int nums[],size_t n)
    {
        int length = n; 
        bool change ;
        for (int j = 1;j<length;j++)
        {
            change = false;
            for(int i=0;i<length-j;i++)
            {
                if(nums[i]>nums[i+1])
                {
                    swap(nums[i],nums[i+1]);
                    change = true;
                }

            }
            if(!change)
                break;
        }
       
    }
};

int main()
{
    int nums[5]={7,8,2,4,3};
    Solution s;
    s.maopao(nums,5);
    for(int i = 0;i<5;i++)
    {
        cout<<nums[i]<<' ';
    }
    system("pause");
}
