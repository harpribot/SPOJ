#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class EditDistDP{
	
	private:
		string X, Y;
		int Xlen, Ylen;
		
	public:
		EditDistDP(string Xstr, string Ystr){
			X = Xstr;
			Y = Ystr;
			Xlen = Xstr.size();
			Ylen = Ystr.size();
		}
		
		int Min2(int a, int b){
			return (a < b ? a:b);
		}
		
		int Min3(int a, int b, int c){
			return Min2( Min2( a, b) , c);
		}
		int distance(string X1, string Y1){
			
			int cost = 0;
			int left, top, corner;
			
			int m = X1.size() + 1;
			int n = Y1.size() + 1;
			
			int *T = (int*)malloc(m * n * sizeof(int));
			
			// Initialize table
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					*(T + i * n + j) = -1;
				}
			}
			
			// Set up base cases
    		// T[i][0] = i
			for(int i = 0; i < m; i++){
				*(T + i * n) = i;
			}
			
			// T[0][j] = j
			for(int j = 0; j < n; j++){
				*(T + j) = j;
			}
			
			
			
			for(int i = 1; i < m ; i++){
				for(int j = 1; j < n; j++){
					
					// T[i][j-1]
					left = *(T + i * n + j - 1);
					left += 1; // deletion 
					
					// T[i-1][j]
					top = *(T + (i - 1) * n + j);
					top += 1; // insertion
				
					// T[i-1][j-1]
					corner = *(T + (i - 1)*n + (j - 1));
					corner += (X[i - 1] != Y[j - 1]); // transform if unequal
					
					// Minimum cost of current cell
            		// Fill in the next cell T[i][j]
            		*(T + (i)*n + (j)) = Min3(left, top, corner);
				}
			}
			cost = *(T + m*n - 1);
			free(T);
			return cost;
		}
		
		string getX(){
			return X;
		}
		string getY(){
			return Y;
		}
		int getM(){
			return Xlen;
		}
		
		int getN(){
			return Ylen;
		}
};

int main(){
	
	string X, Y;
	while(true){
		cin>> X >> Y;
		if(X == "*" && Y == "*") break;
		EditDistDP a(X,Y);
		
		printf("%d\n", a.distance(a.getX(),a.getY()));
	}
}
