//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int nums[], int n) {
	    vector<int>k;
        int count=0;
        for(int i=0;i<n;i++){
            int it=nums[i];
            if(it!=0){
                k.push_back(it);
            }else{
                count++;
            }
        }
        while(count--){
            k.push_back(0);
        }
        for(int i=0;i<n;i++){
            nums[i]=k[i];
        }
        
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends