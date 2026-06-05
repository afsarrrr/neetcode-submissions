class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int>a(26,0),b(26,0);
       int n1=s.size(),n2=t.size();
       if(n1!=n2)return false;
       for(int i=0;i<n1;i++){
        a[s[i]-'a']++;
        b[t[i]-'a']++;
       } 
       for(int i=0;i<26;i++){
        if(a[i]!=b[i])return false;
       }
       return true;
    }
};