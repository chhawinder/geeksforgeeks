//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    
    
    
    Node* findnode(Node* root,int target){
        if(root->data==target)return root;
        if(root->left){
            Node*p=findnode(root->left,target);
        if(p)return p;
        }
        if(root->right){
            Node*p=findnode(root->right,target);
        if(p)return p;
        }
        return nullptr;
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*,Node*>m;
        queue<Node*>qk;
        qk.push(root);
        m[root]=nullptr;
        while(qk.size()){
            Node*n=qk.front();
            qk.pop();
            if(n->left!=nullptr){
                m[n->left]=n;
                qk.push(n->left);
            }
            if(n->right!=nullptr){
                m[n->right]=n;
                qk.push(n->right);
            }
        }
        Node*temp=findnode(root,target);
        vector<int>res;
        set<Node*>vis;
        queue<pair<Node*,int>>q;
        q.push({temp,k});
        while(q.size()){
            
            Node*pk=q.front().first;
            vis.insert(pk);
            int level=q.front().second;
            q.pop();
            if(level==0){
                res.push_back(pk->data);continue;
            }
            
            if(pk->left&&vis.find(pk->left)==vis.end())q.push({pk->left,level-1});
            if(pk->right&&vis.find(pk->right)==vis.end())q.push({pk->right,level-1});
            if(m[pk]&&vis.find(m[pk])==vis.end())q.push({m[pk],level-1});
        
            
            
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends