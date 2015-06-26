#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>

using namespace std;

#define ll_ long long

map <int, int> hasher;

ll_ happyNum(ll_ num, ll_ count){
	if(num == 1 || num == 10 || num == 100 || num == 1000 || num == 10000 || num == 100000 || num == 1000000 || num == 10000000 || num == 100000000 || num == 1000000000)
		return count + 1;
	ll_ numNew = 0;
	while(num){
		int temp = num % 10;
		numNew += temp * temp;
		num = num / 10;
	}
	
	//printf("New Number : %lld\nPresent Count: %lld\n\n", numNew, count);
	if(hasher[numNew] != -numNew){
		hasher[numNew] = - numNew ;
		count++;
		return happyNum(numNew, count);
	}
	else{
		return -1;
	}
}

int main(){
	ll_ num;
	scanf("%lld", &num);
	printf("%lld\n", happyNum(num, 0));
}
