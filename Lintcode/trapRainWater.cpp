#include<iostream>
#include<vector>
using namespace std;


int trapRainWater(vector<int> &heights) {
        // write your code here
        int len = heights.size();
        vector<int> leftMax;
        std::vector<int> rightMax;
        int tem = heights[0];
        leftMax.push_back(tem);
        for(int i=1;i<len;++i)
        {
            if(heights[i]>tem)
                tem = heights[i];
            leftMax.push_back(tem);
        }
        tem = heights[len-1];
        rightMax.push_back(tem);
        for(int i=len-2;i>=0;--i)
        {
            if(heights[i]>tem)
                tem = heights[i];
            rightMax.push_back(tem);
        }
        int sum=0;
        for(int i=0;i<len;++i)
        {
            sum+=min(leftMax[i],rightMax[i])-heights[i];
        }
        return sum;
    }

    int main()
    {
        int c[]={0,1,0,2,1,0,1,3,2,1,2,1};
        std::vector<int> v(c,c+12);
        int ans = trapRainWater(v);
        cout <<ans;
        return 0;
    }