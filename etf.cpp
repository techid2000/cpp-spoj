#include <bits/stdc++.h>
using namespace std;

int d[1000005],n,a;

int main()
{
    for(int i=2;i<=1000000;i++) {
        int j;
        for(j=2;j<=sqrt(i);j++) {
            if(i%j==0){
                break;
            }
        }
        if(j>sqrt(i)){
            a++;
        }
    }
    printf("%d\n",a);
//    for(int i=1;i<=10;i++)
//        printf("%d : %d\n",i,i-(d[i]-1));
//    scanf("%d",&n);
//    while(n--) {
//        scanf("%d",&a);
//        printf("-%d\n",a-(d[a]-1));
//    }

    return 0;
}
