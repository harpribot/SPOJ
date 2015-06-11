#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int iter,divisor,dividend, counter = 0;
	scanf("%d %d",&iter, &divisor);
	
	for(int i = 0; i < iter; i++){
		scanf("%d", &dividend);
		if(dividend % divisor == 0){
			counter++;
		}
	}
	printf("%d", counter);
}
