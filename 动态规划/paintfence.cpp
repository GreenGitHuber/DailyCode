#include<iostream>
using namespace std;
/*题目中要求给n个栅栏涂颜色，有k种颜色可以选择，限制条件是最多可以有两个相邻的栅栏颜色相同。
*/
int numWays(int n,int k)
{
    //n表示n个栅栏，k表示有k种颜色
    if(n==0 || k ==0)
        return 0;
    if(n==1)
        return k;
    if(n==2)
        return k*k;
    int way[3] ={0};//辅助数组,用3个变量就可以了
    way[0] = k;
    way[1] = k*k;
    //动态规划的步骤
    for(int i=2;i<n;++i){
        way[2]=(k-1)*(way[0]+way[1]);// 依据相邻的两个栅栏的填涂方法数来求解第3个栅栏的填涂方法数
        way[0]=way[1];
        way[1]=way[2];
    }
    return way[2];
}

