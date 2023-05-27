//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    
  
    char getMaxOccuringChar(string str)
    {
        int maxi =-1;
        int n= str.length();
        
        int arr[26] = {0};
        
        for(int i=0;i<n;i++){
            char ch = str[i];
            int num =0;
            if(ch >= 'a' && ch <='z'){
                num = ch - 'a';
                
            }else if(str[i] >= 'A' && str[i] <='Z' ){
                num = ch - 'A';
                
                
            }
            arr[num]++;
        }
        
        
        int ans = 0;
        
        for(int i=0;i<26;i++){
            if(maxi < arr[i]){
                ans =i;
                maxi = arr[i];
            }
            
        }
        
        char finala = ans + 'a';
        return finala;
        
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends