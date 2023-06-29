//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    long long int e=0,o=0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='1')
	        {
	            if((i+1)&1)
	                o++;
	            else
	            e++;
	        }
	       // cout<<s[i]<<" "<<e<<" "<<o<<endl;
	    }
	    if((e-o)%3==0)
	        return 1;
	  return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends