#include<vector>
#include<iostream>
#include<string>
#include<set>
using namespace std;
/* 全排列的代码，全排列的意思是abc-》
abc
acb
bac
bca
cba
cab
*/
// class Solution
// {
// public:
//     void swap(int i,int j,string &nums)
//     {
//         char tem = nums[i];
//         nums[i]=nums[j];
//         nums[j]=tem;
//     }
//     void Permutation(string nums)
//     {
//         // if(nums==NULL)
//         //     return;
//         int len = nums.length();
//         PermutationCore(nums,0,len);
//     }

//     void PermutationCore(string &nums,int index,int len)
//     {
//         if(index==len)
//             cout<<nums<<endl;
//         else
//         {
//             for(int i = index;i<len;i++)
//             {
//                 swap(index,i,nums);
//                 PermutationCore(nums,index+1,len);
//                 swap(index,i,nums);
//             }
//         }
//     }
    
// };

//上面是不带重复字母的，如果是带有重复字母的该怎么呢？

class Solution
{
public:
    void swap(int i,int j,string &nums)
    {
        char tem = nums[i];
        nums[i]=nums[j];
        nums[j]=tem;
    }
    bool ok(string &nums,int i, int j)//判断i到当前j是否有相等的，如果有说明之前已经对这
    {  
        if( i < j)
        {  
            for(int k = i; k < j; k++)
            {  
                if(nums[k] == nums[j])  
                    return false;  
            }  
        }    
        return true;  
    }  
    void Permutation(string nums)
    {
        // if(nums==NULL)
        //     return;
        int len = nums.length();
        PermutationCore(nums,0,len);
    }

    void PermutationCore(string &nums,int index,int len)
    {
        if(index==len)
            cout<<nums<<endl;
        else
        {
            for(int i = index;i<len;i++)
            {
                if(ok(nums,index,i))
                {
                    swap(index,i,nums);
                    PermutationCore(nums,index+1,len);
                    swap(index,i,nums);
                }
                
            }
        }
    }
};

int main()
{
    Solution s;
    string str;
    cin>>str;
    s.Permutation(str);
    return 0;

}