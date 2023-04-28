//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int axorb=0;
        for(int i=1;i<=n;i++){
            axorb^=arr[i-1]^i;
        }
        int rmsb=axorb&(-axorb);
        int n1=0,n2=0;
        for( int i=0;i<n;i++){
            if(rmsb&arr[i])n1^=arr[i];
            else n2^=arr[i];
        }
        for(int it=1;it<=n;it++){
            if(rmsb&it)n1^=it;
            else n2^=it;
        }
       
        int* res = new int[2];
        for(int i=0;i<n;i++){
            if(arr[i]==n1){
                res[0]=n1;
                res[1]=n2;
                break;
            }
                
            else if(arr[i]==n2){
                res[0]=n2;
                res[1]=n1;
                break;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends