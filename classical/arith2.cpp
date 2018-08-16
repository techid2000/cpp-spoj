#include <bits/stdc++.h>
using namespace std;
int t,f;
long long num1,num2;
char op;
char s[1000005];
char* tk;
int main() {
    scanf("%d",&t);
    while(t--) {
        fgets(s,100005,stdin);
        if(s[0]=='\n'){
            t++;
            continue;
        }
        tk=strtok(s," ");
        num1=num2=f=0;
        while(tk!=NULL) {
            if(!isalnum(*tk)){
                op=*tk;
            } else {
                if(!f){
                    num1=atoll(tk);
                    f=1;
                } else {
                    num2=atoll(tk);
                    if(op=='+') num1=num1+num2*1LL;
                    if(op=='-') num1=num1-num2*1LL;
                    if(op=='*') num1=num1*num2*1LL;
                    if(op=='/') num1=num1/num2*1LL;
                } 
            }
            tk=strtok(NULL," ");
        }  
        printf("%lld\n",num1);
    }
    return 0;
}