//
// Created by 曾钧麟 on 2018/11/7.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
bool canWin(vector<int>& nums, int pos){
    if(nums.size()==1 || pos == 0)
        return true;
    queue<int> q; q.push(pos);
    unordered_set<int> s; s.insert(pos);
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int iter=-nums[now];iter<=nums[now];++iter) {
            if ((now + iter) >= 0 && (now + iter) <= (nums.size() - 1) && s.find(now + iter) == s.end()) {
                if((now + iter) == 0) return true;
                s.insert(now + iter);
                q.push(now + iter);
            }
        }
    }
    return false;
}
int main(){
    vector<int> nums={1, 0, 2, 0, 5, 2, 8, 2};
    if(canWin(nums,2)) cout << "yes" << endl;
    else cout << "no" << endl;
}
