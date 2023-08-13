//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool pal(string a){
      string b=a;
      reverse(b.begin(),b.end());
      if(a==b)return true;
      return false;
  }
  void help(string word,string check,set<vector<string>>&res,int i,vector<string>&k){
      if(i==word.size()){
          if(check.size()>0&&pal(check)){
              k.push_back(check);
              res.insert(k);
              k.pop_back();
              return ;
          }else if(check.size()==0){
              res.insert(k);
              return ;
          }else{
              return ;
          }
      }
      check+=word[i];
      if(pal(check)){
          //take
          k.push_back(check);
          help(word,"",res,i+1,k);
          k.pop_back();
          //ntake
          
      }
      
          help(word,check,res,i+1,k);
          return ;
      
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        set<vector<string>>res;
        vector<string>k;
        help(S,"",res,0,k);
        vector<vector<string>>ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends