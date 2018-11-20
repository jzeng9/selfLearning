//
// Created by 曾钧麟 on 2018/11/7.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<string> decodeWays(string str){
    vector<unordered_set<string>> dp_array(str.length()+1,unordered_set<string>());
    dp_array[str.length()].insert("");
    for(int iter=str.length()-1;iter>=0;--iter){
        if((str[iter]=='1' && iter!=str.length()-1)
        ||(str[iter]=='2' && iter!=str.length()-1 && str[iter+1]<='6')){
            for(auto item:dp_array[iter+2]){
                dp_array[iter].insert((char)(stoi(str.substr(iter,2))-1+'A')+item);
            }
        }
        if(str[iter]!='0'){
            for(auto item:dp_array[iter+1]){
                dp_array[iter].insert((char)(stoi(str.substr(iter,1))-1+'A')+item);
            }
        }
    }
    return dp_array[0];
}
int main(){
    for(auto item:decodeWays("226")){
        cout << item << endl;
    }
}
