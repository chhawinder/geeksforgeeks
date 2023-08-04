//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
long long int powi(int k, int n) {
    long long int ans = 1;
    while (n > 0) {
        ans *= k;
        n--;
    }
    return ans;
}



	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long int l = 1, h = m;
    while (l <= h) {
        long long int mid = l+ (h-l)/ 2;
        // long long int p = powi(mid, n);
        if (pow(mid,n)==m) return mid;
        if (pow(mid,n)>m) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends