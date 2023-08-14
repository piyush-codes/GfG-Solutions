//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool mysort(pair<double,Item> a,pair<double,Item> b)
{
    return a.first>b.first;
}
class Solution
{static bool cmp(Item a , Item b)
    {
        double ppw1 = (double)a.value / (double)a.weight;
        double ppw2 = (double)b.value / (double)b.weight;
        return ppw1 > ppw2;
    }
    
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        int i=0;
        double pro=0;
      
        while(W>0&&i<n)
        {
            if(W-arr[i].weight>=0)
            {
                pro+=arr[i].value;
                W=W-arr[i].weight;
            }
            else{
                pro+=((double)arr[i].value/(double)arr[i].weight)*W;
                W=0;
                break;
            }
            i++;
        }
        return pro;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends