#include <bits/stdc++.h>
using namespace std;

string mul(string s1, string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    vector<string>adder(s2.size());
    int m,c;
    for(int i=0;i<s2.size();i++){
        for(int j=0;j<i;j++)adder[i]+='0';
        c=0;
        for(int j=0;j<s1.size();j++){
            m=c+(s2[i]-'0')*(s1[j]-'0');
            adder[i]+=(m%10)+'0';
            c=m/10;
        }
        if(c>0) adder[i]+=c+'0';
    }
    string result;
    c=0;
    for(int i=0;i<adder.back().size();i++){
        m=c;
        for(int j=0;j<adder.size();j++){
            if(i>=adder[j].size())continue;
            m+=adder[j][i]-'0';
        }
        result+=(m%10)+'0';
        c=m/10;
    }
    if(c>0)
        result+=c+'0';
    reverse(result.begin(),result.end());
    return result;
}
string prep[105];
string tostr(int x){
    if(x==0)return "";
    return tostr(x/10)+(char)(x%10+'0');
}
int t,n;
int main()
{
    prep[1]="1";
    for(int i=2;i<=100;i++){
        prep[i]=mul(prep[i-1],tostr(i));
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout << prep[n] << '\n';
    }
    return 0;
}
