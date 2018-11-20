//
// Created by 曾钧麟 on 2018/11/7.
//
#include <iostream>
#include <vector>
using namespace std;
string lookAndSay(string str){
    int pre=0;
    string ans;
    for(int iter=1;iter<=str.length();++iter){
        if(iter==str.length() || str[iter]!=str[pre]){
            ans+=to_string(iter-pre)+str[pre];
            pre=iter;
        }
    }
    return ans;
}
void DFS(vector<string>& ans, string str, int index, string tmp){
    if(index == -1){
        ans.push_back(tmp);
        return;
    }
    for(int iter=index;iter>=1;iter-=2){
        string nextTmp = tmp;
        int count = stoi(str.substr(index-iter,iter));
        for(int jter=0;jter<count;++jter){
            nextTmp+=str[index];
        }
        DFS(ans,str,index-iter-1,nextTmp);
    }
}
vector<string> sayAndLock(string str){
    vector<string> ans;
    DFS(ans,str,str.length()-1,"");
    return ans;
}
int main(){
    cout << lookAndSay("111211") << endl;
    for(auto item:sayAndLock("311221")){
        cout << item << endl;
    }
}
