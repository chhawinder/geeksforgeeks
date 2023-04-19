//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    int help(const vector<int>& kp,const vector<int>& tp,int n,int steps){
    if(kp==tp)return steps;
    if(kp[0]<0||kp[1]<0||kp[0]>n||kp[1]>n)return 1e9;
    int s1=help({kp[0]-2,kp[1]+1},tp,n,steps+1);
    int s2=help({kp[0]-2,kp[1]-1},tp,n,steps+1);
    int s3=help({kp[0]+1,kp[1]-2},tp,n,steps+1);
    int s4=help({kp[0]-1,kp[1]-2},tp,n,steps+1);
    int s5=help({kp[0]-1,kp[1]+2},tp,n,steps+1);
    int s6=help({kp[0]+1,kp[1]+2},tp,n,steps+1);
    int s7=help({kp[0]+2,kp[1]-1},tp,n,steps+1);
    int s8=help({kp[0]+2,kp[1]+1},tp,n,steps+1);
    return min(s1,min(s2,min(s3,min(s4,min(s5,min(s6,min(s7,s8)))))));
}
bool isValid(int nrow, int ncol, int N) {
        return nrow >= 1 && nrow <= N && ncol >= 1 && ncol <= N;
    }

    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int kx=KnightPos[0];
	    int ky=KnightPos[1];
	    int tx=TargetPos[0];
	    int ty=TargetPos[1];
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{kx,ky},0});
	    vector<vector<int>>vis(n+1,vector<int>(n+1,0));
	    vis[kx][ky]=1;
	    int minsteps=1e9;
	    while(q.size()!=0){
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int dis=q.front().second;
	        q.pop();
	        if(r==tx&&c==ty)return dis;
	        int drow[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	        int dcol[] = {1, 2, 2, 1, -1, -2, -2, -1};
	   for(int i=0;i<8;i++){
	       int nr=r+drow[i];
	       int nc=c+dcol[i];
	       if(isValid(nr,nc,n)&&vis[nr][nc]==0){
	           q.push({{nr,nc},dis+1});
	           vis[nr][nc]=1;
	           
	       }
	       
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends