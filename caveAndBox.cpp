//
// Created by 曾钧麟 on 2018/10/31.
//
#include <iostream>
#include <vector>
using namespace std;
void caveAndBox(vector<int> boxes, vector<int> cave){
    int smallHeight=INT_MAX;
    vector<int> simpleCave(cave.size(),INT_MAX);
    for(int iter=cave.size()-1;iter>=0;--iter){
        smallHeight = min(smallHeight,cave[iter]);
        simpleCave=smallHeight;
    }
    sort(boxes.begin(),boxes.end());
    int boxIndex=0;
    for(int iter=0;iter<simpleCave.size();++iter){
        if(simpleCave[iter]>=boxes[boxIndex]){
            boxIndex++;
        }
    }
    return boxIndex;
}

