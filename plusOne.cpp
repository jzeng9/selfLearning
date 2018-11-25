//
// Created by 曾钧麟 on 2018/11/20.
//
#include <iostream>
using namespace std;
string plusOne(string str){
    if(str[0]=='-'){
        //negative
        int remain = -1;
        for(int iter=str.length()-1;iter>0;--iter){
            if(remain == 0) return str;
            else{
                int _new = str[iter]-'0'+remain;
                if(_new < 0) {
                    remain = -1;
                    _new += 10;
                } else{
                    remain = 0;
                }
                str[iter] = (char)(_new + '0');
            }
        }
        if(str[1]=='0') str.erase(1,1);
        if(str.length()==1) return "0";
        return str;
    } else{
        //positive
        int remain = 1;
        for(int iter=str.length()-1;iter>=0;--iter){
            if(remain == 0) return str;
            else{
                int _new = str[iter]-'0'+remain;
                if(_new >= 10) {
                    remain = 1;
                    _new %= 10;
                } else{
                    remain = 0;
                }
                str[iter] = (char)(_new + '0');
            }
        }
        if(remain == 1)
            str.insert(0,"1");
        return str;
    }
}
int main(){
    cout << plusOne("-1") << endl;
    cout << plusOne("999") << endl;
}

