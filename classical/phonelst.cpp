#include <bits/stdc++.h>
using namespace std;

struct NUM {
    int len;
    char number[15];
    bool operator <(const NUM &o)const {
        for(int i=1; i<=len; i++) {
            if(number[i] < o.number[i]) return 1;
            if(number[i] > o.number[i]) return 0;
        }
        return 0;
    }
};

int n,y,yy,ok,tc;
NUM input;
vector<NUM>nums;
vector<NUM>prefix[15];

int main()
{
    scanf("%d",&tc);
    while(tc--) {
        nums.clear();
        for(int i=0;i<15;i++)
            prefix[i].clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf(" %s",input.number+1);
            input.len = strlen(input.number+1);
            nums.push_back(input);
            for(int j=input.len; j>=1; j--) {
                prefix[j].push_back(input);
                input.number[j] = '\0';
                input.len--;
            }
        }
        for(int i=1;i<=10;i++) {
            sort(prefix[i].begin(),prefix[i].end());
        }
        ok = 1;
        for(int i=0;i<n;i++) {
            y = lower_bound(prefix[nums[i].len].begin(),prefix[nums[i].len].end(),nums[i]) -
            prefix[nums[i].len].begin();
            yy = upper_bound(prefix[nums[i].len].begin(),prefix[nums[i].len].end(),nums[i]) -
            prefix[nums[i].len].begin();
            if(yy - y > 1) {
                printf("NO\n");
                ok = 0;
                break;
            }
        }
        if(ok) printf("YES\n");
    }
    return 0;
}
