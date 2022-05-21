// [1] https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

// Code : 

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum){
    
    int n=arr.size();
    int dp[n+1][sum+1];
    
    for(int i=0;i<=n;++i) dp[i][0]=1;
    for(int i=1;i<=sum;++i) dp[0][i]=0;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=sum;++j)
        {
            if(arr[i-1]<=j) dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}


int main()
{
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    
    int sum; cin>>sum;
    
    cout<<isSubsetSum(v,sum);
       
}

