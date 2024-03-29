//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int>s;
        for(int i=0;i<S.size();i++){
            if(S[i]=='*'){
                int k=s.top();s.pop();
                int k2=s.top();s.pop();
                s.push(k2*k);
                
            }else if(S[i]=='/'){
                int k=s.top();s.pop();
                int k2=s.top();s.pop();
                s.push(k2/k);
                
            }else if(S[i]=='-'){
                int k=s.top();s.pop();
                int k2=s.top();s.pop();
                s.push(k2-k);
                
            }else if(S[i]=='+'){
                int k=s.top();s.pop();
                int k2=s.top();s.pop();
                s.push(k2+k);
                
            }else{
                s.push((int)S[i]-(int)'0');
            }
        }
        return s.top();
        // Your code here
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends