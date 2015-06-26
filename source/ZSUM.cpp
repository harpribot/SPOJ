#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define llu_ long long unsigned
#define M 10000007

llu_ exp_(llu_ base, llu_ exp){
	
	llu_ result = 1;
	base = base % M;
	
	while(exp > 0){
		if(exp % 2 == 1)
			result = (result * base) % M; 
		
		exp = exp >> 1;
		base = (base * base) % M;
	}
	return result;
}


int main(){
	llu_ n, k;
	while(true){
		scanf("%llu %llu", &n, &k);
		if(n ==0 && k == 0) break;
		printf("%llu\n", (exp_(n, k) + 2 * exp_(n - 1, k) + 2 * exp_(n - 1, n - 1) + exp_(n,n)) % M);
	}
}
