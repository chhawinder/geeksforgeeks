//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        
        if(n==1 && m==1)return 0;
      
        int left=0,right=0,up=0,down=0;
        
        int flagl=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='L'){
                
                left++;
                flagl=1;
            }
            else if(s[i]=='R' && flagl==1){
                
                left--;
            }
            
            if(left>=m){
                
                return 0;
            }
        }
        
        int flagr=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='R'){
                
                right++;
                flagr=1;
            }
            else if(s[i]=='L' && flagr==1){
                
                right--;
            }
            if(right>=m){
                
                return 0;
            }
        }
        
        int flagu=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='U'){
                
                up++;
                flagu=1;
            }
            else if(s[i]=='D' && flagu==1){
                
                up--;
            }
            
            if(up>=n){
                
                return 0;
            }
            
        }
        
        int flagd=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='D'){
                
                down++;
                flagd=1;
            }
            else if(s[i]=='U' && flagd==1){
                
                down--;
            }
            
            if(down>=n){
                
                return 0;
            }
        }
        
        if(up>=n || down>=n){
            
            return 0;
        }
        
        if(left>=m || right>=m){
            
            return 0;
        }
        
        return 1;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends