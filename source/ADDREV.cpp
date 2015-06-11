#include<iostream>
#include<stdio.h>

using namespace std;

class NumReverse{
	
	private:
		long num;
		
	public:
		NumReverse(long n){
			num = n;
		}
		
		void reverseDigit(){
			long reverse = 0;
			while(num > 0){
				reverse = reverse * 10 + num % 10;
				num = num/10;
			}
			num = reverse;
		}
		
		long getNum(){
			return num;
		}
		
};

int main(){
	
	int iter;
	long a,b;
	scanf("%d",&iter);
	
	for(int i = 0; i < iter; i++){
		scanf("%d %d", &a,&b);
		NumReverse n1(a), n2(b);
		n1.reverseDigit();
		n2.reverseDigit();
		long sum = n1.getNum() + n2.getNum();
		NumReverse sum1(sum);
		sum1.reverseDigit();
		printf("%d\n", sum1.getNum());
	}
	
}
