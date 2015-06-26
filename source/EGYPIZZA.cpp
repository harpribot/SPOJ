#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define INF 10009

int pizza(vector<int> a, int total){
	
	if(total == 0) return 0;
	int n22 = INF,n4444 = INF, n442 = INF, n43 = INF, left = 0;
	vector<int> b(3);

	if(a[1] >= 2){
		b = a;
		b[1]-=2;
		n22 =1 + pizza(b, total - 2);
	}
	if(a[0] >= 4){
		b = a;
		b[0]-=4;
		n4444 = 1 + pizza(b, total - 4);
	}
	if(a[0] >= 2 && a[1] >= 1){
		b = a;
		b[0] -= 2; b[1] -= 1;
		n442 = 1 + pizza(b, total - 3);
	}
	if(a[0] >= 1 && a[2] >= 1){
		b = a;
		b[0] -= 1; b[2] -= 1;
		n43 = 1+ pizza(b, total - 2);
	}
	else{
		while(a[0] + a[1] + a[2] != 0){
			if(a[1] >= 1 && a[0] >= 1 ){
				left += 1;
				a[1] -= 1;
				a[0] -= 1;
			}
			if(a[0] >= 3){
				left += 1;
				a[0] -= 3;
			}
			if(a[2] >= 1){
				left += 1;
				a[2] -= 1;
			}
			if(a[1] >= 1){
				left += 1;
				a[1] -= 1;
			}
			if(a[0] >= 2){
				left += 1;
				a[0] -= 2;
			}
			if(a[0] >= 1){
				left += 1;
				a[0] -= 1;
			}
		}
	}
    	
	printf("a0 - %d, a1 - %d, a2 - %d\n", a[0], a[1], a[2]);
	printf("1 - %d\n2 - %d\n3 - %d\n4 - %d\nleft - %d\n", n22,n4444,n442, n43, left);
	return min(left, min(min(n22,n4444),min(n442,n43)));
}
	
int main(int argc, char** argv){
	
	int nFriends;
	scanf("%d", &nFriends);
	vector<int> portionVec(3);
	for(int i = 0; i < nFriends; i++){
		string str;
		cin>>str;
		float val = (float)(str[0] - '0')/ (str[2] - '0');	
		if(val == 0.25)
			portionVec[0] += 1;
		else if(val == 0.5)
			portionVec[1] += 1;
		else
			portionVec[2] += 1;
	}
	printf("Array - %d %d %d\n", portionVec[0], portionVec[1], portionVec[2]);
	int slices = pizza(portionVec, nFriends );
	printf("%d\n", slices + 1);

}
