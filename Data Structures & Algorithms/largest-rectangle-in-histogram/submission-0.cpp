class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())left[i]=st.top();
            st.push(i);
        } 
        while(!st.empty())st.pop();
        vector<int>right(n,-1);
        for(int i=n-1;i>=0;i--){
          while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())right[i]=st.top();
            st.push(i);  
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=left[i]==-1?0:left[i]+1;
            int r=right[i]==-1?n-1:right[i]-1;
            ans=max(ans,heights[i]*(r-l+1));
        }
        return ans;
    }
};
