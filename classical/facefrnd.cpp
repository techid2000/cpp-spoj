#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s,t;
map<string,bool>have;
set<string>adj;
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        have[s]=true;
        cin>>m;
        for(int j=0;j<m;j++) {
            cin>>t;
            adj.insert(t);
        }
    }
    for(auto x : adj){
        if(!have[x]) {
            cnt++;
        }
    }
    cout<<cnt;
}