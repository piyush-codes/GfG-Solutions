//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
    bool sortcol(Job v1,Job v2)
    {
     return v1.profit > v2.profit;
    }

class Solution 
{

    public:
    //Function to find the maximum profit and the number of jobs done.

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
      sort(arr,arr+n,sortcol);
        vector<int>maxprofit(n);
        int cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(maxprofit[arr[i].dead-1]==0)
                maxprofit[arr[i].dead-1]=arr[i].profit,sum+=arr[i].profit,cnt++;
            else{
                int j=arr[i].dead-1;
                while(j>=0){
                    if(maxprofit[j]==0){
                     maxprofit[j]=arr[i].profit,sum+=arr[i].profit,cnt++;
                     break;
                     
                    }
                     j--;
                        
                }
                   
                    
            }
        }
        vector<int>x(2);
        x[0]=cnt;
        x[1]=sum;
        return x;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends