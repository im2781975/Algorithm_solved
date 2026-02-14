// find circular tour for a truck 
#include <bits/stdc++.h>
using namespace std; 
// A petrol pump has petrol and distance to next petrol pump 
class petrolPump 
{
    public:
    int petrol; 
    int distance; 
}; 
 
// The function returns starting point if there is a possible solution, otherwise returns -1 
int printTour(petrolPump arr[], int n) 
{ 
    // Consider first petrol pump as a starting point 
    int start = 0; 
    int end = 1; 
 
    int curr_petrol = arr[start].petrol - arr[start].distance; 
 
    //Run a loop while all petrol pumps are not visited. And we have reached first petrol pump again with 0 or more petrol 
    while (end != start || curr_petrol < 0) 
    { 
        // If current amount of petrol in truck becomes less than 0, then remove the starting petrol pump from tour 
        while (curr_petrol < 0 && start != end) 
        { 
            // Remove starting petrol pump. Change start 
            curr_petrol -= arr[start].petrol - arr[start].distance; 
            start = (start + 1) % n; 
 
            // If 0 is being considered as start again, then there is no possible solution 
            if (start == 0) 
            return -1; 
        } 
        // Add a petrol pump to current tour 
        curr_petrol += arr[end].petrol - arr[end].distance; 
 
        end = (end + 1) % n; 
    } 
    // Return starting point 
    return start; 
}
int main() 
{ 
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}}; 
 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int start = printTour(arr, n); 
 
    (start == -1)? cout<<"No solution": cout<<"Start = "<<start; 
 
    return 0; 
} 
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
int printTour(petrolPump arr[], int n)
{
    int start;
 
    for (int i = 0; i < n; i++) {
        // Identify the first petrol pump from where we might get a full circular tour
        if (arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }
    // To store the excess petrol
    int curr_petrol = 0;
    int i;
    for (i = start; i < n;) {
 
        curr_petrol += (arr[i].petrol - arr[i].distance);
 
        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from current start
        if (curr_petrol < 0) {
            // We move to the next petrol pump
            i++;
            // We try to identify the next petrol pump from where we might get a full circular tour
            for (; i < n; i++) {
                if (arr[i].petrol >= arr[i].distance) {
 
                    start = i;
                    // Reset rem_petrol
                    curr_petrol = 0;
                    break;
                }
            }
        }
        else {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }
    // If remaining petrol is less than 0 while we reach the first petrol pump, it means no circular tour is possible
    if (curr_petrol < 0) {
        return -1;
    }
    for (int j = 0; j < start; j++) {
 
        curr_petrol += (arr[j].petrol - arr[j].distance);
        // If remaining petrol is less than 0 at any point before we reach initial start, it means no circular tour is possible
        if (curr_petrol < 0) {
            return -1;
        }
    }
    // If we have successfully reached intial_start, it means can get a circular tour from final_start, hence return it
    return start;
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
    // deficit is used to store the value of the capacity as soon as the value of capacity becomes negative so as
    // not to traverse the array twice in order to get the solution
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++) {
        capacity += p[i].petrol - p[i].distance;
        if (capacity < 0) {
            // If this particular step is not done then the between steps would be redundant
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
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
