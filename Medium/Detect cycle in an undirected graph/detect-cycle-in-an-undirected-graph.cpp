//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int>vis(V,0);
        while(q.size()!=0){
            int temp=q.front();
            q.pop();
            if(vis[temp]==1)return true;
            vis[temp]=1;
            for(auto it:adj[temp]){
                if(vis[it]==0){
                    q.push(it);
                }
            }
            
            if(q.size()==0){
                for(int i=0;i<V;i++){
                    if(vis[i]==0){
                        q.push(i);
                        break;
                    }
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends