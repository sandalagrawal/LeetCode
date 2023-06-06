//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	
	void sort(int arr[], int n){
	    for(int i=0 ; i<n-1;i++){
	        int min = i;
	        for(int j=i+1; j<n;j++){
	            if(arr[j] < arr[min]){
	                min = j;
	            }
	            
	        }
	        swap(arr[i] , arr[min]);
	    }
	}
	
	
	
	int print2largest(int arr[], int n) {
	    
	   
	   
	    // brute force solution:
	    
	   /* sort(arr, n);
	    int larg = arr[n-1];
	    int sec_larg = -1;
	    for(int i = n-2; i >=0;i--){
	        if(arr[i] != larg){
	            sec_larg = arr[i];
	            break;
	        }
	    }
	    
	    return sec_larg;
	    // ye kuch test cases ke baad TLE maar jayega!
	    TC : O(n log n) + O(n)
	    */
	    
	    
	    
	    
	    
	    // better solution 
	    
/*	    int larg =0;
	    int sec_larg = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i] > larg){
	            larg = arr[i];
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i] > sec_larg && arr[i] < larg){
	            sec_larg = arr[i];
	        }
	    }
	    
	    return sec_larg;
	    // iski TC : O(n) + O(n) = 2 O(n);
	    */
	    
	   
	   
	   //optimal solution 
	   
	   
	    
	    int sec_larg=-1;
	    int larg = -1;
	    for(int i=0;i<n;i++){
	        
	        if(arr[i]>larg){
	            sec_larg = larg;
	            larg = arr[i];
	        }else if(arr[i] < larg && arr[i] > sec_larg){
	            sec_larg = arr[i];
	        }
	        
	    }
	    return sec_larg;
	    // TC : O(n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends