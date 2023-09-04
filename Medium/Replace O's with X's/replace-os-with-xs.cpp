//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>res(n,vector<char>(m,'X'));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                q.push({0,i});
                res[0][i]='O';
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                q.push({i,0});
                res[i][0]='O';
            }
        }
        for(int i=0;i<n;i++){
    if(mat[i][m-1]=='O'){
        q.push({i, m-1}); // Push the correct column 'm-1'
        res[i][m-1] = 'O'; // Update the correct column 'm-1'
    }
}

for(int i=0;i<m;i++){
    if(mat[n-1][i]=='O'){
        q.push({n-1, i}); // Push the correct row 'n-1'
        res[n-1][i] = 'O'; // Update the correct row 'n-1'
    }
}
        while(q.size()){
            int r=q.front().first;
            int c=q.front().second;q.pop();
            int dx[]={0,0,-1,1};
            int dy[]={1,-1,0,0};
            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr<0||nc<0||nr>=n||nc>=m)continue;
                if(mat[nr][nc]=='O'&&res[nr][nc]=='X'){
                    res[nr][nc]='O';
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends