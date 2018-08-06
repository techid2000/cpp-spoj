#include <bits/stdc++.h>
using namespace std;

int sum,h,v;
int m,n;
int T;
priority_queue<int>q1,q2;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&m,&n);
        for(int i=1; i<m; i++) {
            scanf("%d",&h);
            q1.push(h);
        }
        for(int i=1; i<n; i++) {
            scanf("%d",&h);
            q2.push(h);
        }
        h=v=1;
        sum = 0;
        while(!q1.empty()&&!q2.empty()) {
            if(q1.top()>q2.top()) {
                sum += q1.top()*v;
                h++;
                q1.pop();
            } else {
                sum += q2.top()*h;
                v++;
                q2.pop();
            }
        }
        while(!q1.empty()) {sum += q1.top()*v; q1.pop();}
        while(!q2.empty()) {sum += q2.top()*h; q2.pop();}
        printf("%d\n",sum);
    }
}