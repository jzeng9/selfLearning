//
// Created by 曾钧麟 on 2018/11/22.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> II;
struct CompareSet{
    bool operator()(const II& v1, const II& v2){
        return v1.first > v2.first;
    }
};
vector<II> intersection(vector<II> v1, vector<II> v2){
    priority_queue<II,vector<II>,CompareSet> pq;
    for(auto item:v1) pq.push(item);
    for(auto item:v2) pq.push(item);
    vector<II> ans;
    ans.push_back(pq.top()); pq.pop();
    while(!pq.empty()){
        II temp = pq.top(); pq.pop();
        if(temp.first <= ans.back().second) ans[ans.size()-1].second = temp.second;
        else ans.push_back(temp);
    }
    return ans;
}
vector<II> unionIntervals(vector<II> v1, vector<II> v2){
    priority_queue<II,vector<II>,CompareSet> pq1(v1.begin(),v1.end()),pq2(v2.begin(),v2.end());
    vector<II> ans;
    while(!pq1.empty() && !pq2.empty()){
        if(pq2.top().second < pq1.top().first) pq2.pop();
        else if(pq2.top().first > pq1.top().second) pq1.pop();
        else{
            ans.push_back({max(pq1.top().first,pq2.top().first),min(pq1.top().second,pq2.top().second)});
            if(pq1.top().second >= pq2.top().second) pq2.pop();
            else pq1.pop();
        }
    }
    return ans;
}
int main(){
    vector<II> v1 = {{1,2},{4,6}}, v2={{2,4},{5,7}};
    vector<II> interSet = intersection(v1,v2);
    for(auto item:interSet) cout << item.first << " " << item.second << endl;
    vector<II> unionSet = unionIntervals(v1,v2);
    for(auto item:unionSet) cout << item.first << " " << item.second << endl;
}
