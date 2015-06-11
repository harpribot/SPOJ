#include<iostream>
#include<stdio.h>

using namespace std;

class Progression{
	private:
		int n1,n2,n3;
		int a,d;
		
	public:
		Progression(int num1, int num2, int num3):a(0),d(0){
			n1 = num1; n2 = num2; n3 = num3;
		}
		
		void findProgression(){
			if((2 * n2) == n1 + n3){
				printf("AP ");
				a = 1;
				d = n3 - n2;
			}
			else{
				printf("GP ");
				a = 2;
				d = n3/n2;
			}
				
		}
		
		void nextTerm(){
			if(a == 2){
				printf("%d\n", n3 * d);
			}
			else{
				printf("%d\n", (n3 + d));
			}
		}
		
};


int main(int argc, char **argv){
	
	int a,b,c;
	while(true){
		scanf("%d %d %d", &a,&b,&c);
		if(a == b && b == c && c == 0) break;
		Progression p(a,b,c);
		p.findProgression();
		p.nextTerm();
	}
}
