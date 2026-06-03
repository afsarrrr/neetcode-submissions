class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=1;
        sort(nums.begin(),nums.end());
        for(auto n : nums){
            if(n<i)continue;
            else if(i==n)i++;
            else if(i>n)return i;
        }
        return i;
    }
};