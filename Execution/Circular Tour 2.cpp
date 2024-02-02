// find circular tour for a truck
#include <bits/stdc++.h>
using namespace std;
// A petrol pump has petrol and distance to next petrol pump
class petrolPump {
public:
    int petrol;
    int distance;
};
// The function returns starting point if there is a possible solution, otherwise returns -1
int printTour(petrolPump p[], int n)
{
    // storing the difference between petrol and distance
       vector<int> v;
       for(int i=0;i<n;i++)
       {
           v.push_back(p[i].petrol-p[i].distance);
       }
        
       // pref array will store the difference of petrol and distance till the i'th position
       vector<int> pref(n);
       pref[0]=v[0];
       for(int i=0;i<n;i++)
       {
           pref[i]=pref[i-1]+v[i];
       }
       // suff array will store the difference of petrol and distance till the i'th position from the end
        
       vector<int> suff(n);
       suff[n-1]=v[n-1];
       for(int i=n-2;i>=0;i--)
       {
           suff[i]=suff[i+1]+v[i];
       }
        
        int flag=0;
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
           // when the pref array will become 0 first time then we will store the next index of it
           // if the pref of i'th pos minus pref of last index where pref array became negative is less than 0 then we will update the ans
            
           if((ans==-1 && pref[i]<0) || (ans!=-1 && pref[i]-pref[ans-1]<0))
           {
                ans=i+1;
           }
       }
       // no index in pref array is less than 0
       if(ans==-1)
       {
           return 0;
       }
       // if at i'th position pref array become 0
       else if(ans<n)
       {
           if(pref[ans-1]+suff[ans]>=0)
           {
               return ans;
           }
       }
       // if at n'th position pref array become 0
       else if(ans==n)
       {
           if(suff[ans-1]+pref[ans-2]>=0)
           {
               return n-1;
           }
       }
       // if no index is picked as starting point
       return -1;
}
int main() 
{
    petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
  
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);
  
    (start == -1) ? cout << "No solution"
                  : cout << "Start = " << start;
  
    return 0;
}
