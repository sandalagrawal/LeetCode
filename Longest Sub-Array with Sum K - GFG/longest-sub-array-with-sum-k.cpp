//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // better sol
        map<int, int> premap;
        int sum=0;
        int maxLen =0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum == K){
                maxLen = max(maxLen , i+1);
            }
            int rem = sum - K;
            if(premap.find(rem) != premap.end()){
                int len = i - premap[rem];
                maxLen = max(maxLen, len);
            }
            // PROBLEM with above solution is that it dosen't work with 0's and negative numbers.
            //premap[sum] = i;
            // what we'll do
            
            if(premap.find(sum)==premap.end()){ premap[sum] = i;}
        }
        return maxLen;
        
        // PROBLEM with above solution is that it dosen't work with 0's and negative numbers.
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends