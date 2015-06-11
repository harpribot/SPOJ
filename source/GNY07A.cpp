#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main(){
	int iter, pos;
	scanf("%d", &iter);
	
	string str;
	
	for(int i = 0; i < iter; i++){
		cin>>pos>>str;
		str.replace(pos - 1,1,"");
		printf("%d ", i + 1);
		cout<<str<<endl;
	}
}
