#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int minCost2(vector<vector<int> > &costs)
{
    int num_house = costs.size();
    if(num_house==0)
        return 0;
    int i,j,k;
    int tem;
    int minValue = INT_MAX;

    for(j = 0;j<3;j++)
    {
        if(minValue > costs[0][j])
        {
            minValue = costs[0][j];
        }
    }
    if(num_house==1)
    {
        return minValue;
    }

    std::vector<std::vector<int> > value(num_house,std::vector<int> (3,minValue));
    for(i = 0;i<num_house;++i)
    {
        if(i==0)
        {
            for(j=0;j<3;++j)
            {
                value[i][j] = costs[i][j];
            }
            continue;
        }
        for(j=0;j<3;j++)
        {
            minValue = INT_MAX;
            for(k = 0;k<3;++k)
            {
                if(k==j)
                {
                    continue;
                }
                int tem = value[i-1][k]+costs[i][j];
                if(tem<minValue)
                    minValue = tem;
            }
            value[i][j] = minValue;
        }
    }
    minValue = INT_MAX;
    for(j = 0;j<3;++j)
    {
        if(minValue>value[num_house-1][j])
            minValue = value[num_house-1][j];
    }
    return minValue;
}
 int main()
 {
    int n ;
    cin>>n;
    std::vector<std::vector<int> > costs;
    for(int i=0;i<n;++i)
    {
        std::vector<int> item;
        int a,b,c;
        cin>>a>>b>>c;
        item.push_back(a);
        item.push_back(b);
        item.push_back(c);
        costs.push_back(item);
    }
    int ans = minCost2(costs);
    cout<<ans;
 }







