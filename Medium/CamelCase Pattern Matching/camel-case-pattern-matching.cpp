//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string Pattern) {
        // code here
        set<char>p;
        vector<string>res;
        
        for(int i=0;i<d.size();i++){
            string s;
            bool k=0;
            for(char j:d[i]){
                if((int)j>64&&(int)j<96){
                    s+=j;
                }
                if(s==Pattern&&k==0){
                    k=1;
                res.push_back(d[i]);
            }
            }
            
        }
        if(res.size()==0){
            res.push_back("-1");
            return res;
        } 
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends