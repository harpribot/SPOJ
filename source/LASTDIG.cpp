#include<iostream>
#include<stdio.h>

using namespace std;

int onesDigitFast(int base, long long exp){
	
	int result = 1;
	base = base % 10;
	
	while(exp > 0){
		if(exp % 2 == 1)
			result = (result * base) % 10; 
		
		exp = exp >> 1;
		base = (base * base) % 10;
	}
	return result;
}

int onesDigit(int base, long long exp){
	int result = 1;
	
	for(int i = 0; i < exp; i++){
		result = (base * result) % 10;
	}
	
	return result;
}

int main(int argc, char** argv){
	int iter;
	scanf("%d", &iter);
	int base;
	long long exp;
	for(int i = 0; i < iter; i++){
		scanf("%d %lld", &base, &exp);
		printf("%d\n", onesDigitFast(base,exp));
		//printf("%d\n", onesDigit(base,exp));
	}
}
