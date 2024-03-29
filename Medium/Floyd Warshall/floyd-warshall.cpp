//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int i=0;i<matrix.size();i++){
	        //via i
	        for(int m=0;m<matrix.size();m++){
	            for(int n=0;n<matrix.size();n++){
	                if(m==i)break;
	                if(n==i)continue;
	                int f=matrix[m][i];
	                int s=matrix[i][n];
	                if(f==-1||s==-1)continue;
	                if(matrix[m][n]==-1)matrix[m][n]=f+s;
	                else matrix[m][n]=min(f+s,matrix[m][n]);
	                
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends