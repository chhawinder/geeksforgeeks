//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
         Node* ehead = NULL;
        Node* etail = NULL;
        Node* ohead = NULL;
        Node* otail = NULL;

        while (head) {
            if (head->data % 2 == 0) {
                if (ehead == NULL) {
                    ehead = head;
                    etail = head;
                } else {
                    etail->next = head;
                    etail = etail->next;
                }
            } else {
                if (ohead == NULL) {
                    ohead = head;
                    otail = head;
                } else {
                    otail->next = head;
                    otail = otail->next;
                }
            }
            head = head->next;
        }

        if (ehead == NULL) {
            return ohead;
        }
        if (ohead == NULL) {
            return ehead;
        }

        etail->next = ohead;
        otail->next = NULL;
        return ehead;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends