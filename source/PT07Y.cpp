#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Node{
	public:
		int rank;
		int parent;
		
		Node(int x):rank(0),parent(x){
		}
};
class TreeFinder{
	private:
		vector<pair<int,int> > A;
		int nElems;
		int vertex;
		vector<Node*> T;
		int edges;
		
	public:
		TreeFinder(int v,int e):vertex(v),edges(e),nElems(0){
			T.resize(v + 1);
			A.resize(e);
		}
		
		void insert(pair<int, int> edge){
			A[nElems].first = edge.first;
			A[nElems].second = edge.second;
			nElems++;
		}
		
		void MakeSet(int x){
			T[x] = new Node(x);
		}
		
		void UnionRank(int x, int y){
			if(T[x] -> rank > T[y] -> rank)
				T[y] -> parent = x;
			else{
				T[x] -> parent = y;
				if(T[x] -> rank == T[y] -> rank)
					T[y] -> rank = T[y]-> rank +  1;
			}
		}
		
		int FindSet(int x){
			if(x != T[x] -> parent)
				T[x] -> parent = FindSet(T[x] -> parent);
			
			return T[x] -> parent;
		}
		
		bool isTree(){
			
			for(int i = 1; i <= vertex; i++){
				MakeSet(i);	
			}
			
			for(int i = 0; i < edges; i++){
				if(FindSet(A[i].first) != FindSet(A[i].second))
					UnionRank(FindSet(A[i].first), FindSet(A[i].second));
				else
					return false;
			}
			return true;
		}
};

int main(int argc, char** argv){
	int v, e, e1,e2;
	
	scanf("%d %d", &v, &e);
	TreeFinder T(v,e);
	for(int i = 0; i < e; i++){
		scanf("%d %d", &e1, &e2);
		T.insert(make_pair(e1,e2));
	}
	
	if(T.isTree())
		printf("YES\n");
	else
		printf("NO\n");
}
