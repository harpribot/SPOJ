#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef long long ll_;
#define R 1000000000

int k;

ll_* multiply(ll_ *F, ll_ *M);
ll_* power(ll_ *F, ll_ n, ll_ *c);

ll_ mod(ll_ x) {
    ll_ r = x % R;
    return r<0 ? r+R : r;
}

ll_ MatSEQ(ll_ n, ll_ *a, ll_ *c){
	if(n <= 0) return *(a + n + k);
	
	ll_*F = (ll_*)calloc(k * k ,sizeof(ll_));
	
	for(int i = 0; i < k; i++){
		*(F + i) = *( c + i + 1);
	}
	for(int i = 1; i < k; i++){
		*(F + i * k + i - 1) = 1;
	}
	
	F = power(F, n, c);
	ll_ result = 0;
	
	/*for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			cout<<*(F + i * k + j)<<" ";
		}
		cout<<endl;
	}*/
	for(ll_ i = 0; i < k; i++){
		result += mod(*(a + k - i) * (*(F + i)));
	}
	delete F;
	return result;
}

int main(){
	
	int iter;
	scanf("%d", &iter);
	
	for(int i = 0; i < iter; i++){
		scanf("%d",&k);
		ll_ *a = (ll_*)calloc((k + 1) ,sizeof(ll_));
		ll_ *c = (ll_*)calloc((k + 1) , sizeof(ll_)); 
		
		for(int i = 1; i <= k; i++){
			scanf("%lld", a + i );
		}
		
		for(int i = 1; i <= k; i++){
			scanf("%lld", c + i);
		}
		
		ll_ n;
		scanf("%lld", &n);
		printf("%lld\n",mod(MatSEQ(n - k, a, c)));
		
		delete a;
		delete c;
	}
	return 0;
}

ll_* power(ll_ *F, ll_ n, ll_ *c){
	if(n == 0 || n == 1)
		return F;
	ll_* M = (ll_*)calloc(k * k , sizeof(ll_));
	
	for(int i = 0; i < k; i++){
		*(M + i) = *(c + i + 1);
	}
	for(int i = 1; i < k; i++){
		*(M + i * k + i - 1) = 1;
	}
	F = power(F,n/2,c);
	F = multiply(F,F);
	
	if(n%2 == 1)
		F = multiply(F, M);
	delete M;
	return F;
}

ll_* multiply(ll_ *F, ll_ *M){
	ll_ *temp = (ll_*)calloc(k * k ,sizeof(ll_));
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			for(int r = 0; r < k; r++){
				*(temp + i * k + j) = mod(*(temp + i * k + j) + (*(F + i * k + r) * (*(M + r * k + j))));
			}
		}
	}
	return temp;
}
