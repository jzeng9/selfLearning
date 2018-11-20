#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;
int indexOfNum(const string& s){
    int iter=0;
    while(s[iter]>='a' && s[iter]<='z') iter++;
    return iter;
}
struct CompareSet{
    bool operator()(const string& s1, const string& s2){
        int index1 = indexOfNum(s1), index2 = indexOfNum(s2);
        return s1.substr(0,index1)>s2.substr(0,index2) || (s1.substr(0,index1)==s2.substr(0,index2) && stoi(s1.substr(index1,s1.length()-index1))>stoi(s2.substr(index2,s1.length()-index2)));
    }
};
int main(){
    vector<string> inputs={"aaa100","ab1","aaa200"};
    priority_queue<string,vector<string>,CompareSet> pq(inputs.begin(),inputs.end());
    while(!pq.empty()){
        string tmp = pq.top(); pq.pop();
        cout << tmp << endl;
    }
}
