//
// Created by 曾钧麟 on 2018/11/25.
//
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
vector<int> discountPrice(vector<int>& nums){
    stack<int> s;
    vector<int> ans = nums;
    for(int iter=0;iter<nums.size();++iter){
        if(!s.empty() && nums[iter] <= nums[s.top()]){
            while(!s.empty() && nums[iter] <= nums[s.top()]) {
                ans[s.top()] = nums[s.top()] - nums[iter];
                s.pop();
            }
        }
        s.push(iter);
    }
    return ans;
}
int main(){
    vector<int> intput1={1,3,3,2,5};
    vector<int> intput2={5,4,3,2,1};
    vector<int> output = discountPrice(intput2);
    for(auto item:output) cout << item << " ";
}
