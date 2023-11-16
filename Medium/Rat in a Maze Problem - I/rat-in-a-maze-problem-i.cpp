//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m , int n , vector<string>&ans,
    string output , vector<vector<int>>&vis, int i , int j){
        
        if( i == n-1 && j == n-1){
            ans.push_back(output);
            return;
        }
        
        
        // DLRU
        
        // DOWN
        //  i = i+1 and j=j
        if(i+1 < n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i][j] = 1;
            solve(m , n , ans , output+"D" , vis , i+1 , j);
            vis[i][j] = 0;
        }
        
        // LEFT
        // i = i and j = j-1
        if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j] = 1;
            solve(m , n , ans , output+"L" , vis , i , j-1);
            vis[i][j] = 0;
        }
        
        // RIGHT
        // i = i and j = j+1
        if(j+1 < n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j] = 1;
            solve(m , n , ans , output+"R" , vis , i , j+1);
            vis[i][j] = 0;
        }
        
        // UP
        // i = i-1 and j = j
        if(i-1 >= 0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i][j] = 1;
            solve(m , n , ans , output+"U" , vis , i-1 , j);
            vis[i][j] = 0;
        }
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        //storing whole output in ans 
         vector<string>ans;
        // check for visited or not
        vector<vector<int>>vis(n , vector<int>(n , 0));
        string output = "";
            
        int i=0 ; 
        int j=0 ;
        
        if(m[0][0] == 1) solve(m , n , ans , output , vis , i , j);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends