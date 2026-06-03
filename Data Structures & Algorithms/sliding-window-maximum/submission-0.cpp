class Solution {
public:
    #define pp pair<int,int>

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pp> pq;

        vector<int> ans;
        int n=nums.size();

        for(int r=0;r<n;r++){

            pq.push({nums[r],r});

            while(!pq.empty() && pq.top().second<=r-k){
                pq.pop();
            }

            if(r>=k-1){
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};