class Solution 
{
    public:
    // n = 5
    //  0  1  2  3  4 
    // [0, 0, 0, 0, 0]
    int climbStairs(int n) 
    {
        if (n == 1 || n == 2) return n;

        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<n+1; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};