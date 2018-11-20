//
// Created by 曾钧麟 on 2018/10/31.
//
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> wordExtension(string str){
    vector<pair<int,int>> ans;
    if(str.length()<3) return ans;
    int pre=0;
    for(int iter=1;iter<=str.length();++iter){
        if(iter==str.length() || str[iter]!=str[pre]){
            if((iter-pre)>=2){
                ans.push_back({pre,iter-pre});
            }
            pre=iter;
        }
    }
    return ans;
}
bool isWord(string str){
    return str == "heo";
}
bool DFS(string str, vector<pair<int,int>> tmp, int levels, int indexDif){
    if(isWord(str)) return true;
    for(int iter=0;iter<tmp[levels].second;++iter){
        string newStr=str;
        if(iter!=0)
            newStr.erase(tmp[levels].first-indexDif,iter);
        if(DFS(newStr,tmp,levels+1,indexDif+iter)){ return true;}
    }
    return false;
}
bool isWordExtension(string str){
    vector<pair<int,int>> tmp = wordExtension(str);
    return DFS(str,tmp,0,0);
}
int main(){
    if(isWordExtension("hellllooooo")){
        cout << "yes" << endl;
    }
}

