//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& grid) {
        // Code here
        queue<pair<int,int>>q;
        int n=grid.size();int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int dx[]={0,0,-1,1,1,1,-1,-1};
        int dy[]={1,-1,0,0,1,-1,1,-1};
        int res=0;
        while(q.size()){
            int r=q.front().first;int c=q.front().second;q.pop();
            int count=0;
            for(int k=0;k<8;k++){
                int nr=dx[k]+r;int nc=dy[k]+c;
                if(nr<0||nc<0||nr>=n||nc>=m)continue;
                if(grid[nr][nc]==0)count++;
            }
            if(count!=0&&count%2==0)res++;
            
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends