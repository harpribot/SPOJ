#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

class AnagramCheck {
	
	private:
		string s1,s2;
		vector<int> v;
		int len1, len2;
		
	public:
		AnagramCheck(string s1_, string s2_):s1(s1_), s2(s2_){
			len1 = s1_.size();
			len2 = s2_.size();
			v.resize(len1);
		}
		
		void isAnagram(){
			if(len1 != len2){
				printf("NO\n");
				return;
			}
			for(int i = 0; i < len1; i++){
				int a = 0;
				for(int j = 0; j < len2; j++){
					if(s1[i] == s2[j] && (v[j] != 1)){
						a = 1;
						v[j] = 1;
						break;
					}
				}
				if(a == 0){
					printf("NO\n");
					return;
				}
			}
			printf("YES\n");
		}
		
		
};

int main(int argc, char** argv){
	
	int iter;
	string s1,s2;
	scanf("%d", &iter);
	
	for(int i = 0; i < iter; i++){
		cin>>s1>>s2;
		AnagramCheck a(s1,s2);	
		a.isAnagram();
	}	
	
	

}
