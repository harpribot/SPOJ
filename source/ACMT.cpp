#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<math.h>

using namespace std;
# define l_ long long unsigned

int main(int argc, char** argv){
	int iter;
	l_ E, N;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld %lld", &E, &N);
		if(N > E)
			printf("%lld\n", (E + (N > 2*E ? 2*E:N))/3);
		else
			printf("%lld\n", (N + (E > 2*N ? 2*N:E))/3);
	}
	
}
