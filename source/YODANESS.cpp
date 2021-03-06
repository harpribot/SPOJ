#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<map>

using namespace std;

class InversionCount{
	
	private:
		long long numInv;
		
	public:
		
		InversionCount():numInv(0){
		}
		
		void merge(long long v[], long long lowPtr, long long highPtr, long long upperBound, long long a[]){
			long long j = 0;
			long long lowerBound = lowPtr;
			long long mid = highPtr - 1;
			long long n = upperBound - lowerBound + 1;
			
			while(lowPtr <= mid && highPtr <= upperBound){
				if(v[lowPtr] <= v[highPtr]){
					a[j++] = v[lowPtr++];
				}
				else{
					a[j++] = v[highPtr++];
					numInv += (mid - lowPtr + 1);  // this counts total number of inverted pair, i.e those out of order
				}
			}	
			
			while(lowPtr <= mid){
				a[j++] = v[lowPtr++];
			}
			
			while(highPtr <= upperBound){
				a[j++] = v[highPtr++];
			}
			
			for(int i = 0; i < n; i++){
				v[lowerBound + i] = a[i];
			}
		} 
		
		void mergeSort(long long a[], long long lowerBound, long long higherBound, long long b[]){
			
			
			if(lowerBound == higherBound)
				return;
			else{
				long long mid = (lowerBound + higherBound)/2;
				mergeSort(a, lowerBound, mid, b);
				mergeSort(a, mid + 1, higherBound, b);
				merge(a, lowerBound, mid + 1, higherBound, b);
			}
			
		}
		
		long long getCountInv(){
			return numInv;
		}
		
};

int main(int argc, char** argv){
	long numCases;
	long long length;
	string data;
	map<string, long long> DATA;
	scanf("%ld", &numCases);
	
	while(numCases--){
		scanf("\n%lld",&length);
		long long a[length], b[length];
		InversionCount ic;
		for(long long i = 1; i <= length; i++){
			cin >> data;
			DATA[data] = i;
		}
		
		for(long long i = 1; i <= length; i++){
			cin>> data;
			a[i - 1] = DATA[data];
		}
		ic.mergeSort(a, 0 ,length - 1, b);
		printf("%lld\n",ic.getCountInv());
	}
}
