// C++ program to print next
//greater number of Q queries
#include <bits/stdc++.h>
using namespace std;
 
// Function to print next greater
// of Q query
void next_greater(int arr[],int query[], int n,int q)
{
    //Loop for traversing each query
    for(int i=0;i<q;i++){
   //Take every query one by one
   int k=query[i];
   //To detect next greater element is present or not
   bool val=false;
   //Loop for checking next greater of each query
   for(int j=k+1;j<n;j++){
       if(arr[j]>arr[k]){
           cout<<arr[j]<<" ";
           //Make val true when there exist a next greater element
           val=true;
           break;
       }
   }
    
   //If next greater element is not present
   if(val==false){
      cout<<-1<<" ";    
   }
}
}
 
 
// Driver Code
int main()
{
//Given Numbers
int arr[] = {3, 4, 2, 7,5, 8, 10, 6 };
//Queries
int query[]={3,6,1};
 
int n = sizeof(arr) / sizeof(arr[0]);
      
int q= sizeof(query) / sizeof(query[0]);
    
next_greater(arr,query,n,q);
 
}
