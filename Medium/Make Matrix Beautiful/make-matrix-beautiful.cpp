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
        vector<int>row(matrix.size());int m=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum+=matrix[i][j];
            }
            row[i]=sum;
            m=max(m,sum);
        }
        int res=0;
        for(int i=0;i<matrix.size();i++){
            res+=m-row[i];
        }
        
        vector<int>col(matrix[0].size());int m2=INT_MIN;
        for(int i=0;i<matrix[0].size();i++){
            int sum=0;
            for(int j=0;j<matrix.size();j++){
                sum+=matrix[j][i];
            }
            col[i]=sum;
            // cout<<col[i]<<" ";
            m2=max(m2,sum);
        }
        
        int res2=0;
        for(int i=0;i<matrix.size();i++){
            res2+=m2-col[i];
        }
        return max(res,res2);
        // code here 
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