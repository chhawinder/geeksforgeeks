//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char,int>p,t;
	    for(auto it:pat){
	        p[it]++;
	    }
	    for(int i=0;i<pat.size();i++){
	        t[txt[i]]++;
	    }
	    int i=0,j=pat.size(),count=0;
	    while(j<txt.size()){
	       if(p == t) // Check if the character frequency maps are equal
	                count++;
	            
	            // Remove the leftmost character from the window
	            t[txt[i]]--;
	            if(t[txt[i]] == 0)
	                t.erase(txt[i]);
	        i++;
	        t[txt[j++]]++;
	    }
	    if(p == t) // Check if the character frequency maps are equal
	                count++;
	    
	    return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends