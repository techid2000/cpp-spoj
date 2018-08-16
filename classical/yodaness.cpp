#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
string s;
int tc,ans;
int w;
string words[30005];
int a[30005];
int fw[30005];
void add(int i) {
    while(i<30005) {
        fw[i]++;
        i+=(i&(-i));
    }
}
int query(int i) {
    int s=0;
    while(i>0){
        s+=fw[i];
        i-=(i&(-i));
    }
    return s;
}
int main() {
    cin >> tc;
    while(tc--){
        m.clear();
        memset(fw,0,sizeof fw);
        cin >> w;
        for(int i=1;i<=w;i++) 
            cin>>words[i];
        for(int i=1;i<=w;i++) {
            cin >> s;
            m[s]=i;   
        }
        for(int i=1;i<=w;i++) 
            a[i]=m[words[i]];
        ans=0;
        for(int i=1;i<=w;i++) {
            ans+=query(30000)-query(a[i]);
            add(a[i]);
        }
        printf("%d\n",ans);
    }
}