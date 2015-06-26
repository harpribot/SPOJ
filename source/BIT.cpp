#include<iostream>
#include<vector>
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
	
	int iter;
	long n, u, l, r, val, q, index;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%ld %ld", &n, &u);
		BinaryIndexTree BIT(n);
		while(u--){
			scanf("%ld %ld %ld", &l, &r, &val);
			BIT.updateRange(l + 1,r + 1,val);
		}
		scanf("%ld", &q);
		while(q--){
			scanf("%ld", &index);
			printf("%ld\n", BIT.queryBIT(index + 1));
		}
	}
	
	return 0;
}
