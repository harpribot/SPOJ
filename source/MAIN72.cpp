#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>

using namespace std;

int subsetSum (int n, int dataSum, vector<int> arr){
	if(dataSum == 0) return 0;
	
	bool * T = (bool*) malloc ((n + 1) * (dataSum + 1) * sizeof(bool));
	
	// T[0][j > 0]
	for(int j = 1; j <= dataSum; j++)
		*(T + j) = false;
	
	// T[i >= 0][0]
	for(int i = 0; i <= n; i++)
		*(T + i * (dataSum + 1)) = true;
	  
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= dataSum; j++){
			if(arr[i - 1] > j) 
				*(T + i * (dataSum + 1) + j) = *(T + (i - 1) * (dataSum + 1) + j);
			else
				*(T + i * (dataSum + 1) + j) = *(T + (i - 1) * (dataSum + 1) + j) || *(T + (i - 1) * (dataSum + 1) + (j - arr[i - 1]));
		}
	}
	
	int sum = 0;
	for(int j = 0; j <= dataSum; j++){
		if(*(T + n * (dataSum + 1) + j))
			sum+= j;
	}
	
	return sum;
}

int main(int argc, char** argv){
	
	int iter,n,dataSum = 0, val;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%d", &n);
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			dataSum += arr[i];
		}
		printf("%d\n", subsetSum(n, dataSum, arr));
	}
	
}
