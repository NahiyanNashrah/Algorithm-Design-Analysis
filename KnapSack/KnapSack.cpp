#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a > b)? a : b;
}

int knapSack(int weight[],int value[],int capacity,int n)
{
    int dp[n+1][capacity+1];
    int k;

    for(int i = 0; i <= n; i++)
    {
        k = i-1;
        for(int j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[k] <= j)
                dp[i][j] = max(value[k] + dp[k][j-weight[k]], dp[k][j]);
            else
                dp[i][j] = dp[k][j];

        }
    }
    return dp[n][capacity];
}

int main()
{
    int capacity,number;
    printf("Item number ");
    scanf("%d",&number);
    printf("Capacity ");
    scanf("%d",&capacity);
    int value[number],weight[number];

    for(int i = 0; i < number; i++)
        scanf("%d",&weight[i]);

    for(int i = 0; i < number; i++)
        scanf("%d",&value[i]);

    printf("%d",knapSack(weight,value,capacity,number));
    return 0;

}
