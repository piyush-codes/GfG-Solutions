//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
       set<int>st;    //creating a set
        
        while(head1){
            st.insert(head1->data);        //inserting data in sorted and remove dupicacy in set
            head1 = head1->next;
        }
        while(head2){
            st.insert(head2->data);        //inserting data in sorted and remove dupicacy in set
            head2 = head2->next;
        }
        
        Node *list = new Node(0);     //creating a list for adding those data
        Node *h = list;    // creating pointer ,pointing to list
        
        for(auto i:st){ 
            list->next = new Node(i);      //traversing though the set and putting all data together
            list = list->next;
        }
        return h->next;
        
    
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int data;
    cin>> data;
    
    Node* head = new Node(data);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends