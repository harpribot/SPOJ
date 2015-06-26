#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAXN  100000

vector<int> adj[MAXN + 2];
int n;
int dp[MAXN + 2][2];

int go(int cur, int parent, bool selectedParent){
	// if value is already known
	if(dp[cur][selectedParent] != -1) return dp[cur][selectedParent];
	
	// reference the return value(ret) to the dp location so that it can be stored there.
	int &ret = dp[cur][selectedParent]; 
	ret = 0;
	
	int r;
	if(selectedParent){
		for(int i = 0; i < adj[cur].size(); i++){
			if(adj[cur][i] != parent)
				ret += go(adj[cur][i], cur, false);
		}
		
		r = 1;
		for(int i = 0; i < adj[cur].size(); i++){
			if(adj[cur][i] != parent)
				r += go(adj[cur][i], cur, true);
		}
		
		ret = min(r, ret);
	}
	else{
		ret = 1;
		for(int i = 0; i < adj[cur].size(); i++){
			if(adj[cur][i] != parent)
				ret+= go(adj[cur][i], cur, true);
		}
	}
	
	return ret;
}

int main(){
	int u,v;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}
	
	for(int i = 1; i < n; i++){
		scanf("%d %d", &u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	memset(dp, -1, sizeof(dp));
	
	// when not included
	int r1 = 0;
	for(int i = 0; i < adj[1].size(); i++){
		r1 += go(adj[1][i], 1, false);
	}
	
	//when included
	int r2 = 1;
	for(int i = 0; i < adj[1].size(); i++){
		r2 += go(adj[1][i], 1, true);
	}
	
	// minimum of the two cases is the answer
	printf("%d\n", min(r1,r2));
}
