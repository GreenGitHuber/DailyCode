/*假设有一个数组，它的第i个元素是一个给定的股票在第i天的价格。
设计一个算法来找到最大的利润。你可以完成尽可能多的交易(多次买卖股票)。
然而,你不能同时参与多个交易(你必须在再次购买前出售股票)。

样例 给出一个数组样例[2,1,2,0,1], 返回 2
*/
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(std::vector<int> prices)
{
    int len = prices.size();
    if(len<2)
        return 0;
    int sum=0;//最后总的利润
    int i=0,j=0;
    while(j<len-1)
    {
        if (prices[j]>prices[j+1])
        {
            int pro=prices[j]-prices[i];
            sum+=pro;
            ++j;
            i=j;
        }
        else 
            j++;
    }
    if(i!=j)
        sum+=prices[j]-prices[i];
    return sum;

}

int main()
{
    int prices[]={2,1,2,0,1};
    vector<int> p (prices,prices+5);
    int ans=maxProfit(p);
    cout<<ans;
    return 0;
}
/*这道题的思路就是找到上升序列*/

