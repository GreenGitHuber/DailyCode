class Solution {
public:
    /*
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.给定一个可能具有重复数字的列表，返回其所有可能的子集
     */
     
    vector<bool> flag;
    set<vector<int> > result;
    vector<vector<int>> res;
    vector<int> item;
    void robot(int index,vector<int> &nums)//函数的返回值是void
    {
        int n = nums.size();
        if(index>=n)
        {
            for(int i=0;i<n;i++)
            {
                if(flag[i])
                item.push_back(nums[i]);
            }
            if(result.find(item)==result.end())
            {
                result.insert(item);
                res.push_back(item);
            }
            item.clear();
            return;
        }
        flag.push_back(true);
        robot(index+1,nums);
        flag.pop_back();
        flag.push_back(false);
        robot(index+1,nums);
        flag.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        robot(0,nums);
        return res;
    }
};