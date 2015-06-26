#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define ll_ long long unsigned

int main(){
	ll_ n, m;
	scanf("%llu %llu", &n, &m);
	ll_ d;
	int MIN, MAX;
	
	vector<ll_> A(n + 1); 
	for(int i = 1; i <= n; i++){
		scanf("%llu", &A[i]);
	}
	
	int start = 1, end = 1;
	ll_ total = A[1];
	cout<< n << " "<< m<< endl;
	
	while(end <= n || total > m){
		if(start == 1 && end == 1 && total > m){	
			printf("0\n");
			break;
		}
		end += 1;
		total += A[end];
		cout<< total << endl;
		if(total > m){
			while(total > m){
				total -= A[start];
				cout<< "While: "<< total<<endl;
				start++;
			}
		}
	
	}
	printf("%llu\n", total);	
}
