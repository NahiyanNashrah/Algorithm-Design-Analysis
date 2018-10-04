#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[],int n,int V)
{
    int table[V+1];
    table[0] = 0;
    int i = 0,j = 0;

    for(int i = 1; i <= V; i++)
        table[i] = 999999;

    for(i = 1; i<= V; i++)
    {
        for(j = 0; j < n; j++)
            if(coins[j] <= i)
        {
           int sub_res = table[i-coins[j]];
        if(sub_res != 999999 && sub_res+1 <table[i])
            table[i] = sub_res+1;
        }
    }
    return table[V];
}

int main()
{
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int V = 8;
    printf("Minimum number of coins %d\n",minCoins(coins,n,V));
    return 0;
}

