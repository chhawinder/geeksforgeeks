//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long  mod=1e9+7;
        long long  count=1;
        long long sol=0;
        for(int i=0;i<n;i++){
            long long  temp=i+1;
            long long  temp1=1;
            while(temp--){
                temp1=(temp1*count)%mod;
                count++;
            }
            sol=(temp1+sol)%mod;
        }
        return sol;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends