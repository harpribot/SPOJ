#include<iostream>
#include<stdio.h>

using namespace std;

#define ll_ long long

ll_ numCards(ll_ n){
	if(n == 1) return 2;
	else
		return (n-1) + 2 * n + numCards(n - 1);
}

int main(int argc, char** argv){
	
	int iter;
	ll_ level;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld" , &level);
		printf("%lld\n", ((level * (level + 1) * 3 - (2 * level))/2) % 1000007);
	}
}
