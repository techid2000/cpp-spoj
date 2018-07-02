#include <bits/stdc++.h>
#define mod ((long long)(1e9+7))
using namespace std;

int n,a,b;
long long mt[3][3],mt1[3][3],mt2[3][3],mt3[3][1],mt4[3][1],ans;

void recur(int x) {
    if(x==1) return;
    recur(x/2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mt1[i][j]=0;
            for(int k=0;k<3;k++){
                mt1[i][j]+=mt[i][k]*mt[k][j];
                mt1[i][j]%=mod;
            }
        }
    }
    if(x%2==1){
        mt[0][0]=2,mt[0][1]=0,mt[0][2]=-1;
        mt[1][0]=1,mt[1][1]=0,mt[1][2]=0;
        mt[2][0]=0,mt[2][1]=1,mt[2][2]=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mt2[i][j]=0;
                for(int k=0;k<3;k++){
                    mt2[i][j]+=mt1[i][k]*mt[k][j];
                    mt2[i][j]%=mod;
                }
            }
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                mt[i][j]=mt2[i][j];
    } else {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                mt[i][j]=mt1[i][j];
    }
}

long long ask(int x) {
    if(x<=0){
        return 0;
    }
    mt[0][0]=2,mt[0][1]=0,mt[0][2]=-1;
    mt[1][0]=1,mt[1][1]=0,mt[1][2]=0;
    mt[2][0]=0,mt[2][1]=1,mt[2][2]=0;
    mt3[0][0]=2,mt3[1][0]=1,mt3[2][0]=0;
    recur(x);
    for(int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            mt4[i][j]=0;
            for(int k=0;k<3;k++){
                mt4[i][j]+=mt[i][k]*mt3[k][j];
                mt4[i][j]%=mod;
            }
        }
    }
    return mt4[2][0];
}


int main() {
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        ans = (ask(b)-ask(a-1))%mod;
        while(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
