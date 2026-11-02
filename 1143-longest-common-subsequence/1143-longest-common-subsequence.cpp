class Solution {
public:
    int solve(string& text1, string& text2, int i, int j,vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
             dp[i][j] = 1 + solve(text1, text2, i-1, j-1,dp);
        }
        else{
            dp[i][j] = max(solve(text1, text2, i-1,j,dp) , solve(text1, text2, i, j-1,dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size();
        int j = text2.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1,-1));
        return solve(text1,text2,i-1,j-1,dp);
    }
};