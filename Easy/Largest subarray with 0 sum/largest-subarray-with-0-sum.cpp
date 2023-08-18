//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int>m;
        int sum=0;int sol=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                sol=max(sol,i+1);
                continue;
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }else{
                sol=max(sol,i-m[sum]);
            }
        }
        return sol;
        // Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends