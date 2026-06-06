class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            int take=nums[i];
            if(i-2>=0)take+=dp[i-2];
            int notTake=0;
            if(i-1>=0)notTake+=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};
