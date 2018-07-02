#include <bits/stdc++.h>
using namespace std;

int t;

string s;

string plus_one(string x) {
    int l = x.size(),i;
    for(i = l-1; i>=0; i--) {
        x[i] = ((x[i]-'0'+1)%10) + '0';
        if(x[i] != '0') {
            return x;
        }
    }
    if(i < 0) {
        return "1" + x;
    }
}

bool greaterr(string a, string b) {
    int i=a.size(), k;
    for(k = 0; k < i; k++) {
        if(a[k]-'0' > b[k]-'0')
            return true;
        else if(a[k]-'0' < b[k]-'0')
            return false;
    }
    return false;
}

void next_palin(string x) {
    if(x == "9")  {
        cout << "11\n";
        return;
    }
    int l = x.size();
    int lhalf = l/2;
    string rev, ri, res;
    for(int i=0; i<x.size()/2; i++) {
        rev += x[x.size()/2 - i -1];
    }
    if(l % 2 == 0) {
        ri = x.substr(lhalf,lhalf);
        if(greaterr(rev, ri)) {
//            cout << "*" << rev << "*" << ri << "\n";
            cout << x.substr(0,lhalf) << rev;
        } else {
            res = plus_one(x.substr(0,lhalf));
            cout << res;
            if(res.size() > lhalf) {
                res = res.substr(0,res.size() - 1);
                reverse(res.begin(),res.end());
                cout << res;
            } else {
                reverse(res.begin(),res.end());
                cout << res;
            }
        }
    } else {
        ri = x.substr(lhalf+1, lhalf);
        if(greaterr(rev, ri)) {
            cout << x.substr(0,lhalf) << x[lhalf] << rev;
        } else {
            res = plus_one(x.substr(0,lhalf+1));
            cout << res;
            if(res.size() > lhalf+1) {
                res = res.substr(0, res.size()-2);
                reverse(res.begin(),res.end());
                cout << res;
            } else {
                res = res.substr(0,res.size()-1);
                reverse(res.begin(),res.end());
                cout << res;
            }
        }
    }
    cout << "\n";
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        next_palin(s);
    }
    return 0;
}
