class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(nums.begin(),nums.end());
        for(auto n : nums)ans.push_back(n);
        return ans;
    }
};