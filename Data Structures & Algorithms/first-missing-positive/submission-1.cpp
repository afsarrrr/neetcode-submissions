class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int targetIdx = nums[i] - 1;

            if(nums[i] > 0 &&
               nums[i] <= n &&
               nums[i] != nums[targetIdx]) {

                swap(nums[i], nums[targetIdx]);
                i--;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};