#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int lastDigit(int base, long long exp){
	
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


int main(int argc, char** argv){
	int iter;
	scanf("%d", &iter);
	int base;
	long long  exp;
	string s;
	for(int i = 0; i < iter; i++){
		cin >> s;
		scanf("%lld", &exp);
		base = s[s.size() - 1] - '0'; // extract the last element of the base string
		printf("%d\n", lastDigit(base,exp));
	}
}
