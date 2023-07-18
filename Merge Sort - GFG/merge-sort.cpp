//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // now we will create two array
         
         int len1 = m - l+1;
         int len2 = r-m;
         
         int *first = new int[len1];
         int *second = new int[len2];
         
         // now cpoying values
         int k =l;
         
         for(int i=0;i<len1;i++){
             first[i] = arr[k];
             
             k++;
         }
         
         k = m+1;
         for(int i=0;i<len2;i++){
             second[i] = arr[k];
             
             k++;
         }
         
         // now we will merge two arrays
         int index1 = 0;
         int index2 = 0;
         k = l;
         
         while(index1 < len1 && index2 < len2){
             if(first[index1] < second[index2]){
                 arr[k++] = first[index1++];
             }else{
                 arr[k++] = second[index2++];
             }
         }
         
         while(index1 < len1){
             arr[k++] = first[index1++];
         }
         
         while(index2 < len2){
             arr[k++] = second[index2++];
         }
         
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        int mid = l+ (r-l)/2;
        
        // base case
        if(l>=r){
            return;
        }  
        
        // recrusive call to sort left part of array
        mergeSort(arr, l, mid);
        
        //recursive call to sort right part of array
        mergeSort(arr, mid+1, r);
        
        //merge
        merge(arr, l, mid, r);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends