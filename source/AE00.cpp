#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

int main(){
	
	int n, counter = 0;
	scanf("%d", &n);
	
	while(n != 0){
		for(int i = 1; i <= sqrt(n); i++){
			if(n % i == 0){
				counter++;
			}
		}
		n--;
	}
	
	printf("%d\n", counter);
}

