#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

class BinaryIndexTree{
	
	private:
		vector<long> b;
		long N;
		
	public:
		BinaryIndexTree(long size): N(size){
			b.resize(size + 1);
		}
		
		long queryBIT(long loc){ // returns sum from 0 to loc - 1 of the actual array, NOT BIT ARRAY
			long sum = 0;
			for(long i = loc;i > 0; i -= i & (-i))
				sum += b[i];
			
			return sum;
		}
		
		void updateSingleBIT(long loc, long d){
			for(long i = loc;i <= N; i += i & (-i))
				b[i] += d;
		}
		
		void updateRange(long a, long b, long data){
			updateSingleBIT(a, data);
			updateSingleBIT(b + 1, -data);
		}	
};

int main(int argc, char** argv){
	
	long n, k, A, B, val = 1;
	

	scanf("%ld %ld", &n,&k);
	BinaryIndexTree BIT(n);
	while(k--){
		scanf("%ld %ld", &A, &B);
		BIT.updateRange(A,B,val);
	}
	
	long arr[n];
	for(long i = 0; i < n; i++){
		arr[i] = BIT.queryBIT(i + 1);
	}	
	
	sort(arr, arr + n);

	printf("%ld\n", arr[n/2]);
	return 0;
}
