#include <bits/stdc++.h>
using namespace std;

long long in,def;
int n,a,b;
long long s;
vector <long long> num,abc;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&in);
        num.push_back(in);
    }
    for(int a=0;a<num.size();a++){
        for(int b=0;b<num.size();b++){
            for(int c=0;c<num.size();c++){
                abc.push_back(num[a]*num[b]+num[c]);
            }
        }
    }
    sort(abc.begin(),abc.end());
    for(int d=0;d<num.size();d++){
        if(num[d]==0) continue;
        for(int e=0;e<num.size();e++){
            for(int f=0;f<num.size();f++){
                def = num[d]*(num[e] +num[f]);
                a=lower_bound(abc.begin(),abc.end(),def)-abc.begin();
                b=upper_bound(abc.begin(),abc.end(),def)-abc.begin();
                s += b-a;
            }
        }
    }
    printf("%lld\n",s);
    return 0;
}
