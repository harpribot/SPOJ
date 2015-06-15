#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

class NumBishops{
	
	private:
		string n;
		stack <int> out;
	public:
		NumBishops(string a):n(a){
		}
		
		void decrement(){
			int digit;
			bool dec = false;
			for(int i = n.size() - 1; i >= 0; i--){
				digit = n[i] - '0';
				if(digit || dec){
					if(!dec){
						if(i != 0 || digit - 1 != 0)
							out.push(digit - 1);
						dec = true;
					}
					else
						out.push(digit);
				}
				else{
					out.push(9);
				}
			}
		}
		
		void mul(){
			stack<int> b = out;
			stack<int> c;
			while(!b.empty()){
				c.push(b.top());
				b.pop();
			}
			int carry = 0;
			while(!c.empty()){
				if(c.top() * 2 + carry >= 10){
					b.push((c.top() * 2 + carry) % 10);
					carry = 1;
				}
				else{
					b.push(c.top() * 2 + carry);
					carry = 0;
				}
					
				c.pop();
			}
			if(carry == 1) b.push(carry);
			out = b;
		}
		
		void display(){
			while(!out.empty()){
				printf("%d",out.top());
				out.pop();
			}
			printf("\n");
		}
		
};

int main(int argc, char** argv){
	string str;
	
	while(true){
		getline(cin,str);
		if(str == "")break;
		if(str[0] - '0' == 1 && str.size()==1)
			printf("1\n");
		else{
			NumBishops a(str);
			a.decrement();
			a.mul();
			a.display();
		}
		
	}
	
	
}
