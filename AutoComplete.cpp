//
// Created by 曾钧麟 on 2018/10/25.
//
#include "iostream"
#include "vector"
using namespace std;
struct TrieNode{
    vector<int> nodes;
    TrieNode* sons[26];
    TrieNode(){
        fill_n(sons,26,nullptr);
    }
};
class Solutiion{
public:
    void autoComplete(string str, vector<string>& words){
        TrieNode* root=new TrieNode();
        for(int jter=0;jter<words.size();++jter){
            string tmp=generateUpper(words[jter]);
            TrieNode* p=root;
            for(int iter=0;iter<tmp.length();++iter){
                int index=tmp[iter]-'A';
                if(p->sons[index]==NULL)
                    p->sons[index]=new TrieNode();
                p=p->sons[index];
                p->nodes.push_back(jter);
            }
        }
        string strUpper = generateUpper(str);
        TrieNode* p=root;
        for(int iter=0;iter<strUpper.length();++iter){
            int index=strUpper[iter]-'A';
            if(p->sons[index]==NULL) {
                cout << "No match!" << endl;
                return;
            }
            p=p->sons[index];
        }
        vector<string> candidates;
        for(auto item:p->nodes){
            candidates.push_back(words[item]);
        }
        vector<string> ans;
        for(auto item:candidates){
            int cpointer=0,spointer=0;
            for(;cpointer<item.length();cpointer++){
                if(spointer<str.length() && item[cpointer]==str[spointer]) spointer++;
            }
            if(spointer==str.length()){
                ans.push_back(item);
                cout << item << endl;
            }
        }
    }
    string generateUpper(string str){
        string ans;
        for(int iter=0;iter<str.length();++iter)
            if(str[iter]>='A' && str[iter]<='Z')
                ans+=str[iter];
        return ans;
    }
};

int main(){
    string str = "GraphController";
    vector<string> words={"GraphView","DataGraphView","DataController","GraphViewController","DataScienceView"};
    Solutiion().autoComplete(str,words);
}

