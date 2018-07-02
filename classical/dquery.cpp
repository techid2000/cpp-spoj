#include <bits/stdc++.h>
using namespace std;

int block;

struct query {
    int x,y,order,answer;
    bool operator < (const query &o)const {
        if(x/block == o.x/block) {
            return y < o.y;
        }
        return x/block < o.x/block;
    }
};

int n;
int a[300005];

int bucket[1000005];
int distinct,cx,cy;

int q;

query prepare;
vector<query>queries;

int orderSort(query a, query b) {
    return a.order < b.order;
}

int main()
{
    scanf("%d",&n);
    block = sqrt(n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        scanf("%d %d",&prepare.x,&prepare.y);
        prepare.order = i;
        queries.push_back(prepare);
    }
    sort(queries.begin(),queries.end());
    for(int i=0;i<q;i++) {
        while(cy < queries[i].y) {
            cy++;
            if(bucket[a[cy]]==0) {
                distinct++;
            }
            bucket[a[cy]]++;
        }
        while(cy > queries[i].y) {
            bucket[a[cy]]--;
            if(bucket[a[cy]]==0) {
                distinct--;
            }
            cy--;
        }
        while(cx < queries[i].x) {
            if(cx > 0) {
                bucket[a[cx]]--;
                if(bucket[a[cx]]==0) {
                    distinct--;
                }
            }
            cx++;
        }
        while(cx > queries[i].x) {
            cx--;
            if(bucket[a[cx]]==0) {
                distinct++;
            }
            bucket[a[cx]]++;
        }
        queries[i].answer = distinct;
    }
    sort(queries.begin(),queries.end(),orderSort);
    for(int i=0; i<q; i++) {
        printf("%d\n",queries[i].answer);
    }
    return 0;
}
