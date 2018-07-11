#include <iostream>
using namespace std;

int n,a[10005],sum,avg;

int main() {
	while(true) {
		cin >> n;
		if(n == -1) return 0;
		sum = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", a+i);
			sum += a[i];
		}
		if(sum % n != 0) {
			printf("-1\n");
		} else {
			avg = sum / n, sum = 0;
			for(int i=1; i<=n; i++) {
				sum += abs(a[i] - avg);
			}
			printf("%d\n",sum / 2);
		}
	}
	return 0;
}