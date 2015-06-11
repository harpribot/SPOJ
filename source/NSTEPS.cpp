#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Nsteps{
	private:
		int x,y;
		
	public:
		Nsteps(int a, int b){
			x = a; y = b;
		}
		
		int numPoint(){
			int sum;
			if(x - y > 2 || (y > x) || (x - y) == 1){
				return 0;
			}
			else{
				sum = x + y;
				if((sum/2) % 2 == 1){
					if(x == y)return sum - 1;
					else return sum;
				}
				else{
					if(x == y)return sum;
					else return sum - 1;
				}
			}
		}
};


int main(){
	
	int iter,x,y;
	cin>>iter;
	
	for(int i = 0; i < iter; i++){
		cin>>x>>y;
		Nsteps v(x,y);
		int pointVal = v.numPoint();
		if(pointVal == 0){
			if(x != 0 || y != 0 ){
				printf("No Number\n");
			}
			else printf("%d\n",0);	
		}
		else printf("%d\n", pointVal);
	}
	
	
}
