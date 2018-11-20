//
// Created by 曾钧麟 on 2018/11/1.
//
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> II;
vector<II> comprassArray(vector<int> nums){
    vector<II> ans;
    ans.push_back({nums[0],nums[0]});
    for(int iter=1;iter<nums.size();++iter){
        if((nums[iter]-1)==ans[ans.size()-1].second){
            ans[ans.size()-1].second++;
        }
        else{
            ans.push_back({nums[iter],nums[iter]});
        }
    }
    return ans;
}
bool contains(vector<II> nums, int target){
    int l=0,r=nums.size()-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(nums[mid].first<=target && target<=nums[mid].second) return true;
        else if(target<nums[mid].first) r=mid-1;
        else l=mid+1;
    }
    return false;
}
int main(){
    vector<int> nums={2, 3, 4, 6, 8, 9, 11};
    vector<II> comprassedNums=comprassArray(nums);
    for(auto item:comprassedNums){
        cout << item.first << " " << item.second << endl;
    }
    assert(contains(comprassedNums,9));assert(!contains(comprassedNums,12));
}
