/*两数之和

描述 给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。 
你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。
注意这里下标的范围是 1 到 n，不是以 0 开头。
样例 给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vec(std::vector<int> v)
{
    cout<<"The vector is：";
    std::vector<int> ::iterator it = v.begin();
    for(;it!=v.end();++it)
    {
        cout<<*it <<" ";
    }
}
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    sort(nums.begin(),nums.end());
    print_vec(nums);
    int len = nums.size();
    int left =0;
    int right = len-1;
    while(left<right)
    {
        int a = nums[left];
        int b = nums[right];
        cout<<a<<" "<<b<<endl;
        if(a+b==target)
        {
            cout<<"ok";
            ans.push_back(left+1);
            ans.push_back(right+1);
            --right;
            ++left;
        }
        else if(a+b>target)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }
    return ans;
}


int main()
{
    int a[] = {4,6,10,3,5,4,9};
    std::vector<int> v(a,a+7);
    print_vec(v);
    int target;
    cin>>target;
    std::vector<int> ans = twoSum(v,target);
    print_vec(ans);
    return 0;
}