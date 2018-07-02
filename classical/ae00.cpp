#include <bits/stdc++.h>
using namespace std;

int n,cnt;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
