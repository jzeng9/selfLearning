//
// Created by 曾钧麟 on 2018/11/29.
//
#include <queue>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
typedef pair<int,int> II;
void DFS(const vector<int>& beautyScore, const unordered_map<int,set<II>>& roadM, int start, int left, int& ans, unordered_set<int> path,int score){
    if(path.find(start)==path.end()){
        score += beautyScore[start];
        path.insert(start);
    }
    if(start == 0) ans = max(score,ans);
    for(auto next:roadM[start]){
        if(left >= next.second){
            DFS(beautyScore,roadM,next.first,left-next.second,ans,path,score);
        }
    }
    return;
}
int beautyScore(int n, vector<int> beautyScore, int m, vector<II> road, vector<int> cost, int minutes){
    int ans=0;
    unordered_map<int,set<II>> roadM;
    unordered_map<int,int> bS;
    for(int iter=0;iter<m;++iter){
        m[road[iter].first].insert({road[iter].second,cost[iter]});
    }
    unordered_set<int> path;
    DFS(beautyScore,roadM,0,minutes,ans,path,0);
    return ans;
}
int main(){

}
