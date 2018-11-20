//
// Created by 曾钧麟 on 2018/11/8.
//
#include <iostream>
#include <vector>
using namespace std;
string addAnd(string str){
    int index=str.length()-1;
    while(index>=0 && str[index]!=' ') index--;
    str.insert(index," and");
    return str;
}
int main(){
    cout << addAnd("Alice Bob Tom") << endl;
}
