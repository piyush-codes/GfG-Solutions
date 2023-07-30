//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    int findMax(int arr[], int n){
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
            maxi= max(arr[i], maxi);
        return maxi;
    }
    
    int findSum(int arr[], int n){
        int sum=0;
        for(int i=0; i<n; i++)
            sum+= arr[i];
        return sum;
    }
    
    int countBooks(int arr[],int pages, int n){
        int books=1, pagesAlloted=0;
        for(int i=0; i<n; i++){
            if(pagesAlloted+arr[i] <= pages){
                pagesAlloted += arr[i];
            }
            else{
                books++;
                pagesAlloted = arr[i];
            }
        }
        return books;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n) return -1;

        int low= findMax(arr, n);
        int high = findSum(arr, n);
    
        while(low<=high){
            int mid= low+(high-low)/2;
            int bookCnt = countBooks(arr, mid, n);
    
            if(bookCnt > m) low= mid+1;
            else high= mid-1;
        }
        return low;
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