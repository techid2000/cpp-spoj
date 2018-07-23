#include <bits/stdc++.h>
using namespace std;

int T,ni,nj,mi,mj;
int dir[8][2]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
int step[9][9][9][9];
char s1[3],s2[3];
queue<int>q;

inline int inbound(int i,int j) {
    return (i>=1 && i<=8 && j>=1 && j<=8);
}

int main()
{
    memset(step,-1,sizeof step);
    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            step[i][j][i][j]=0;
            q.push(i*10+j);
            while(!q.empty()) {
                ni=q.front()/10;
                nj=q.front()%10;
                q.pop();
                for(int k=0;k<8;k++) {
                    mi=ni+dir[k][0];
                    mj=nj+dir[k][1];
                    if(inbound(mi,mj) && step[i][j][mi][mj]==-1) {
                        step[i][j][mi][mj]=step[i][j][ni][nj]+1;
                        q.push(mi*10+mj);
                    }
                }
            }
        }
    }
    scanf("%d",&T);
    while(T--) {
        scanf(" %s %s",s1+1,s2+1);
        printf("%d\n",step[s1[2]-'0'][s1[1]-'a'+1][s2[2]-'0'][s2[1]-'a'+1]);
    }
    return 0;
}