#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;

#define ll_ long long
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

inline void writell (ll_ n)
{
    ll_ N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
    pc('\n');
    return ;
}


ll_ happyNum(ll_ num, ll_ count, map <ll_,ll_> &hasher){
	if(num == 1)
		return count;
	
	ll_ numNew = 0;
	while(num){
		int temp = num % 10;
		numNew += temp * temp;
		num = num / 10;
	}
	
	if(hasher[numNew] != -numNew){
		hasher[numNew] = - numNew ;
		count++;
		return happyNum(numNew, count, hasher);
	}
	else{
		return -1;
	}
}

void scanll(ll_ &x)
{
    register ll_ c = gc();
    x = 0;
    ll_ neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


int main(){
	
	ll_ iter;
	ll_ num;
	ll_ result;
	scanll(iter);
	while(iter--){
		map <ll_, ll_> hasher;
		scanll(num);
		result = happyNum(num, 0, hasher);
		cout<<result<<endl;
		writell(result);
	}
}
