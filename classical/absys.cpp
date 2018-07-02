#include <bits/stdc++.h>
using namespace std;

int tc,l1,l2,l3,da,db,c,ch;
int v1,v2,v3;
char c1,c2;
string n1,n2,n3;

int main() {
    cin >> tc;
    while(tc--) {
        ch=0;
        cin >> n1 >> c1 >> n2 >> c2 >> n3;
        l1=n1.size(),l2=n2.size(),l3=n3.size();
        for(int k=0;k<l3;k++){
            if(isalpha(n3[k])) {
                v1 = atoi(n1.c_str());
                v2 = atoi(n2.c_str());
                cout << n1 << " + " << n2 << " = " << v1+v2 << '\n';
                ch=1;
                break;
            }
        }
        if(ch)continue;
        ch=0;
        for(int k=0;k<l2;k++) {
            if(isalpha(n2[k])) {
                swap(n1,n2);
                ch=1;
                break;
            }
        }
        v2 = atoi(n2.c_str());
        v3 = atoi(n3.c_str());
        v1 = v3-v2;
        if(ch) {
            swap(v1,v2);
        }
        cout << v1 << " + " << v2 << " = " << v3 << "\n";
    }
}
