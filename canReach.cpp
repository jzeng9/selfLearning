//
// Created by 曾钧麟 on 2018/11/7.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
bool canReach(vector<vector<int>>& nums, int x, int y){
    unordered_map<int,unordered_set<int>> m;
    for(auto pairs:nums)
        m[pairs[0]].insert(pairs[1]);
    unordered_set<int> visited;
    queue<int> q; q.push(x);
    while(!q.empty()){
        int temp = q.front(); q.pop();
        if(temp == y) return true;
        visited.insert(temp);
        for(auto item:m[temp]){
            if(visited.find(item)==visited.end()){
                q.push(item);
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> nums={{1,3},{3,4}};
    if(canReach(nums,1,5)) cout << "yes" << endl;
    else cout << "no" << endl;
}

