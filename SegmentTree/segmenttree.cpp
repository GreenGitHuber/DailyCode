#include <iostream>
#include <vector>
using namespace std;


//线段树的创建
void bulid_segment_tree(vector<int>&value,vector<int> nums,int pos,int left,int right){
    //value 是指线段树数组（存放的是区间sum）
    //num存放的是原始数组
    if(left==right) {
        value[pos] = nums[left];
        return;
    }

    int mid = (left+right)/2;
    bulid_segment_tree(value,nums,pos*2+1,left,mid);
    bulid_segment_tree(value,nums,pos*2+2,mid+1,right);
    value[pos]=value[pos*2+1]+value[pos*2+2];
}

int get_sum_of(vector<int> values,int pos,int left,int right,int qleft,int qright){
    if(right<qleft||left>qright)
        return 0;
    if(qleft<=left&&qright>=right)
        return values[0];
    int mid = (left+right)/2;
    return get_sum_of(values,pos*2+1,left,mid,qleft,qright)+
           get_sum_of(values,pos*2+2,mid+1,right,qleft,qright);
}
//线段树的更新
void update_segment_tree(vector<int>&values,int pos,int left,int right,int index,int val){
    if(left==right&&left == index){
        values[pos]=val;
        return;
    }
    int mid = (right+left)/2;
    if(mid<index){
        update_segment_tree(values,pos*2+1,left,mid,index,val);
    }
    else
        update_segment_tree(values,pos*2+2,mid+1,right,index,val);
    values[pos]=values[pos*2+1]+values[pos*2+2];
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
