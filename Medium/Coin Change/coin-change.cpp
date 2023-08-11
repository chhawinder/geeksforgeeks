//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long int help(int coins[], int N, int sum,int i,vector<vector<long long int>>&dp){
      if(sum==0)return 1;
      if(i>=N)return 0;
      if(dp[i][sum]!=-1)return dp[i][sum];
      long long int take=0,ntake;
      ntake=help(coins,N,sum,i+1,dp);
      if(sum>=coins[i])take=help(coins,N,sum-coins[i],i,dp);
      return dp[i][sum]=take+ntake;
  }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
        for(int i=0;i<N;i++)dp[i][0]=1;
        for(int i=N-1;i>=0;i--){
            for(int s=1;s<=sum;s++){
                long long int take = 0, ntake = 0;

            if (s >= coins[i]) {
                take = dp[i][s - coins[i]];
            }

            if (i + 1 < N) {
                ntake = dp[i + 1][s];
            }

            dp[i][s] = take + ntake;
            }
        }
        
        return dp[0][sum];
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends