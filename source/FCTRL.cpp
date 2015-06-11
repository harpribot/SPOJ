#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int divBase = 5;
	int iter;
	cin>>iter;
	
	for(int i= 0; i < iter; i++){
		int div = divBase;
		int numZeros = 0;
		int num;
		cin>>num;
		while(num >= div){
			numZeros += (num/div);
			div *= divBase;
		}
		cout<<numZeros<<endl;
	}
	

	return 0;
}
