#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

class Factorial{
	
	private:
		vector<int> res;
		int nElems;
		
	public:
		Factorial(int maxSize):nElems(1){
			res.resize(maxSize);
			res[0] = 1;
		}
		
		void factorial(int n){
			for(int x = 2; x <= n; x++){
				nElems = fMultiply(x, res, nElems);
			}
			
			for(int i = nElems - 1; i >= 0; i--){
				cout<<res[i];
			}
			cout<<endl;
		}
		
		int fMultiply(int x, vector<int> &r, int elem){
			int carry = 0, prod;
			for(int i = 0; i < elem; i++){
				prod = x * r[i] + carry;
				r[i] = prod % 10;
				carry = prod/10;
			}
			
			while(carry){
				r[elem] = carry % 10;
				carry = carry / 10;
				elem++;
			}
			return elem;
		}
		
		int getElem(){
			return nElems;
		}
};

int main(){
	int iter,x;
	cin>>iter;
	
	for(int i = 0; i < iter; i++){
		Factorial f(158);
		cin>>x;
		f.factorial(x);
	}
	
}
