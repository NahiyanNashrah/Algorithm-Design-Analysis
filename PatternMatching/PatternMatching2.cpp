#include<bits/stdc++.h>
using namespace std;
#define No_Of_Chars 256

void buildTransitionTable(char *pat, int M, int TF[][No_Of_Chars])
{
    int i, tracker = 0,x;

     for(x = 0; x<No_Of_Chars; x++)
        TF[0][x] = 0;
     TF[0][pat[0]] = 1;

     for(i = 1; i <= M; i++)
     {
         for(x = 0; x < No_Of_Chars; x++)
            TF[i][x] = TF[tracker][x];

            TF[i][pat[i]] = i+1;

            if(i < M)
                tracker = TF[tracker][pat[i]];
    }
}

void searchUsingPatternMatching2(char *pat,char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M+1][No_Of_Chars];

    buildTransitionTable(pat,M,TF);

    int i,j=0;
    for(i=0;i<N;i++)
    {
        j = TF[j][txt[i]];
        if(j == M)
            printf("Pattern found at index %d\n",i-M+1);
    }
}

int main()
{
    char *txt = "worHello world";
    char *pat ="wor";
    searchUsingPatternMatching2(pat,txt);
    return 0;
}
