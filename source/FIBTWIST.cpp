#include<iostream>
#include<stdio.h>

using namespace std;

#define ll_ long long 

ll_ R = 20;

void multiply(ll_ F[2][2], ll_ M[2][2]);
void power(ll_ F[2][2], ll_ n);

ll_ mod(ll_ x, ll_ m) {
    ll_ r = x%m;
    return r<0 ? r+m : r;
}

ll_ Fibonacci(ll_ n){
	if(n == 0) return 0;
	
	ll_ F[2][2] = {{1, 1}, {1, 0}};
	
	power(F, n-1);
	
	return F[0][0];
}

int main(){
	
	int iter;
	ll_ n,m;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld %lld", &n, &m);
		R = m;
		printf("%lld\n",mod(2 * Fibonacci(n + 2) - n - 2, R));
		
	}
}

void power(ll_ F[2][2], ll_ n){
	if(n == 0 || n == 1)
		return;
	ll_ M[2][2] = {{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	
	if(n%2 == 1)
		multiply(F, M);
}

void multiply(ll_ F[2][2], ll_ M[2][2]){
	ll_ x =  mod(mod(F[0][0]*M[0][0],R) + mod(F[0][1]*M[1][0],R),R);
	ll_ y =  mod(mod(F[0][0]*M[0][1],R) + mod(F[0][1]*M[1][1],R),R);
	ll_ z =  mod(mod(F[1][0]*M[0][0],R) + mod(F[1][1]*M[1][0],R),R);
	ll_ w =  mod(mod(F[1][0]*M[0][1],R) + mod(F[1][1]*M[1][1],R),R);

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
