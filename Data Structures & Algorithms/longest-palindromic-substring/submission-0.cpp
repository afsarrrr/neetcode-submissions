class Solution {
public:
    string longestPalindrome(string s) {
         int n=s.size();
       int ans=1,start=0;

       for(int i=0;i<n;i++){
        int j=i-1,k=i+1;
        int cnt=1;

        while(j>=0 && k<n){
            if(s[j]==s[k]){
                cnt+=2;
                if(cnt>ans){
                    ans=cnt;
                    start=j;
                }
                j--;
                k++;
            }
            else break;
        }

        j=i-1,k=i;
        cnt=0;

        while(j>=0 && k<n){
            if(s[j]==s[k]){
                cnt+=2;
                if(cnt>ans){
                    ans=cnt;
                    start=j;
                }
                j--;
                k++;
            }
            else break;
        }
       }

       return s.substr(start,ans);
    }
};
