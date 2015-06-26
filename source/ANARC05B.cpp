#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int * A;
int * B;
int n, m;
typedef long long ll_;

ll_ sum1;
ll_ sum2;

ll_ helix(int i, int j){
	sum1 = 0;
	sum2 = 0;
	while(i <= n && j <= m){
		if(*(A + i) > *(B + j) && ){
			sum2 += *(B + j);
			j++;
		}
		else if(*(A + i) < *(B + j)){
			sum1+= *(A + i);
			i++;
		}
		else
			break;
	}
	
	
	ll_ presSum = max(sum1, sum2) + *(A + i);
	return presSum + helix(i + 1, j + 1);
	
}

int main(){
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		A = (int*)malloc( (n + 1) * sizeof(int));
		for(int i = 1; i <= n; i++)
			scanf("%d", A + i);
		scanf("%d", &m);
		B = (int*) malloc((m + 1) * sizeof(int));
		for(int i = 1; i <= m; i++)
			scanf("%d", B + i);
		
		
		printf("%lld\n", helix(1,1));
	}
}
