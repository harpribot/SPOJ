#include<iostream>
#include<string>
#include<stdio.h>
#include<utility>

using namespace std;

pair<int,int> depth(string s, int loc){
	if(s[loc] == 'l') return make_pair(0,1);
	else if(s[loc + 1] == 'l' && s[loc + 2] == 'l')return make_pair(1,3);
	else if(s[loc + 1] == 'l' && s[loc + 2] == 'n'){
		pair<int, int> a;
		a = depth(s, loc + 2);
		return make_pair(a.first + 1, a.second + 2);
	}
	else if(s[loc + 1] == 'n'){
		pair<int, int> a;
		a = depth(s, loc + 1);
		if(s[loc + 1 + a.second] == 'l'){
			return make_pair(a.first + 1, a.second + 2);
		}
		else{
			pair<int, int>b;
			b = depth(s, loc + 1 + a.second);
			return make_pair(1 + max(a.first, b.first), 1 + a.second + b.second);
		}
	}
}

int main(){
	int iter;
	string s; 
	scanf("%d", &iter);
	pair<int, int> a;
	while(iter--){
		cin>>s;
		a = depth(s,0);
		printf("%d\n", a.first);
	}
}
