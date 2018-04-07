#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>



#include <vector>
#include <numeric>
#include <limits>

using namespace std;




int backPackII(int target, int N,vector<int> &nums, vector<int> &vals) {
    std::vector<int> f(target+1,0);
    f[0] = 1;
    for(int i = 0;i<2;++i)
    {
        for(int j=vals[i];j<=target;++j)
        {
            for(int k = 1;k<=nums[i];k++)
            {
                f[j] += f[j-vals[i]*k];
            }
        }
        
    }
    return f[target];

}


int main()
{
    int target;
    cin>>target;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    std::vector<int> vals;//zhongliang
    vals.push_back(a);
    vals.push_back(c);
    std::vector<int> nums;//shuliang
    nums.push_back(b);
    nums.push_back(d);
    int N = b+d;
    int ans = backPackII(target,N,nums,vals);
    cout<<ans<<endl;

}