#include <bits/stdc++.h>
using namespace std;

int k,n;
queue<string>q;
string t;
int ismod() {
    int r=0;
    for(int i=0;i<t.size();i++) {
        r=r*10 + (t[i]-'0');
        r%=k;
    }
    return r;
}

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&k);
        while(!q.empty())q.pop();
        q.push("1");
        while(true) {
            t=q.front();
            q.pop();
            if(ismod()==0)break;
            q.push(t+"0");
            q.push(t+"1");
        }
        printf("%s\n",t.c_str());
    }
    return 0;
}
