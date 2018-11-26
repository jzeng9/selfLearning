//
// Created by 曾钧麟 on 2018/11/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countPairs1(vector<int> nums, int target){
    unordered_set<int> s(nums.begin(),nums.end());
    int ans=0;
    for(auto item:nums){
        if(s.find(item+target)!=s.end()) ans++;
        if(s.find(item-target)!=s.end()) ans++;
    }
    return ans;
}
int countPairs2(vector<int> nums, int target){
    unordered_set<int> s(nums.begin(),nums.end());
    int ans=0;
    for(auto item:nums){
        if(s.find(item+target)!=s.end()) ans++;
        if(s.find(item-target)!=s.end()) ans++;
    }
    return ans;
}
int main(){

}

