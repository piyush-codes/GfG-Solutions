//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        long long c=0,b=0;
        for(auto i:bills)
        {
            if(i==5)
                c++;
            else if(i==10){
                if(c>0){
                c--;
                b++;
                }
                else
                    return false;
            }
                
            else
            {
                if(b>0 && c>=1){
                    b--;c--;
                }
                else if(c>=3)
                    c-=3;
                //else if(b)
                else
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends