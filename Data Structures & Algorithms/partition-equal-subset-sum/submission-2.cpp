class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        sum/=2;
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        
        for(auto c : nums){
           for (int i = sum; i >= c; i--) {
                if(i-c>=0 && dp[i-c]){
                    dp[i]=dp[i]||dp[i-c];
                }
            }
        }
        return dp[sum];
    }
};
