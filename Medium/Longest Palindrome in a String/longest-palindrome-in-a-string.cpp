//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
      int n = str.length();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        string ans = str.substr(0,1);
        int len =1;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i][i] = 1;
            
            if( i-1>=0  && str[i]==str[i-1] ){
            dp[i-1][i] = 1;
            ans = str.substr(i-1,2);
            len =2;
            }
        }
        
        
        int count = 2;
        int i=0;
        
        while(count<n)
        {
            for(int j=0;j+count<n;j++)
            {
                
                if(dp[j+1][j+count-1]==1 &&  str[j]==str[j+count]){
                    
                dp[j][j+count] = 1;
                
                if(len<count+1)
                ans = str.substr(j,count+1);
                len = count+1;
                }
            }
            count++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends