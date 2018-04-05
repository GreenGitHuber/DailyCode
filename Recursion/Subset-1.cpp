/*给定一个含不同整数的集合，返回其所有的子集*/

class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
   
    vector<bool> flag;
    vector<vector<int>> result;
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
            result.push_back(item);
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
    
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
       int len = nums.size();
    robot(0,nums);
    return result;
       
    }
};