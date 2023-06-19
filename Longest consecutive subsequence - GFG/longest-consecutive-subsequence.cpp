//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      
      sort(arr , arr+N);
      int longest=1;
      int cnt_curr = 0;
      int last_sm = INT_MIN;
      
      for(int i=0;i<N;i++){
          if(arr[i] -1 == last_sm){
              cnt_curr++;
              last_sm = arr[i];
          }else if(last_sm != arr[i])  {
              cnt_curr =1;
              last_sm = arr[i];
              
              
          }
          longest = max(longest, cnt_curr);
          
      }
      
      return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends