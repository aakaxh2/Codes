// coins change : https://leetcode.com/problems/coin-change/

const int N=10005;
const int M=15;
class Solution {
public:
    int dp[M][N];
    bool flag=false;
    int fun(vector<int>&v, int x, int i)
    {
        if(x==0) {
            flag=true;
            return 0;
        }
        if(i>=v.size() || x<0) return 100;
        
        if(dp[i][x]!=-1) return dp[i][x];
        
        int y=100;
        if(v[i]<=x) y=1+fun(v,x-v[i],i); // if i can take this coin, then take it and go for same once again
        y=min(y,fun(v,x,i+1)); // else go for next one
        
        return dp[i][x]=y;
    }
    
    int coinChange(vector<int>& coins, int amount) {

        memset(dp,-1,sizeof(dp));
        int ans=fun(coins,amount,0);
        
        if(flag==true) return ans;
        
        return -1;
    }
};


// ------------------------------------- end -----------------------------


