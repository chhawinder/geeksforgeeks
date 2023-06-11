//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int help(int arr[],int n,int i,int t,vector<vector<int>>&dp){
    if(t==0)return 1;
    if(i==n)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    int ntake=help(arr,n,i+1,t,dp);
    if(t<arr[i])return 0;
    int take=help(arr,n,i+1,t-arr[i],dp);
    dp[i][t]=take||ntake;
    return take||ntake;
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2!=0)return 0;
        sort(arr,arr+N);
        vector<vector<int>>dp(N,vector<int>((sum/2)+1,-1));
        return help(arr,N,0,sum/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends