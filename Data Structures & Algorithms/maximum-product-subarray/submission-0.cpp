class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int t1=max({nums[i],nums[i]*mini,nums[i]*maxi});
            int t2=min({nums[i],nums[i]*mini,nums[i]*maxi});
            maxi=max(t1,t2);
            mini=min(t2,t2);
            ans=max(ans,maxi);
        }
        return ans;
    }
};
