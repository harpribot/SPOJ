#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stack>

using namespace std;

class CarAllign{
	
	private:
		int pass;
		stack<int> inStack;
		int numCars;
	
	public:
		CarAllign(int n):pass(0), numCars(n){
			inStack.push(n + 1);
		}
		
		bool isPossible(){
			int n, count = numCars;
			bool isTrue = 1;
			while(count--){
				scanf("%d", &n);
				if(n == pass + 1) pass = n;
				else if(n < inStack.top()) inStack.push(n);
				else{
					while(n > inStack.top() && inStack.top() != numCars + 1){
						if(inStack.top() == pass + 1){
							pass = inStack.top();
							inStack.pop();
						}
						else {
							isTrue = false;
							break;
						}
					}
					inStack.push(n);
				}
			}
			return isTrue;
		}
};

int main(int argc, char** argv){
	int iter;
	while(true){
		scanf("%d", &iter);
		if(iter == 0) break;
		CarAllign car(iter);
		if(car.isPossible()) printf("yes\n");
		else printf("no\n");
	}
}
