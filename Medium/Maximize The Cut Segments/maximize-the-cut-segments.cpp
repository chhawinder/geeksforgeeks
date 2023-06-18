//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int help(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0;
        if(n<0) return INT_MIN;
        int a=-1,b=-1,c=-1;
        if(dp[n]!=-1)return dp[n];
       
            a=help(n-x,x,y,z,dp);
            b=help(n-y,x,y,z,dp);
            c=help(n-z,x,y,z,dp);
        int res=max(a,max(b,c));
        if(res==-1)return -1;
        return dp[n]=res+1;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int res=help(n,x,y,z,dp);
        if(res<0)return 0;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends