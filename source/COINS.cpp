#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define llu long long 

/*long long maxMoney(long long data){
	if(data == 0) return 0;
	else if(data == 1) return 1;
	else{
		vector<long long> temp(data + 1);
		temp[0] = 0;
		temp[1] = 1;
		
		for(long long i = 2; i <= data; i++){
			temp[i] = max(i, temp[i/2] + temp[i/3] + temp[i/4]);
		}
		
		return temp[data];
	}
}
*/
llu maxMoneyAux(llu data, map<llu, llu> & temp){
	if(data == 0) return 0;
	if(data == 1) return 1;
	
	if(temp[data/2] == 0)
		temp[data/2] =  maxMoneyAux(data/2, temp);	

	if(temp[data/3] == 0)
		temp[data/3] = maxMoneyAux(data/3, temp);	

	if(temp[data/4] == 0)
		temp[data/4] = maxMoneyAux(data/4, temp);
		
	

	return max(data, temp[data/2] + temp[data/3] +  temp[data/4]);
}

llu maxMoneyFast(llu data){
	
	map<llu, llu> temp;
	return maxMoneyAux(data, temp);
}



int main(int argc, char** argv){
	
	llu data;
	
	while(scanf("%llu", &data) != EOF){
		printf("%llu\n", maxMoneyFast(data));
	}
	
	return 0;
}
