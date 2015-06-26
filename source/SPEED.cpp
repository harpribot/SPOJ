/*

Suppose the circumference of the circular track is D
Speed of A is Va. Time taken by A to cover distance D is ta.
Speed of B is Vb'. Time taken by B to cover distance D is tb.
 
So, relative speed between them is Va-Vb

Now this is important. A and B will start from the starting point and after a certain time passes they will meet again 
at the starting point. This time depends on their relative speed. It will be the LCM of their individual times,ta and tb.
So at that time, both A and B will be exactly at the starting point again. In this time period they may meet at any number
of points which we have to find out.

(Note: After they meet at the starting point again, the cycle  continues and they will keep meeting at the exact same points.)

Time taken by both of them to meet again at the starting point , T1=LCM(ta,tb)=LCM(D/Va,D/Vb) =D/GCD(Va,Vb)

Suppose they meet n times in time T1. So time in between their consecutive meets is, T2=(T1/n). This time can be calculated
 by calculating the time taken to meet for the first time after starting. Va-Vb is their relative speed.

So,Time taken by them to meet for the first time, T2= D/(Va-Vb)

Dividing T1 by T2, we find n

n=(T1/T2)=((Va-Vb)/GCD(Va,Vb))

Hence, the answer.
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long ll_;

ll_ gcd(ll_ a, ll_ b){
	while(b != 0){
		ll_ temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main(){
	ll_ iter, v1, v2;
	scanf("%lld", &iter);
	
	while(iter--){
		scanf("%lld %lld", &v1, &v2);
		printf("%lld\n", abs(v1 - v2)/gcd(abs(v1), abs(v2)));
	}
}
