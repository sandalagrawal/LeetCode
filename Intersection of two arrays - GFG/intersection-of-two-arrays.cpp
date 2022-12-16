//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
      /*  unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[a[i]]++;
        }
        for(int i=0;i<m;i++){
            umap[b[i]]++;
        }
        int ans=0;
        for(auto x: umap){
            if(x.second>1){
                ans++;
            }
        }
        return ans;*/
        
        //problem : agr dono arrays me repeating elements hue toh do baar ans++ ho jayega, which makes no sense. 
        //isliye use unordered_set and jaise hi koi common element milega, usko erase krte jyenge set se
        
        unordered_set<int>s;
        
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        
        int count=0;
        for(int i=0;i<m;i++){
            int key = b[i];
            if(s.find(key)!=s.end()){
                count++;
                s.erase(key);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends