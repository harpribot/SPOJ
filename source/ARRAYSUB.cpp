#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

long long findMax(long long a[], long long i, long long j){
	
	long long max = 0;
	for(long long r = i; r <= j; r++){
		if(a[r] > max) max = a[r];
	}	
	
	return max;
}

int main(int argc, char** argv){
	
	long long length, data, k;
	scanf("%lld", &length);
	long long a[length];
	for(long long i = 0; i < length; i++){
		scanf("%lld", &data);
		a[i] = data;
	}
	scanf("%lld", &k);
	
	long long i = 0, j = k - 1;
	long long max = findMax(a,i,j);
	
	while(j < length){
		printf("%lld ", max);
		i++; j++;
		if(a[i - 1] == max){
			max = findMax(a,i,j);
		}
		else{
			if(a[j] > max) max = a[j];
		}
	}
}
