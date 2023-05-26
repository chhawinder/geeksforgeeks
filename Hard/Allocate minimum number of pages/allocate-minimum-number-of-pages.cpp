//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

  class Solution 
{
    public:
    bool isAllocation(int barrier,int A[],int N , int M){
        int pages =0;
        int no_of_allocated_students=1;
        for(int i=0;i<N;i++){
            if(A[i]>barrier){
                return false ;
            }
            else{
                if(pages+A[i]<=barrier){
                    pages = pages + A[i];
                }
                else{
                    pages = 0;
                    
                    no_of_allocated_students +=1;
                    pages = pages + A[i];
                }
            }
        }
        if(no_of_allocated_students <=M){
            return true;
        }
        else{
            return false;
        }
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        int low =A[0];
        for(int i=1;i<N;i++){
            if(A[i]<low){
                low = A[i];
            }
        }
        int high=0;
        for(int i=0;i<N;i++){
            high = high + A[i];
        }
        int res=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(isAllocation(mid,A,N,M)==true){
                res=mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
       return res;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends