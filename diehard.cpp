#include <bits/stdc++.h>
using namespace std;

int t;
int h,a,maxx;
int dp[2005][2005][3];

int mic(int _h,int _a,int s){
//    printf("%d %d %d\n",_h,_a,s);
    if(dp[_h][_a][s]!=-1)
        return dp[_h][_a][s];
    if(_h==0 || _a==0)
        return dp[_h][_a][s]=0;
    int maxx=0;
    if(s==0){
        maxx=max(maxx,mic(max(0,_h-5),max(0,_a-10),1)+1);
        maxx=max(maxx,mic(max(0,_h-20),max(0,_a+5),2)+1);
    }
    if(s==1){
        maxx=max(maxx,mic(max(0,_h+3),max(0,_a+2),0)+1);
        maxx=max(maxx,mic(max(0,_h-20),max(0,_a+5),2)+1);
    }
    if(s==2){
        maxx=max(maxx,mic(max(0,_h+3),max(0,_a+2),0)+1);
        maxx=max(maxx,mic(max(0,_h-5),max(0,_a-10),1)+1);
    }
    return dp[_h][_a][s]=maxx;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&h,&a);
        memset(dp,-1,sizeof dp);
        maxx=0;
        maxx=max(maxx,mic(h,a,0));
        maxx=max(maxx,mic(h,a,1));
        maxx=max(maxx,mic(h,a,2));
        printf("%d\n",maxx-1);
    }
    return 0;
}
