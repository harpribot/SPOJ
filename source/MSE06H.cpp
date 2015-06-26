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
		
		long queryRange(long a, long b){
			return queryBIT(b) - queryBIT(a - 1); 
		}
};

int main(int argc, char** argv){
	BinaryIndexTree b(12);
	
	b.updateSingleBIT(1,3);
	b.updateSingleBIT(2,2);
	b.updateSingleBIT(3,-1);
	b.updateSingleBIT(4,6);
	b.updateSingleBIT(5,5);
	b.updateSingleBIT(6,4);
	b.updateSingleBIT(7,-3);
	b.updateSingleBIT(8,3);
	b.updateSingleBIT(9,7);
	b.updateSingleBIT(10,2);
	b.updateSingleBIT(11,3);
	
	cout<< b.queryRange(1,5);
	
	return 0;
}
