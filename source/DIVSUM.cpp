#include<iostream>
#include<stdio.h>

using namespace std;

long long divsum(long long a){
	
	long long sum = 0;
	for(long i = 2; i * i <= a; i++){
		if(a % i == 0)
			if(i != a/i)
				sum += ( i + a/i);
			else
				sum += i;
	}
	return (a > 1 ? sum + 1: sum);
}

int main(int argc, char** argv){
	long iter;
	long long number; 
	scanf("%ld", &iter);
	
	for(long long i = 0; i < iter; i ++){
		scanf("%lld", &number);
		printf("%lld\n" ,divsum(number));
	}
}
