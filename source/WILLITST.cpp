#include<stdio.h>

using namespace std;

int main(){
	long long unsigned a;
	scanf("%llu", &a);
	
	if((a & (a - 1)) == 0)
		printf("TAK");
	else
		printf("NIE");
}
