//
// Created by 曾钧麟 on 2018/11/8.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
struct TrieNode{
    unordered_set<string> ids;
    TrieNode* kids[3];
    TrieNode(){
        fill_n(kids,3, nullptr);
    }
};
void dfs(TrieNode* root, int level){
    for(int iter=0;iter<=2;++iter){
        if(root->kids[iter]!=nullptr){
            if(root->kids[iter]->ids.size()>0){
                for(int iter=1;iter<=level;++iter) cout << "-";
                cout << (char)('A'+iter) << root->kids[iter]->ids.size() << endl;
            }
            dfs(root->kids[iter],level+1);
        }
    }
}
void construct(vector<vector<string>> logs){
    unordered_map<string,TrieNode*> m;
    TrieNode* root=new TrieNode();
    for(auto log:logs){
        TrieNode* p;
        if(m.find(log[0])==m.end()) p=root;
        else p=m[log[0]];
        int index = log[2][0]-'A';
        if(p->kids[index]== nullptr)
            p->kids[index]=new TrieNode();
        p=p->kids[index];
        p->ids.insert(log[0]);
        m[log[0]]=p;
    }
    dfs(root,1);
}
int main(){
    vector<vector<string>> logs={{"100","1000","A"},{"200","1003","A"}
    ,{"300","1009","B"},{"100","1026","B"}
    ,{"100","1030","C"},{"200","1109","B"}
    ,{"200","1503","A"}};
    construct(logs);
}
