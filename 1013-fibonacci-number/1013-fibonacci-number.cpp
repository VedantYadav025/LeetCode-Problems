class Solution {
public:
    int fib(int n) {
        int dp[n + 1];
        for (int i = 0; i < n + 1; i++){
            dp[i] = -1;
        }
        return helper(n, dp);
    }
private:
    int helper(int n, int* dp){
        if (n == 0 || n == 1){
            return n;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }
};