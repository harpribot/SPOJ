#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class AdvEditDistDP{
	
	private:
		string X, Y;
		
	public:
		AdvEditDistDP(string Xstr, string Ystr){
			X = Xstr;
			Y = Ystr;
		}
		
		int Min2(int a, int b){
			return (a < b ? a:b);
		}
		
		int Min3(int a, int b, int c){
			return Min2( Min2( a, b) , c);
		}
		int distance(string X1, string Y1){
			
			int cost = 0;
			int left, top, corner,nextCorner;
			
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
					corner += (X1[i - 1] != Y1[j - 1]); // substitution if unequal
					
					if(i > 1 && j > 1){
					
						if(X1[i - 2] == Y1[j - 1] && X1[i - 1] == Y1[j - 2]){
							// T[i - 2][j - 2] 
							nextCorner = *(T + (i - 2) * n + (j - 2));
							nextCorner += (X1[i - 1] != Y1[j - 1]); // swap operation
							*(T + (i)*n + (j)) = Min2(Min3(left, top, corner), nextCorner);	
						}
						else
							*(T + (i)*n + (j)) = Min3(left, top, corner);
					}
					else
						*(T + (i)*n + (j)) = Min3(left, top, corner);// Minimum cost of current cell
            													   	// Fill in the next cell T[i][j]
				}
			}
			cost = *(T + m*n - 1);
			free(T);
			return cost;
		}
		
		
		int dlDistance(string a, string b, int c){
			int m = a.length(); int n = b.length();
			int INF = m + n;
			
			vector<int> DA(c);
			
			int * T = (int*)malloc((m + 2) * (n + 2) * sizeof(int));
			
			*(T) = INF;
			
			for(int i = 0; i <= m; i++){
				*(T + (i + 1) * (n + 2) ) = INF;
				*(T + (i + 1) * (n + 2) + 1) = i;
			}
			
			for(int j = 0; j < = n; j++){
				*(T + (j + 1)) = INF;
				*(T + (n + 2) + (j + 1))= j;
			}
			
			for(int i = 1; i <= m; i++){
				int DB = 0;
				
				for(int j = 1; j <= n; j++){
					int i1 = DA[b[j - 1]];
					int j1 = DB;
					
					int cost;
					
					if(a[i - 1] == b[j - 1]){
						cost = 0;
						DB = j;
					}
					else{
						cost = 1;
						*(T + i * (n + 2) + j) = Min3();
					}
				}
			}
		}
		
		string getX(){
			return X;
		}
		string getY(){
			return Y;
		}

};

int main(){
	string X, Y;
	while(true){
		cin>> X >> Y;
		if(X == "*" && Y == "*") break;
		AdvEditDistDP a(X, Y);
		
		printf("%d\n", a.distance(a.getX(),a.getY()));
	}
}
