#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class CandyPop{
	
	private:
		vector<int> a;
		int nElems;
		int sum;
		
	public:
		CandyPop(int maxSize):nElems(0), sum(0){
			a.resize(maxSize);
		}
		
		void insert(int val){
			a[nElems++] = val;
			sum += val;
		}
		
		int minMoves(){
			if(sum % nElems != 0)
				return -1;
			
			int avg = sum/nElems;
			int move = 0;
			for(int i = 0; i < nElems; i++){
				if(a[i] < avg)
					move += (avg - a[i]);
			}
			
			return move;
		}
		
		
};

int main(int argc, char** argv){
	
	int numCandy, candyVal;
	int maxSize = 10000;
	while(true){
		scanf("%d", &numCandy);
		if(numCandy == -1) break;
		CandyPop can(maxSize);
		for(int i = 0; i < numCandy; i++){
			scanf("%d", &candyVal);
			can.insert(candyVal);
		}
		printf("%d\n", can.minMoves());
	}
}
