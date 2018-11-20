//
// Created by 曾钧麟 on 2018/11/19.
//
#include <vector>
#include <iostream>
using namespace std;
int findDup(vector<int> nums, int target){
    int start=0;
    if(nums[0]!=target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid-1]<target && target==nums[mid]){
                start = mid;
                break;
            }
            else if(target==nums[mid]) r=mid-1;
            else l=mid+1;
        }
    }
    int ans = 1;
    while(nums[start]==target){
        start++;
        ans++;
    }
    return ans;
}
int main(){
    vector<int> inputs={1, 1, 1, 2, 2, 2, 2, 2, 2, 5, 5, 5, 8, 8};
    cout << findDup(inputs,2) << endl;
}

