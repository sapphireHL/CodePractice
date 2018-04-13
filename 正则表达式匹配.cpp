class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern) return false;
        int n = strlen(str), m = strlen(pattern);
        //str为空特别考虑
        if(n == 0 && m != 0){
            if(m < 2) return false;
            int i = 1;
            while(i < m){
                if(pattern[i] != '*') return false;
                i += 2;
            }
            return true;
        }
        
        vector<vector<int> > dp(n+1, vector<int>(m+1));
        dp[0][0] = 1;
        for(int j=1; j<=m; j++){
            if(pattern[j-1] == '*') 
                dp[0][j] = dp[0][j-2];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(pattern[j-1] == '.' || str[i-1] == pattern[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[j-1] == '*'){
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || ((pattern[j-2]=='.' || pattern[j-2] == str[i-1]) && dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
