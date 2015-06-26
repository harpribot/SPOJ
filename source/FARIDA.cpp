#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define l64 long long

l64 maxCoins(vector<l64> a){
	l64 n = a.size();
	l64 b[n + 1];
	
	if(n == 0) return 0;
	if(n == 1) return a[0];
	
	else{
		// initialize T(0)
		b[0] = 0;
		// initialize T(1)
		b[1] = a[n - 1];
		
		for(l64 j = 2; j <= n; j++){
			b[j] = max(b[j - 1], a[n - j] + b[j - 2]);
		}
		return b[n];
	} 
		
	
}

int main(int argc, char** argv){
	
	l64 iter, length;
	l64 data;
	cin>>iter;
	
	for(l64 i = 1; i <= iter; i++){
		cin>>length;
		vector<l64> a(length);
		for(l64 j = 0; j < length; j++){
			cin>>data;
			a.push_back(data);	
		}
		cout<< "Case "<< i<< ": "<< maxCoins(a)<<endl;
		
	}
}
