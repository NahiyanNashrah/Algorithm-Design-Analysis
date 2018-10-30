#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void patternMatching(char text[],char pattern[])
{
    int flag = 0,index=0;
    int len = strlen(text);
    int len1 =strlen(pattern);

    for(int i = 0; i < len-len1+1; i++)
    {
        if(text[i] == pattern[0])
        {
            flag=1;
            index=i;
            for(int j=i+1,k=1;k<len1;j++,k++)
            {
                if(text[j] != pattern[k])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
    }
    if(flag==1)
        cout<<"pattern matched at "<<index+1<<" index"<<endl;
    else
        cout<<"pattern don't match"<<endl;
}

int main()
{
    char text[100],pattern[50];
    cout<<"Enter a string ";
    gets(text);
    cout<<"Enter another string ";
    gets(pattern);
    patternMatching(text,pattern);;
    return 0;
}


