//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
         int answer=0;
        int count1=0;
        int count2=0;
        for(auto i:S)
        {
            if(i == '[') 
            {
                if(count2 !=0)
                {
                    answer+=count2;
                    count2--;
                }
                else count1++;
            } 
            else if(count1 == 0) 
            {
                count2++;
            } 
            else count1--;
        }
        return answer+count1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends