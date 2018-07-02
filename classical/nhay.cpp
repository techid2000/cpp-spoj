#include <bits/stdc++.h>
using namespace std;

char needle[1000100];
char haystack[1000100];
int n,len,j;
int prefix[1000100];

int main()
{
    while(scanf("%d",&n)!=EOF){
        scanf(" %s",needle+1);
        j=0;
        for(int i=2;i<=n;i++){
            while(j>0 && needle[j+1]!=needle[i])
                j=prefix[j];
            if(needle[j+1]==needle[i])
                j++;
            prefix[i]=j;
        }
        scanf(" %s",haystack+1);
        len=strlen(haystack+1);
        j=0;
        for(int i=1;i<=len;i++){
            while(j>0 && needle[j+1]!=haystack[i]){
                j=prefix[j];
            }
            if(needle[j+1]==haystack[i])j++;
            if(j==n) printf("%d\n",i-n);
        }
        printf("\n");
    }
    return 0;
}
