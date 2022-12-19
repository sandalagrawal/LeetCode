//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<int> PosNegPair(int a[], int n) {
        
     vector<int>v,ans;
     map<int,int>mp;
     
     for(int i=0;i<n;i++){
         if(a[i]<0){
             v.push_back(a[i]);
         }else {
             mp[a[i]]++;
         }
     }
     
     sort(v.begin(), v.end());
     
     for(int i= (int)v.size()-1; i>=0;i--){
         int temp =  abs(v[i]);
         if(mp[temp]>0){
             
             ans.push_back(v[i]);
             ans.push_back(temp);
             mp[temp]-=1;
         }
     }
      
        return ans;
      
      
        /*
        bool hash_table[n+1][2];
        
        for(int i=0;i<=n;i++){
            if(a[i]>=0){
                hash_table[a[i]][0] = 1;
            }else{
                hash_table[abs(a[i])][1]=1;
            }
        }
    }
    
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(hash_table[a[i]][0]==1 && hash_table[abs(a[i])][1]==1){
            ans.push_back(a[i]);
            int temp = - (a[i]);
            ans.push_back(temp);
        }
        
        return ans; */
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> v = obj.PosNegPair(a, n);

        if (v.size() == 0) cout << "0";

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends