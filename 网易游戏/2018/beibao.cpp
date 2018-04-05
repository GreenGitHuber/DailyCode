#include <iostream>
#include <vector>
using namespace std;


/*
输入描述:
输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。
*/
//对于一件物品，放进去or不放进去
//放进去那么不能超过，如果没有超过的话
int beibao(int index,int len, vector<int> & nums,int &tem_weight,int weight)
{
    if(index>=len && tem_weight<=weight)
        return 1;
    else if(tem_weight>weight)
        return 0;
    else
    {
        int noput = beibao(index+1,len,nums,tem_weight,weight);
        tem_weight += nums[index];
        int putin = beibao(index+1,len,nums,tem_weight,weight);
        return noput+putin;
    }

}




int main(){
    int num, weight;
    cin>>num>>weight;
    std::vector<int> nums;
    for(int i = 0;i< num;++i)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int tem_weight =0;
   
    int ans = beibao(0,num,nums,tem_weight,weight);
    cout<<ans;
    return 0;
}
    


