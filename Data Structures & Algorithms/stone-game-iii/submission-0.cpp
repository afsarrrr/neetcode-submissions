#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int dp[50001][2][2];
    long long f(vector<int>&a,bool alice,bool bob,int idx){
        if(idx>=a.size())return 0;
        if(dp[idx][alice][bob]!=-1)return dp[idx][alice][bob];
        long long ans=0;
        long long sum=0;
        if(alice){
            ans=INT_MIN;
            for(int i=idx;i<idx+3 && i<a.size();i++){
                sum+=a[i];
                ans=max(ans,sum+f(a,false,true,i+1));
            }
        }
        if(bob){
            ans=INT_MAX;
            for(int i=idx;i<idx+3 && i<a.size();i++){
                sum+=a[i];
                ans=min(ans,f(a,true,false,i+1));
            }
        }
        return dp[idx][alice][bob]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        long long total=0;
        for(auto n : stoneValue)total+=n;
        long long alice=f(stoneValue,true,false,0);
        if(total-alice>alice)return "Bob";
        if(total-alice <alice)return "Alice";
        return "Tie";
    }
};