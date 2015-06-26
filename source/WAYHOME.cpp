#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

long long wayHome(long long a[], long long n){
	
	if(n == 1) return a[0];
	if(n == 2) return a[1];
	if(n == 3) return (a[2] + a[1] + a[0]);
	
	long long retResult = wayHome(a, n - 2);
	long long sol1 = (a[0] + 2 * a[1] + a[n - 1] + retResult);
	long long sol2 = (2 * a[0] + a[n - 1] + a[n - 2]  + retResult);
	
	return min(sol1, sol2);
}


int main(int argc, char** argv){
	
	int iter;
	long long n;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld", &n);
		long long a[n];
		for(long long i = 0; i < n; i++){
			scanf("%lld", &a[i]);
		}
		printf("%lld\n", wayHome(a, n));
	}
}
