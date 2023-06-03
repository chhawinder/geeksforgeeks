//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>res(n,vector<int>(m,-1));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                res[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int dx[]={0,0,-1,1};
	    int dy[]={-1,1,0,0};
	    
	    while(q.size()){
	        int row=q.front().first;
	        int col=q.front().second;q.pop();
	        
	        for(int k=0;k<4;k++){
	            int nr=row+dx[k];
	            int nc=col+dy[k];
	            if(nc<0||nr<0||nr>=n||nc>=m)continue;
	            if(grid[nr][nc]==0){
	                if(res[nr][nc]==-1){
	                    res[nr][nc]=res[row][col]+1;
	                    q.push({nr,nc});
	                }else{
	                    res[nr][nc]=min(res[nr][nc],res[row][col]+1);
	                }
	            }
	        }
	        
	    }return res;
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends