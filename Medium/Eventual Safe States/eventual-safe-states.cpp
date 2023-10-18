//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        //reverse edges
        vector<vector<int>> r_adj(V+1);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                r_adj[it].push_back(i);
            }
        }
        //compute indegrees and push zero indegree
        vector<int>ind(V,0);
        for(int i=0;i<V;i++){
            for(auto it:r_adj[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int>res;
        while(q.size()){
            int temp=q.front();q.pop();
            res.push_back(temp);
            for(auto it:r_adj[temp]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
            
        }
        sort(res.begin(),res.end());
        return res;
        //get result
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends