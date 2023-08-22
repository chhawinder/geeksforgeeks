//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int a= 0,b = 0;
         for(int i = 0;i<n;i++)
         {
            int colsum = 0, rowsum = 0;
             for(int j = 0;j<n;j++)
             {
                 colsum += matrix[i][j];
                 rowsum += matrix[j][i];
             }
             a = max(a,colsum);
             b = max(b,rowsum);
         }
         a = max(a,b);
         int ans = 0;
         for(int i = 0;i<n;i++)
         {
             int sum1 = 0;
             for(int j = 0;j<n;j++)
             {
                 sum1 += matrix[i][j];
             }
             ans += abs(a-sum1);
         }
         return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends