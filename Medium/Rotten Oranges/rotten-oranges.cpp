//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};
        int time=0;
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(r+dr[k]<0||c+dc[k]<0||r+dr[k]>=grid.size()||c+dc[k]>=grid[0].size()){
                        continue;
                    }
                    if(grid[r+dr[k]][c+dc[k]]==1){
                        grid[r+dr[k]][c+dc[k]]=2;
                        q.push({r+dr[k],c+dc[k]});
                    }
                }
            }
            if(q.size()!=0)time++;
        }
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends