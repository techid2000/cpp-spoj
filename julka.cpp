#include <bits/stdc++.h>
using namespace std;

char sa[200],sb[200];
int a[200],b[200],c[200],d[200],e[200],f[200],x,la,lb;

int main() {
    for(int tc=1;tc<=10;tc++){
        for(int i=0;i<200;i++)
            sa[i]=sb[i]='\0',
            a[i]=b[i]=c[i]=d[i]=e[i]=f[i]=0;
        x=la=lb=0;
        scanf(" %s",sa+1);
        scanf(" %s",sb+1);
        la=strlen(sa+1);
        lb=strlen(sb+1);
        for(int i=1;i<=la;i++)
            a[i+1]=sa[i]-'0';
        for(int i=1;i<=lb;i++)
            b[i+(la-lb)+1]=sb[i]-'0';

        for(int i=la+1;i>=1;i--) {
            c[i]+=a[i]+b[i];
            c[i-1]+=c[i]/10;
            c[i]%=10;
        }
        for(int i=la+1;i>=1;i--){
            if(a[i]<b[i]){
                a[i]+=10;
                a[i-1]-=1;
            }
            d[i]=a[i]-b[i];
        }
        for(int i=1;i<=la+1;i++){
            x+=c[i];
            if(x>=2){
                e[i]=x/2;
                x%=2;
            }
            x*=10;
        }
        x=0;
        for(int i=1;i<=la+1;i++){
            x+=d[i];
            if(x>=2){
                f[i]=x/2;
                x%=2;
            }
            x*=10;
        }
        x=0;
        for(int i=1;i<=la+1;i++){
            x+=e[i];
            if(x>0)
                printf("%d",e[i]);
        }
        if(x==0)printf("0");
        printf("\n");
        x=0;
        for(int i=1;i<=la+1;i++){
            x+=f[i];
            if(x>0)
                printf("%d",f[i]);
        }
        if(x==0)printf("0");
        printf("\n");
    }
}
