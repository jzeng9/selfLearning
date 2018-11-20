//
// Created by 曾钧麟 on 2018/10/31.
//
#include <iostream>
#include <vector>
using namespace std;
void helper(vector<vector<string>> v, int levels, vector<string>& ans, string tmp){
    if(levels == v.size()){
        ans.push_back(tmp);
        return;
    }
    for(auto item:v[levels]){
        helper(v,levels+1,ans,tmp+item);
    }
}
void findAllPairs(vector<vector<string>> v){
    vector<string> ans;
    string tmp;
    helper(v,0,ans,tmp);
    for(auto item:ans){
        cout << item << endl;
    }
}
int main(){
    vector<vector<string>> strs={{"2","3","4"},{"a","b"}};
    findAllPairs(strs);
}