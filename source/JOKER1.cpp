#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
#define ll_ long long
void QuickSort(vector<ll_> &, ll_, ll_);
int Partition(vector<ll_> &, ll_, ll_);
//void display(vector<ll_> &);
void swap(ll_ &, ll_ &);


int main(){
	int iter;
	scanf("%d", &iter);
	int n;
	ll_ data;
	ll_ output;
	while(iter--){
		scanf("%d", &n);
		vector<ll_> A;
		for(int i = 0; i < n; i++){
			scanf("%lld", &data);
			A.push_back(data);
		}
		QuickSort(A,0,n-1);
		output = A[0];
		for(int i = 1; i < n; i++){
			output = (output * (A[i] - i))% 1000000007;
		}
		printf("%lld\n", output);
	}
	printf("KILL BATMAN\n");	
}

void QuickSort(vector<ll_> &A, ll_ p, ll_ r){
	if(p < r){
		ll_ q = Partition(A,p,r);
		QuickSort(A,p,q - 1);
		QuickSort(A,q + 1,r);
	}
}

int Partition(vector<ll_> &A, ll_ p, ll_ r){
	ll_ x = A[r];
	ll_ wall = p;
	
	for(ll_ i = p; i < r; i++){
		if(A[i] <= x){
			swap(A[wall], A[i]);
			wall++;
		}
	}
	swap(A[wall], A[r]);
	return wall;
}

void swap(ll_ &x, ll_ &y){
	ll_ temp = x;
	x = y;
	y = temp;
}


