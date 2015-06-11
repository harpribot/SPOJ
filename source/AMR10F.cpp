#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int iter, n,a,d;
	
	scanf("%d", &iter);
	
	for(int i = 0; i < iter; i++){
		scanf("%d %d %d", &n, &a, &d);
		printf("%d\n", (n * (2*a + (n - 1) * d))/2);
		
	}
}
