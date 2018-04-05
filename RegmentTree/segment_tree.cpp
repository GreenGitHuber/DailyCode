#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//
//线段树数组value存储的是区间和sum
//nums代表的是原始数组
//pos代表当前线段（结点）在线段树数组（value）中的下标
//当前线段的左端点left，右断点right
void build_segment_tree(std::vector<int> &value,
    std::vector<int> &nums,
    int pos,int left,int right)
    {
        if(left==right)
        {//到了叶子结点
            value[pos] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        build_segment_tree(value,nums,pos*2+1,left,mid);
        build_segment_tree(value,nums,(pos+1)*2,mid+1,right);

        value[pos]=value[pos*2+1]+value[pos*2+2];
    }
//线段树求和
int sum_range_segment_tree(std::vector<int> &value,
    int pos,int left,int right,
    int qleft,int qright)
{
    if(qleft>right||qright<left)//不相交，不在区间内
        return 0;
    if(qleft<=left&&qright>=right)//区间被查询区间覆盖，直接返回
        return value[pos];
    //左子树加右子树
    int mid = (left+right)/2;
    return sum_range_segment_tree(value,pos*2+1,left,mid,qleft,qright)+
    sum_range_segment_tree(value,pos*2+2,mid+1,right,qleft,qright);
}
//线段树的更新
void update_segment_tree(std::vector<int>& value,
    int pos,int left,int right,
    int index,int new_value)
{
    if(left==right&&left==index)
    {
        value[pos]=new_value;
        return;
    }
    int mid = (left+right)/2;
    if(index<=mid)
    {
        update_segment_tree(value,pos*2+1,left,mid,index,new_value);
    }
    else
        update_segment_tree(value,pos*2+2,mid+1,right,index,new_value);
    value[pos]=value[pos*2+1]+value[pos*2+2];
}

class NumArray
{
private:
    std::vector<int> value;
    int end_right;
public:
    NumArray(std::vector<int> nums)
    {
    int n=nums.size()*4;
    for(int i=0;i<n;i++)
     {
        value.push_back(0);
     }
     end_right=nums.size()-1;
     build_segment_tree(value,nums,0,0,end_right);       
    }
    void update(int i,int val)
    {
        update_segment_tree(value,0,0,end_right,i,val);
    }
    int sumRange(int i,int j)
    {
        return sum_range_segment_tree(value,0,0,end_right,i,j);
    }
    
};

int main()
{
     std::vector<int> nums;
     for(int i=0;i<6;i++)
     {
        nums.push_back(i*2+1);
     }
     // std::vector<int> value;
     //  for(int i=0;i<24;i++)
     // {
     //    value.push_back(0);
     // }
     // build_segment_tree(value,nums,0,0,nums.size()-1);
     // int sum_range = sum_range_segment_tree(value,0,0,nums.size()-1,2,4);
     // cout<<"sum_range [2,5]="<<sum_range<<endl;
     // update_segment_tree(value,0,0,nums.size()-1,2,10);
     // sum_range = sum_range_segment_tree(value,0,0,nums.size()-1,2,4);
     // cout<<"sum_range [2,5]="<<sum_range<<endl;

     NumArray num_array(nums);
     cout<<"sum_range [1,2]="<<num_array.sumRange(0,2)<<endl;
     num_array.update(1,2);
     cout<<"sum_range [1,2]="<<num_array.sumRange(0,2)<<endl;
     

}











