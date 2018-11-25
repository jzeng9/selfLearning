//
// Created by 曾钧麟 on 2018/11/22.
//
#include <iostream>
#include <vector>
using namespace std;
vector<string> seperateString(string str){
    bool isStart= false;
    vector<string> ans;
    int iter=0,start=0;
    while(iter<str.length()){
        if(str[iter] == '"'){
            isStart=!isStart;
            ++iter;
        }
        else if(str[iter] == ',' && !isStart){
            ans.push_back(str.substr(start,iter-start));
            start = ++iter;
        }
        else ++iter;
    }
    if(start <= str.length()-1) ans.push_back(str.substr(start,iter-start));
    return ans;
}
int main(){
    vector<string> ans=seperateString("abc,,cca\",anc\"cca,nba");
    for(auto item:ans) cout << item << endl;
}

