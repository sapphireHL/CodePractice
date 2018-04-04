class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int num2 = 1, num3 = 1, num5 = 1;
        vector<int> dp(index + 1);
        dp[1] = 1;
        for(int i = 2; i <= index; i++){
            dp[i] = min(2*dp[num2], min(3*dp[num3], 5*dp[num5]));
            if(dp[i] == 2*dp[num2]) num2++;
            if(dp[i] == 3*dp[num3]) num3++;
            if(dp[i] == 5*dp[num5]) num5++;
        }
        return dp[index];
    }
};
