//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int sol=INT_MAX;int j=0;
        int z=0,o=0,t=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0')z++;
            if(S[i]=='1')o++;
            if(S[i]=='2')t++;
            while(z&&o&&t){
                sol=min(sol,i-j+1);
                if(S[j]=='0')z--;
                if(S[j]=='1')o--;
                if(S[j]=='2')t--;
                j++;
            }
        }
        if(sol==INT_MAX)return -1;
        return sol;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends