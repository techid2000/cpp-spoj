#include <bits/stdc++.h>
using namespace std;

int n,c,m;
stack<int>s;

int main()
{
    while(true) {
        scanf("%d",&n);
        while(!s.empty())s.pop();
        if(n==0)return 0;
        c=1;
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            while(!s.empty()&&s.top()==c){
                c++;
                s.pop();
            }
            if(m==c){
                c++;
            } else {
                s.push(m);
            }
        }
        while(!s.empty()&&s.top()==c){
            c++;
            s.pop();
        }
        if(s.empty()){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
