class Solution {
public:
    int countSubstrings(string s) {
       int n=s.size();
       int ans=0;

       for(int i=0;i<n;i++){
        int j=i-1,k=i+1;
        ans++;

        while(j>=0 && k<n){
            if(s[j]==s[k]){
                ans++;
                j--;
                k++;
            }
            else break;
        }

        j=i-1,k=i;
        while(j>=0 && k<n){
            if(s[j]==s[k]){
                ans++;
                j--;
                k++;
            }
            else break;
        }
       }

       return ans;  
    }
};
