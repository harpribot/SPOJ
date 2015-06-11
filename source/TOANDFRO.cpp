#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

class DecodeString{
	
	private:
		string text;
		int matCol;
		
	public:
		DecodeString(int columns, string message){
			matCol = columns;
			text = message;	
		}
		
		int getRows(){
			return text.length()/matCol; 
		}
		
		void decode(){
			for(int i = 0; i < matCol; i++){
				for(int j = 0; j < getRows(); j++){
					if(j % 2 == 0)
						cout<< text[j * matCol + i];
					else
						cout<< text[j * matCol + ((matCol - 1) - i)];
				}
			}
			printf("\n");
		}
		
		string getText(){
			return text;
		}
		
		int getCol(){
			return matCol;
		}
		
};


int main(){
	string s;
	int n;
	
	while(true){
		cin>>n;
		if(n == 0) break;
		cin>>s;
		DecodeString d(n,s);
		d.decode();	
	}
}
