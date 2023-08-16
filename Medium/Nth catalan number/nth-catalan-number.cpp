//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int help(int sb,int se,stack<char>&st){
        
        if(sb==0&&se==0){
            if(st.size()==0)
            return 1;
            else 
            return 0;
            
        }
        //push
        st.push('(');
        int take=0;
        if(sb>0)take=help(sb-1,se,st);
        st.pop();
        int ntake=0;
        if(!st.empty()&&se>0){
            st.pop();
            ntake=help(sb,se-1,st);
        }
        return take+ntake;
    }
    int findCatalan(int n) 
    {
        long long int mod=1e9+7;
        vector<long long int>pref(n+1);
        pref[0]=1;
        pref[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                pref[i]+=(pref[j-1]*pref[i-j])%mod;
                pref[i]=(pref[i])%mod;
            }
        }
        return pref[n];
        //code here
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends