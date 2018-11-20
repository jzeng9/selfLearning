//
// Created by 曾钧麟 on 2018/11/7.
//
#include <vector>
#include <iostream>
using namespace std;
void diagnoalOutput(vector<vector<int>>& nums){
    for(int iter=0;iter<nums[0].size();++iter){
        int jter=0,tmpIter=iter;
        while(tmpIter>=0){
            cout << nums[jter][tmpIter];
            tmpIter--;
            jter++;
        }
        cout << endl;
    }
    for(int jter=1;jter<nums.size();++jter){
        int iter=nums[0].size()-1,tmpJter=jter;
        while(tmpJter<nums.size()){
            cout << nums[tmpJter][iter];
            tmpJter++;
            iter--;
        }
        cout << endl;
    }
}
int main(){
    vector<vector<int>> ans={{1,2,3},{4,5,6},{7,8,9}};
    diagnoalOutput(ans);
}


