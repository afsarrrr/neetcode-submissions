class Solution {
public:
    
    bool isValid(vector<int>& curr, vector<int>& fix) {
        for(int i = 0; i < 128; i++) {
            if(curr[i] < fix[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> fix(128, 0), curr(128, 0);

        for(auto c : t) fix[c]++;

        int l = 0;
        string ans = "";

        for(int r = 0; r < s.size(); r++) {
            curr[s[r]]++;

            while(isValid(curr, fix)) {
                string temp = s.substr(l, r - l + 1);

                if(ans.size() == 0 || temp.size() < ans.size()) {
                    ans = temp;
                }

                curr[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};