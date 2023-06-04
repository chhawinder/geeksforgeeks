//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string>num;
            stack<char>op;
            
            for(int i=0;i<s.size();i++){
                string k="";int val=(int)s[i]-(int)'0';
                while(val>=0&&val<=9){
                    k+=s[i++];
                    val=(int)s[i]-(int)'0';
                }
                num.push(k);
                if(i!=s.size())
                op.push(s[i]);
            }
            string res="";
            while(num.size()){
                res+=num.top();num.pop();
                if(op.size())
                res+=op.top();op.pop();
            }
            return res;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends