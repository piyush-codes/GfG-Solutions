//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int distributeTicket(int N, int K) {
        int i=1, j=N;
        bool flag = false;
        int k=K;
        while(i<j) {
            k = K;
            if(flag == false){
                while(k-- and i<j) i++;
            }
            else {
                while(k-- and i<j)j--;
            }
            flag = !flag;
        }
        return i;
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
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends