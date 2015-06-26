#include<iostream>
#include<stdio.h>

int main(){
	int iter;
	scanf("%d", &iter);
	int count = 0;
	while(iter--){
		long long r;
		count++;
		scanf("%lld", &r);
		printf("Case %d: %0.2f\n",count, 4 * r * r + 0.25 );
	}
}
