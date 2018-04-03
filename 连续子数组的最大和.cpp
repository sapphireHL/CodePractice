class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) 
            return 0;
        vector<int> dp(array.size(), INT_MIN);
        dp[0] = array[0];
        //以i结尾的最大和
        //dp[i] = max(dp[i-1]+num[i], num[i]);
        int res = INT_MIN;
        for(int i = 1; i < array.size(); i++){
            dp[i] = max(dp[i-1]+array[i], array[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
