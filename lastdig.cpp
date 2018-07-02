#include <bits/stdc++.h>
using namespace std;

int n,a,b;
vector<int>v[10];
int main()
{
    v[0] = {0};
    v[1] = {1};
    v[2] = {2,4,8,6};
    v[3] = {3,9,7,1};
    v[4] = {4,6};
    v[5] = {5};
    v[6] = {6};
    v[7] = {7,9,3,1};
    v[8] = {8,4,2,6};
    v[9] = {9,1};
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(b==0)printf("1\n");
        else printf("%d\n",v[a%10][(b-1)%(v[a%10].size())]);
    }
    return 0;
}
