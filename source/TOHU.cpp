#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;


int main(){
	int iter;
	long long n;
	scanf("%d", &iter);
	
	while(iter--){
		scanf("%lld", &n);
		std::cout << std::fixed;
		cout<< setprecision(11) << 0.75 - 1.0/(2 * (n + 1) * (n + 2))<< endl;
	}
}
