#include<iostream>
#include<cstring>
#include<stdio.h>


#define MAX 5005
#define l64 long long 

using namespace std;




class Acode{
	
	private:
		char a[MAX];
		l64 d[MAX];
		int str_len;
		
	public:
		Acode(char str[],l64 d_[], int size):str_len(size){
			strncpy(a,str,size * sizeof(char));
			memcpy(d,d_, size * sizeof(l64));
		}
		
		l64 numCodes(int idx){
			while(idx < str_len){
				int temp = 0;
				temp = (a[idx - 1] - '0') * 10;
				temp += (a[idx] - '0');
				
				if(a[idx] - '0') d[idx] = d[idx - 1];
				if(temp <= 26 && temp > 9) d[idx] += d[idx - 2 >= 0 ? idx - 2 : 0];
				idx++;
			}
			return d[str_len - 1];
		}
		
		char* getStr(){
			return a;
		}
		
		l64* getCount(){
			return d;
		}
};


int main(int argc, char** argv){
	
	char str[MAX];
	int len;
	l64 d[MAX];
	
	while(scanf("%s", str) == 1){
		if(str[0] == '0') break;
		len = strlen(str);
		memset(d,0,sizeof(d));
		d[0] = 1;
		Acode a(str,d,len);
		printf("%d\n",a.numCodes(1) );
	}
}
