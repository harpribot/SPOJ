#include<iostream>
#include<stdio.h>

using namespace std;


long long sumFib(long long a, long long b,int count, int n){
	
	if(count == n){
		return a;
	}
	long long c = a + b;
	return a + sumFib(b,c, count + 1,n);
}

int main(){
	
	int iter, n;
	scanf("%d", &iter);
	
	for(int i = 0; i < iter; i++){
		scanf("%d", &n);
		printf("%lld\n", sumFib(0,1,1,n));	
	}
	
}
