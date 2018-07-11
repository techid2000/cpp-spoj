#include <bits/stdc++.h>
using namespace std;

int len,m,c;
string n,n2,ans;

int main() {
    while(cin >> n) {
        if(n=="1") {cout << "1\n"; continue;}
        reverse(n.begin(),n.end());
        n2 = "";
        len = n.size();
        for(int i=0; i<len; i++) {
            m = (n[i]-'0')*2 + c;
            n2 += (m % 10) + '0';
            c = m / 10;
        }
        while(c > 0) {
            n2 += (c % 10) + '0';
            c /= 10;
        }
        ans = "";
        len = n2.size();
        for(int i=0; i<len; i++) {
            m = (n2[i]-'0') - c;
            c = 0;
            if(i==0) {
                if(m < 2) {
                    m += 10, c = 1;
                }
            } else {
                if(m < 0) {
                    m += 10, c = 1;
                }
            }
            ans += (m - (i==0 ? 2:0)) + '0';
        }
        reverse(ans.begin(), ans.end());
        len = ans.size();
        m = 0;
        for(int i=0; i<len; i++) {
            m += ans[i] - '0';
            if(m > 0)
                cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}