#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<stdlib.h>

using namespace std;

class TrieNode{
    public:
        bool isEnd;
        char val;
        vector<TrieNode*> children;

        TrieNode():isEnd(false), val(' '){}
        TrieNode(char v):isEnd(false), val(v){}

        TrieNode* subNode(int val){
            for(auto child: children){
                if(child -> val == val)
                    return child;
            }
            return NULL;
        }

        ~TrieNode(){
            for(auto child: children)
                delete child;
        }
};

class Trie{
    private:
        TrieNode *root;

    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string word){
            if(search(word)) return;

            TrieNode* curr = root;
            for(auto ch: word){
                TrieNode* child = curr -> subNode(ch);
                if(child != NULL)
                    curr = child;
                else{
                    TrieNode* newNode = new TrieNode(ch);
                    curr -> children.push_back(newNode);
                    curr = newNode;
                }
            }
            curr -> isEnd = true;
        }
        

        bool search(string word){
            TrieNode* curr = root;
            for(auto ch : word){
                TrieNode* child = curr -> subNode(ch);
                if(child == NULL)
                    return false;
                curr = child;
            }
            return curr -> isEnd == true;
        }

        bool isCompatible(string word){
            TrieNode* curr = root;
            for(auto ch : word){
                curr = curr -> subNode(ch);
            }
            if(curr -> children.size() > 0)
                return false;
            else
                return true;

        }
        
};

int main(){
    int iter, N;
    scanf("%d", &iter);

    while(iter--){
        scanf("%d", &N);
        vector<string>store(N);
        Trie t;
        bool compatible = true;
        for(int i = 0; i< N; i++){
            string str;
            cin >> str;
            store[i] = str;
            t.insert(str);
        }
        for(int i = 0; i < N; i++){
            if(!t.isCompatible(store[i])){
                compatible = false;
                break;
            }
        }
        if(!compatible)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
