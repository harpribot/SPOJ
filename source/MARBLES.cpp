#include<iostream>
#include<stdio.h>

using namespace std;

#define ll_ long long int


// a1 + a2 + a3 + ...... ak = n   where ai >= 1 is (n - 1)C(k - 1) , here C is the combination operator
// as (a1 - 1) + (a2 - 1) + ....... ak - 1 = n - k  so (n - k + k - 1)C(k - 1) 
// if ai >= 0 then answer would have been (n + k - 1)C(k - 1) 
long long C(ll_ n, ll_ m){
    if(m>n-m) m=n-m;
    
    long long ans=1;
    
    for(ll_ i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    
    return ans;
}

int main(){
	int iter;
	ll_ n, k;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld %lld", &n, &k);
		printf("%lld\n", C(n - 1,k - 1));
	}
}
