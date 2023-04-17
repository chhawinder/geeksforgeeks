//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfshelp(int start,int V, vector<int> adj[],vector<int>&vis,vector<int>&path){
        for(int c:adj[start]){
            if(vis[c]==-1&&path[c]==0){
                vis[c]=1;
                path[c]=1;
                if(dfshelp(c,V,adj,vis,path)==true)return true;
            }else if(vis[c]==1&&path[c]==1)return true;
            
        }
        path[start]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // vector<int>vis(V,-1),path(V,0);
        // for(int i=0;i<V;i++){
        //     if(vis[i]==-1){
        //         vis[i]=1;
        //         path[i]=1;
        //         if(dfshelp(i,V,adj,vis,path)==true)return true;
        //     }
        // }
        // return false;
        
        // //using khan's algo
        
        // vector<int>ind(V,0);
        // for(int i=0;i<V;i++){
        //     for(int it:adj[i]){
        //         ind[it]++;
        //     }
        // }
        // queue<int>q;
        // for(int i=0;i<V;i++){
        //     if(ind[i]==0)q.push(i);
        // }
        // vector<int>res;
        // while(q.size()!=0){
        //     int t= q.front();
        //     q.pop();
        //     res.push_back(t);
        //     for(int i:adj[t]){
        //         ind[i]--;
        //         if(ind[i]==0)q.push(i);
        //     }
            
            
        // }
        // if(res.size()!=V)return true;
        // return false;
        
        //toposort
        vector<int>topo(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                topo[it]++;
            }
        }
        //queue intiate
        queue<int>q;
        for(int i=0;i<V;i++){
            
            if(topo[i]==0)q.push(i);
        }
         vector<int>res;
        while(q.size()!=0){
            int t=q.front();
            q.pop();
            res.push_back(t);
            for(auto it:adj[t]){
                topo[it]--;
                if(topo[it]==0)q.push(it);
            }
        }
        if(res.size()==V)return false;
        return true;
        
        
        
        
        
        
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends