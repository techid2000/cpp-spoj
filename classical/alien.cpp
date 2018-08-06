#include <bits/stdc++.h>
using namespace std;

int T;
int a,b,sum,ma,n,j;
int arr[100005];

int main()
{
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&a,&b);
        for(int i=1; i<=a; i++) {
            scanf("%d",arr+i);
        }
        sum = j = ma = n = 0;
        for(int i=1; i<=a; i++) {
            if(i > j) {
                j = i;
                sum = arr[i];
            }
            while(j+1 <= a && sum+arr[j+1] <= b) {
                sum += arr[++j];
            }
            if(sum <= b) {
                if(j-i+1 > n) {
                    n = j-i+1;
                    ma = sum; 
                } else if(j-i+1 == n) {
                    ma = min(ma, sum);
                }
            }
            sum -= arr[i];
        }
        printf("%d %d\n",ma,n);
    }
    return 0;
}