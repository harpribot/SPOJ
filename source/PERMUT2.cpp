#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main(){
	
	vector <long> a(100001);
	int nElems;
	
	while(true){
		scanf("%d", &nElems);
		
		if(nElems == 0)break;
		
		for(int i = 1; i <= nElems; i++){
			scanf("%d", &a[i]);
		}
		int counter = 0;	
		for(int i = 1; i <= nElems; i++){
			if(a[a[i]] == i){
				counter++;
			} 
		}
		if(counter == nElems){
			printf("ambiguous\n");
		}else{
			printf("not ambiguous\n");
		}
		
	}
	
}

