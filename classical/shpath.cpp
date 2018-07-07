#include <bits/stdc++.h>
using namespace std;

int tc,n,m,u,w,Q;
string name,name1;
map<string,int> convert;
vector<pair<int,int>>g[10050];
priority_queue<pair<int,int>>q;
int ch[10050];
int shpath() {
    int st = convert[name];
    int ed = convert[name1];

    memset(ch,0,sizeof(ch));
    while(!q.empty())q.pop();

    q.push({0,st});
    while(!q.empty()) {
        w=-q.top().first;
        u=q.top().second;
        q.pop();
        if(!ch[u]) {
            ch[u] = 1;
            if(u==ed){
                return w;
            }
            for(int i=0;i<g[u].size();i++) {
                if(!ch[g[u][i].first]) {
                    q.push({-(w + g[u][i].second), g[u][i].first});
                }
            }
        }
    }
}

int main()
{
    cin>>tc;
    while(tc--) {
        convert.clear();
        cin >> n;
        for(int i=1;i<=n;i++) {
            g[i].clear();
            cin >> name;
            convert[name] = i;
            cin >> m;
            while(m--) {
                cin>>u>>w;
                g[i].push_back({u,w});
            }
        }
        cin >> Q;
        while(Q--) {
            cin >> name >> name1;
            cout << shpath() << '\n';
        }
    }
    return 0;
}
