#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(int argc, char** argv){
	float L;
	while(true){
		scanf("%f", &L);
		if(L == 0) break;
		cout<<setprecision(2)<<fixed<< L * L / (2 * M_PI)<<"\n";
	}
}
