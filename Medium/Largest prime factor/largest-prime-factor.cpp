//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    int isPrime(long long int x)
    {
        if(x<=1)
            return 0;
        for(long long int i=2;i<=sqrt(x);i++)
            if(x%i==0)
                return 0;
        return 1;
    }
    long long int largestPrimeFactor(int N){
        // code here
        long long int maxP=-1;
        for(long long int i=2;i<=sqrt(N);i++)
            if(N%i==0){
                if(isPrime(i))
                    maxP=i>maxP?i:maxP;
                if(isPrime(N/i))
                    maxP=(N/i)>maxP?(N/i):maxP;
            }
    if(maxP==-1)
        maxP=N;
        return maxP;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends