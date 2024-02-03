// generate binary numbers from 1 to n
#include <bits/stdc++.h>
using namespace std;
void generatePrintBinary(int n)
{
   for(int i=1;i<=n;i++){
       string str="";
       int temp=i;
       while(temp){
           if(temp&1){str=to_string(1)+str;}
           else{str=to_string(0)+str;}
            
           temp=temp>>1;
       }
       cout<<str<<endl;
   }
}
int main()
{
    int n = 10;
    generatePrintBinary(n);
    return 0;
}
