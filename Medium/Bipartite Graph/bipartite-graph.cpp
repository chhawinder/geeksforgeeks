//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V, -1); // Initialize with -1
        queue<int> q;

        for (int i = 0; i < V; i++) { // Iterate over all nodes
            if (col[i] == -1) { // If the node is uncolored
                q.push(i);
                col[i] = 0; // Assign color 0 to the node

                while (!q.empty()) {
                    int temp = q.front();
                    q.pop();

                    for (int it : adj[temp]) {
                        if (col[it] == -1) { // If the neighbor is uncolored
                            col[it] = 1 - col[temp]; // Assign the opposite color of the current node
                            q.push(it);
                        } else if (col[it] == col[temp]) { // If the neighbor has the same color as the current node
                            return false; // Not bipartite
                        }
                    }
                }
            }
        }

        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends