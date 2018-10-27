#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={10,20,30,1,29,40,30,5,1};
    int temp_max;
    int temp_index;

    int n = sizeof(arr)/sizeof(arr[0]);
    int lis_arr[n];
    int lis[n];
    for(int i = 0;i<n;i++)
        lis[i] =1;
    int maxValue = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j] && lis[j]+1 > lis[i])
                   {
                        lis[i] = lis[j]+1;
                        if(maxValue < lis[i]){
                            maxValue = lis[i];
                             temp_max = maxValue;
                             temp_index = i;
                        }
                   }

        }
       for(int i=temp_index;i>=0;i--)
       {
           if(temp_max == lis[i])
           {
               int temp =0;
               for(int j = i-1 ;j>0 ;j--){
                if(temp_max == lis[j]){
                  temp = j;

                }
               }
               if(temp==0)
                lis_arr[temp_max] = arr[i];
               else

                lis_arr[temp_max] = arr[temp];
               temp_max -- ;
           }
       }

       for(int j = 1 ; j<=maxValue; j++)
        cout<<lis_arr[j]<<" ";
       cout<<endl;


        cout<<"Length of LIS: "<<maxValue<<endl;

    return 0;
}
