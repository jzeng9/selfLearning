//
// Created by 曾钧麟 on 2018/11/28.
//
#include <time.h>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution{
public:
    void rateLimit(string ip){
        time_t timer;
        time(&timer);
        while(!m[ip].empty() && timer - m[ip].front() > 20) m[ip].pop();
        if(m[ip].size() >= 10) throw "Too Much Call";
        else m[ip].push(timer);
        cout << "Successful Call" << endl;
    }
private:
    unordered_map<string,queue<time_t>> m;
};
int main(){
    Solution s;
    for(int iter=0;iter<11;++iter){
        try {
            s.rateLimit("1");
        } catch(char const* e){
            printf("%s",e);
            cout << e << endl;
        }
    }
}

