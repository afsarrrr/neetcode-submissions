class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(auto c : nums) {
                if(i - c >= 0 && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[n];
    }
};