//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            stack<string> numBackup;
            stack<char> opeBackup;
            string element = "";
            
            for(int i = 0 ; i<s.size();i++){
                while(s[i]>=48 && i<s.size())
                element += s[i++];
                numBackup.push(element);
                if(i<s.size()){opeBackup.push(s[i]);}
                element.clear();
            }
            s= "";
            while(numBackup.size() && opeBackup.size()){
                s += numBackup.top();
                s += opeBackup.top();
                opeBackup.pop();
                numBackup.pop();
            }
            while(numBackup.size()){
                s += numBackup.top();
                numBackup.pop();
            }
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends