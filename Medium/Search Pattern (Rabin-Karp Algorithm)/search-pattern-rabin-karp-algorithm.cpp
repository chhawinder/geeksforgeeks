//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int hash1=0;int window=0;
            for(int i=0;i<pat.size();i++){
                hash1+=pat[i]-'a'+1;
                window+=txt[i]-'a'+1;
            }
            int i=0,j=pat.size();vector<int>res;
            while(j<=txt.size()){
                if(window==hash1){
                    bool flag=0;
                    for(int k=0;k<pat.size();k++){
                        if(pat[k]!=txt[i+k]){
                            flag=1;break;
                        }
                    }
                    if(flag==0)res.push_back(i+1);
                }
                window-=txt[i]-'a'+1;i++;
                window+=txt[j]-'a'+1;j++;
            }
            if(res.size()==0)res.push_back(-1);
            return res;
            
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends