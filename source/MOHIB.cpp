#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int iter, avg,x, n, t, sum;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%d %d", &x , &avg);
		n = avg - x;
		sum = avg * (n + 1) - x;
		
		printf("%d\n", sum - (n * (n - 1))/2); // sum of all numbers - sum of (1,2,3,.....,n - 1)
	}
}
