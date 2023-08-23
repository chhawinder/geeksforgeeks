//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 bool dfs(vector<vector<char>>grid,int i,int j,int dx,int dy,int k,string word){
     
     if(k==word.size())return true;
     
     int nr=i+dx;int nc=j+dy;
     if(nr<0||nc<0||nr>=grid.size()||nc>=grid[0].size())return false;
     if(word[k]!=grid[nr][nc])return false;
     return dfs(grid,nr,nc,dx,dy,k+1,word);
     
 }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    queue<pair<int,int>>q;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==word[0]){
	                q.push({i,j});
	            }
	        }
	    }
	    vector<vector<int>>res;
	    while(q.size()){
	        int i=q.front().first;int j=q.front().second;q.pop();
	        int dx[]={0,0,1,-1,1,1,-1,-1};
	        int dy[]={1,-1,0,0,1,-1,1,-1};
	        for(int k=0;k<8;k++){
	            if(dfs(grid,i,j,dx[k],dy[k],1,word)){
	                res.push_back({i,j});
	                break;
	            }
	        }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends