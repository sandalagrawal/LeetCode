//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        vector<int> trav;
        int total = n*m;
        int count=0;
        int row_st =0, row_end = n-1;
        int col_st =0, col_end = m-1;
        
        while(count < total){
            for(int i = col_st; count < total && i<= col_end; i++){
                trav.push_back(a[row_st][i]);
                count++;
            }
            row_st++;
            
            for(int i = row_st; count < total && i<= row_end; i++){
                trav.push_back(a[i][col_end]);
                count++;
            }
            col_end--;
            
            for(int i = col_end; count < total && i>= col_st ; i--){
                trav.push_back(a[row_end][i]);
                count++;
            }
            row_end--;
            
            for(int i = row_end; count < total && i>= row_st; i--){
                trav.push_back(a[i][col_st]);
                count++;
            }
            col_st++;
        }
        
        int ans = trav[k-1];
        
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends