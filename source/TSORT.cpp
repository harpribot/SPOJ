#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	// the algorithm used is Counting Sort
	// Quick sort was failing on TLE
	vector<long> a(1000002);
	vector<long> b(1000002);
	
	long nElems;
	scanf("%d",&nElems);
	
	for(long i = 0;i < nElems; i++){
		scanf("%d", &b[i]);
	}
		
	
	for(long i = 0; i < nElems; i++){
		a[b[i]]++;
	}
	
	for(long i = 0; i < 1000002; i++)
	{
		while(a[i]--){
			printf("%d\n",i);
		}
	} 
	
} 
