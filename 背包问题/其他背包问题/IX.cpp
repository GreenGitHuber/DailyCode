class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        // write your code here
        int len = prices.size();
        for(int i =0;i<len;++i)
        {
            probability[i]=1- probability[i];
        }
        vector<double> dp(n+1,1);
        for (int i = 0; i < len; ++i)
        {
            for(int j = prices[i];j>=prices[i];j--)
            {
                dp[j]=min(dp[j],dp[j-prices[i]] *probability[i]);
            }
        }
        return 1-dp[n];
    }
};