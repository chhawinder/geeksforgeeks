//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        // code here
        //itrate over the array 
            //store frequency ->should i use pq for the storage ->not aware that map is dynamic according to frequency(lets try)
            //take first k elements from the map
        // return array of array
        
        //array->set  frequency->set  set removal is easy 
        //per itration check the frequeny take out the number and change the set it was in and then update the result
        
        
        // dryrun:
        //52132
        //it 1: 5 1:5,5->1
        
        // vector<vector<int>>solution(N);
        // map<int,int>m;
        // vector<set<int>>freq(N+1);
        // for(int i=0;i<N;i++){
        //     if(m.find(arr[i])!=m.end()){
        //         freq[m[arr[i]]].erase(arr[i]);
        //         freq[m[arr[i]]+1].insert(arr[i]);
                
        //     }else{
        //         freq[1].insert(arr[i]);
        //     }
        //     m[arr[i]]++;
        //     vector<int>temp;
            
        //     for(int j=N;j>0&&temp.size()<K;j--){
        //         if(freq[j].size()!=0){
        //             for (auto itr = freq[j].begin();itr != freq[j].end(); itr++) 
        //               {
        //                   if(temp.size()<K){
        //                       temp.push_back(*itr);
        //                   }
        //                 // cout<<*itr<<" ";
                        
        //               }
        //         }
        //     }
        //     solution.push_back(temp);
        // }
        
        
        
        // return solution;
        
        
        vector<int> place(k+1 , 0);
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++)
        {
            place[k] = arr[i];
            mp[arr[i]]++;
            
            int ele =find( place.begin() , place.end()-1,arr[i])-place.begin()-1;
            
            for(int j = ele ; j>=0 ;j--)
            {
                if(mp[place[j]] < mp[place[j+1]] || (mp[place[j]] == mp[place[j+1]] && place[j]>place[j+1]))
                    swap(place[j], place[j+1]);
                else   break;
            }
            
            vector<int> temp;
            for(int j= 0 ; j<k && place[j]!=0; j++)
                temp.push_back(place[j]);
                
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends