//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(int arr[] ,int k, int mid,int n){
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          if(sum>mid){
              sum=arr[i];
              k--;
          }
      }
      if(k>0)return true;
      return false;
  }
    int splitArray(int arr[] ,int n, int k) {
        // code here
        int l=0,h=0;
        for(int i=0;i<n;i++){
            h+=arr[i];
            l=max(l,arr[i]);
        }
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(arr,k,mid,n)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends