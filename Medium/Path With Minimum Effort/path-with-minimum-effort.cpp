//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int m, int n, vector<vector<int>> &a) {
        // code here
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0 ; i<a.size() ; i++)
        {
            for(int j=0 ; j<a[i].size() ; j++)
            {
                if((i-1)>=0)
                {
                    adj[i*n+j].push_back({(i-1)*n+j,abs(a[i][j]-a[i-1][j])});
                }
                if((j-1)>=0)
                {
                    adj[i*n+j].push_back({i*n+j-1,abs(a[i][j]-a[i][j-1])});
                }
                if(i+1<m)
                {
                    adj[i*n+j].push_back({(i+1)*n+j,abs(a[i][j]-a[i+1][j])});
                }
                if(j+1<n)
                {
                    adj[i*n+j].push_back({i*n+j+1,abs(a[i][j]-a[i][j+1])});
                }
            }
        }
        vector<int> distance(m*n,INT_MAX);
        distance[0]=0;
        set<pair<int,int>> myset;
        myset.insert({0,0});
        while(myset.size()>0)
        {
            pair<int,int> temp=*myset.begin();
            myset.erase(myset.begin());
            int node=temp.second;
            int dist2=temp.first;
            for(auto &it : adj[node])
            {
                int maxi=max(dist2,it.second);
                if(maxi<distance[it.first])
                {
                    distance[it.first]=maxi;
                    myset.insert({maxi,it.first});
                }
            }
        }
        return distance.back();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends