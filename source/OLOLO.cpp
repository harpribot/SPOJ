#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char** argv){
	
	long iter;
	long long val;
	long long unique = 0;
	
	scanf("%ld", &iter);
	
	while(iter--){
		scanf("%lld", &val);
		unique = unique ^ val;
	}
	
	printf("%lld\n", unique);
}
