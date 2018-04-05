#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool recursive(vector<int>& sequence,int begin,int end)
    {
        if(sequence.empty())
            return false;
        if(end<=begin)
            return true;
        int val = sequence[end];
        int i = begin;
        for(;i<end;i++)
        {
            if(sequence[i]>val)
                break;
        }
        int j = i;
        for(;j<end;j++)
        {
            if(sequence[j]<val)
                return false;
        }
        bool left = true;
        if(i>=begin)
            left = recursive(sequence,begin,i-1);
        bool right = true;
        if(i<=end)
            right = recursive(sequence,i,j);
        return left&&right;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        return recursive(sequence,0,sequence.size()-1);

    }
};
int main()
{
    Solution s;
    int arr[] = {9,8};
    vector<int> varr(arr, arr+2);
    bool res=s.VerifySquenceOfBST(varr);
    cout<<res;
    return 0;
}