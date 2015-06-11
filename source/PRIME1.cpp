#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class prime1{
	private:
		vector<int> primes;
		int nElems;
		
	public:
		prime1(int maxSize):nElems(0){
			primes.resize(maxSize);
		}
		
		void insert(int prime){
			primes[nElems] = prime;
			nElems++;
		}
		
		void display(){
			for(int i = 0; i < nElems;i++){
				cout<<primes[i]<<endl;
			}
			
		}
		
		void displayAll(){
			for(int i = 0; i < primes.size();i++){
				cout<<primes[i]<<endl;
			}
		}
		
		int getFirstUnflagged(int p_old){
			int p = p_old - 1;
			while(primes[p] != 0){
				p++;
				if(p == primes.size())
					break;
			}
			return (p + 2);
		}
		
		void sieveOfEratosthenes(){
			bool noZeros = false;
			int p = 1;
			while(noZeros == false){
				p = getFirstUnflagged(p);
				if(p == 32002){ 
					noZeros = true;
				}
				else{
					for(int i = p; (p * i - 2) < 32000; i++){
						primes[p * i - 2] = 1;
					}
				}
			}
			
		}
		
		int getIndex(int pos){
			return primes[pos];
		}
		
		void getAllPrimes(prime1 a){
			for(int i = 0; i < 32000; i++){
				if (a.getIndex(i) == 0){
					primes[nElems] = i + 2;
					nElems++;
				}
			}
		}
		
		int getElems(){
			return nElems;
		}
		
		void getPrimes(int low,int high, prime1 primeList){
			for(int i = low; i<= high;i++){
				if(!(isDivisible(i, primeList)) && i != 1)
					cout<<i<<endl;
			}
		}
		
		bool isDivisible(int a, prime1 list){
			int start = 0;
			int stop = floor(sqrt(a));
			while(list.getIndex(start) <= stop){
				if(a % list.getIndex(start) == 0){
					return true;
				}
				else{
					start++;
				}
			}
			return false;
		}
		
};


int main(){
	
	int maxNumPrimes = 32000;
	prime1 initPrimeList(maxNumPrimes);
	initPrimeList.sieveOfEratosthenes();
	
	prime1 loadPrimes(maxNumPrimes);
	loadPrimes.getAllPrimes(initPrimeList);
	
	int counter, low, high;
	
	prime1 finalList(maxNumPrimes);
	
	cin>> counter;
	
	for(int i = 0; i < counter; i++){
		cin>> low;
		cin>>high;
		finalList.getPrimes(low,high,loadPrimes);
		cout<<endl;
	}
	
	return (0);
}
