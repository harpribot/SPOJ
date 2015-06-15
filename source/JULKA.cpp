#include<iostream>
#include<cstring>
#include<stdio.h>

#define MAX 111
using namespace std;

class AppleDist{
	private:
		char total[MAX];
		char diff[MAX];
		int totLen, diffLen;
		char Klaudia[MAX];
		char Natalia[MAX];
		char add[MAX];
		char minus[MAX];
		
	public:
		AppleDist(char tot[], char dif[], int tot_, int dif_): totLen(tot_), diffLen(dif_){
			strncpy(total, tot, totLen * sizeof(char));
			strncpy(diff, dif, diffLen * sizeof(char));
			total[totLen] = 0; // terminate the array
			diff[diffLen] = 0; // terminate the array
		}
		
		void addThem(){
			int i, j, carry;
			for(i = totLen - 1, j = diffLen - 1, carry = 0; i >= 0 || j >= 0 || carry; i++,j++ ){
				
			}
		}
		
		void substractThem(){
			int i, j;
			for(i = totLen - 1, j = diffLen - 1; i >= 0 || j >= 0; i++,j++ ){
				
			}
		}
		
		char* divide(char num[]){
			
		}
		char* klaudiaShare(){
			addThem();
			strncpy(Klaudia, divide(add), strlen(add));
			return Klaudia;
		}
		
		char* nataliaShare(){
			substractThem();
			strncpy(Natalia, divide(minus), strlen(minus));
			return Natalia;
		}
};

int main(int argc, char** argv){
	
	char total[MAX], diff[MAX];
	int totSize,diffSize;
	while(scanf("%s%s", total, diff) == 2){
		totSize = strlen(total);
		diffSize = strlen(diff);
		AppleDist a(total,diff,totSize, diffSize);
		printf("%s\n", a.klaudiaShare());
		printf("%s\n", a.nataliaShare());
	}
	return 0;
}
