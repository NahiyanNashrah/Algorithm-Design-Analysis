#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={10,20,30,1,29,40,30,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
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
                        if(maxValue < lis[i])
                            maxValue = lis[i];
                   }
        }
        cout<<"Length of LIS: "<<maxValue<<endl;

    return 0;
}
