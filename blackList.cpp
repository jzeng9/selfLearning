//
// Created by 曾钧麟 on 2018/11/6.
//
#include <iostream>
#include <vector>
using namespace std;
struct TrieNode{
    bool isWord;
    TrieNode* sons[27];
    TrieNode(){
        isWord=false;
        fill_n(sons,27, nullptr);
    }
};
vector<bool> isBlacListLetter(vector<string> backList, vector<string> query){
    TrieNode* root = new TrieNode();
    for(auto item:backList){
        TrieNode* p = root;
        for(char letter:item){
            int index= letter==' '?26:letter-'a';
            if(p->sons[index]==nullptr)
                p->sons[index]=new TrieNode();
            p=p->sons[index];
        }
        p->isWord=true;
    }
    vector<bool> ans;
    for(auto item:query){
        bool finded = false;
        for(int iter=0;iter<item.length();++iter){
            TrieNode* p = root;
            int tmp = iter;
            while(tmp < item.length()){
                int index = item[tmp]==' '?26:item[tmp]-'a';
                if(p->sons[index]==nullptr)
                    break;
                p=p->sons[index];
                if(p->isWord){
                    ans.push_back(true);
                    finded=true;
                    break;
                }
                tmp++;
            }
            if(finded) break;
        }
        if(!finded) ans.push_back(false);
    }
    return ans;
}
vector<bool> isBlacListWord(vector<string> backList, vector<string> query){
    TrieNode* root = new TrieNode();
    for(auto item:backList){
        TrieNode* p = root;
        for(char letter:item){
            int index= letter==' '?26:letter-'a';
            if(p->sons[index]==nullptr)
                p->sons[index]=new TrieNode();
            p=p->sons[index];
        }
        p->isWord=true;
    }
    vector<bool> ans;
    for(auto item:query){
        bool finded = false;
        for(int iter=0;iter<item.length();++iter){
            TrieNode* p = root;
            int tmp = iter;
            while(tmp < item.length()){
                int index = item[tmp]==' '?26:item[tmp]-'a';
                if(p->sons[index]==nullptr)
                    break;
                p=p->sons[index];
                if(p->isWord){
                    ans.push_back(true);
                    finded=true;
                    break;
                }
                tmp++;
            }
            if(finded) break;
            while(iter<item.length() && item[iter]!=' ') iter++;
        }
        if(!finded) ans.push_back(false);
    }
    return ans;
}
int main(){
    vector<string> blacklisted_phrases = {"machine guns","free ray bans","pornography","world war i","world war ii","sun ray","cool day"};
    vector<string> is_blacklisted = {"i like lmachine guns"};
    vector<bool> ans = isBlacListWord(blacklisted_phrases,is_blacklisted);
    for(auto item:ans){
        if(item) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
