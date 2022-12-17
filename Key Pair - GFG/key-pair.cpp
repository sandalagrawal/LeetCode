//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    /*
	    unordered_set<int>s;
	    for(int i=0;i<n;i++){
	       s.insert(arr[i]);
	        
	    }
	    
	    for(int i=0;i<n;i++){
	        int temp = x - arr[i];
	        if(s.count(temp)){
	            return 1;
	            s.erase(arr[i]);
	        }
	    }
	   
	   return 0; */
	   
	   unordered_map <int,int> umap;
	   for(int i=0;i<n;i++){
	       umap[arr[i]]++;
	   }
	   
	   for(auto itr = umap.begin(); itr!=umap.end();itr++){
	       int key = itr->first;
	       int val = itr->second;
	       
	       int temp = x - key;
	       if(temp ==key){
	           if(val>1){
	               return true;
	           }
	           }
	           else{
	               if(umap.find(temp)!=umap.end()){
	                   return true;
	               }
	           }
	       
	       
	       
	   }
	   
	   return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends