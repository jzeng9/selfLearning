//
// Created by 曾钧麟 on 2018/11/26.
//
#include <iostream>
#include <vector>
using namespace std;
void times(vector<int>& nums, int n){
    int remain =  0;
    for(int iter=nums.size()-1;iter>=0;--iter){
        int value = n*nums[iter]+remain;
        nums[iter] = value % 10;
        remain = value / 10;
    }
    while(remain!=0){
        nums.insert(nums.begin(),remain%10);
        remain /= 10;
    }
}
vector<int> factorial(int n){
    vector<int> ans={1};
    for(int iter=2;iter<=n;++iter){
        times(ans,iter);
    }
    return ans;
}
int  main(){
    vector<int> ans =  factorial(20);
    for(auto item:ans) cout << item;
}

