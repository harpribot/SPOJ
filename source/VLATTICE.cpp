#include<iostream>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll_ long long unsigned

ll_ a[1000000];
ll_ count = 1;

ll_ vLattice(ll_ n){
	// T[1] init
	a[1] = 7;
	a[0] = 0;
	if(a[n] != 0) return a[n];
	for(ll_ i = count + 1; i <= n; i++){
		a[i] = a[i - 1] + (i + 1)*(i + 1)*(i + 1)  - i * i * i;
		
		for(ll_ j = 1; j * j <= i; j++){
			if(i % j == 0){
				if(j != i/j){
					if(j == 1)
						a[i] -= a[1];
					else
						a[i] -=(a[j] - a[j - 1] + a[i/j] - a[i/j - 1]);
				}
				else
					a[i] -= (a[j] - a[j - 1]);
			}	
		}
	
	}
	count = n;
	return a[n];
}

int main(int argc, char** argv){
	int iter;
	ll_ n;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%llu", &n);
		printf("%llu\n", vLattice(n));
	}
}
