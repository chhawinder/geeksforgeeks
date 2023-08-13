//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9+7;
    int nthFibonacci(int n){
        // code here
        vector<long long int>dp(n+1,0);
        dp[0]=0;dp[1]=1;
        int i=2;
        while(i<n+1){
            long long int temp=(dp[i-1]+dp[i-2])%mod;
            dp[i]=temp;
            i++;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends