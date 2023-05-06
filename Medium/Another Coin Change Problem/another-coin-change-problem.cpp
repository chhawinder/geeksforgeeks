//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  bool help(int i, int k, int target, vector<int> &coins,vector<vector<int>>&dp){
       
      if(target==0)
        {
            if(k==0) return true;
            return false;
        }
        
        if(i==0) 
        {
            if(target%coins[0]==0 && target/coins[0]==k) return true;
            return false;
        }
      if(dp[target][k]!=-1)return dp[target][k];
      bool ntake;
      ntake=help(i-1,k,target,coins,dp);
      bool take=false;
      if(target>=coins[i])
      take=help(i,k-1,target-coins[i],coins,dp);
      return dp[target][k]= take||ntake;
      
  }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>>dp(target+1,vector<int>(K+1,-1));
        sort(coins.begin(),coins.end());
        return help(N-1,K,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends