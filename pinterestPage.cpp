//
// Created by 曾钧麟 on 2018/11/8.
//
#include <list>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pin{
    int score;
    int length;
    Pin(int _score,int _length){
        score = _score; length = _length;
    }
};
typedef pair<int,int> II;
struct CompareSet{
    bool operator()(II const& i1, II const& i2){
        return i1.first > i2.first || (i1.first == i2.first && i1.second>i2.second);
    }
};
struct ComparePin{
    bool operator()(Pin const& p1, Pin const& p2){
        return p1.score < p2.score;
    }
};
vector<vector<Pin>> sortedToPage(vector<Pin> pins,int column){
    // priority_queue
    vector<vector<Pin>> ans(column);
    priority_queue<II,vector<II>,CompareSet> pq;
    for(int iter=0;iter<column;++iter){
        pq.push({0,iter});
    }
    for(auto item:pins){
        int theColumn = pq.top().second, theLength = pq.top().first;
        pq.pop();
        ans[theColumn].push_back(item);
        pq.push({theLength+item.length,theColumn});
    }
    return ans;
}
vector<vector<Pin>> unsortedToPage(vector<Pin> pins,int column){
    vector<vector<Pin>> ans(column);
    priority_queue<II,vector<II>,CompareSet> pq;
    priority_queue<Pin,vector<Pin>,ComparePin> pinsPq(pins.begin(),pins.end());
    for(int iter=0;iter<column;++iter){
        pq.push({0,iter});
    }
    while(!pinsPq.empty()){
        Pin item = pinsPq.top(); pinsPq.pop();
        int theColumn = pq.top().second, theLength = pq.top().first;
        pq.pop();
        ans[theColumn].push_back(item);
        pq.push({theLength+item.length,theColumn});
    }
    return ans;
}
int main(){
    vector<Pin> pins;
//    pins.push_back(Pin(1,100));
//    pins.push_back(Pin(2,200));
//    pins.push_back(Pin(3,300));
//    pins.push_back(Pin(4,400));
//    pins.push_back(Pin(5,500));
//    pins.push_back(Pin(6,600));
//    pins.push_back(Pin(7,700));
    pins.push_back(Pin(1,100));
    pins.push_back(Pin(2,200));
    pins.push_back(Pin(3,300));
    pins.push_back(Pin(4,400));
    pins.push_back(Pin(5,500));
    pins.push_back(Pin(6,600));
    pins.push_back(Pin(7,700));
    for(auto item:unsortedToPage(pins,3)){
        for(auto pin:item){
            cout << pin.score << " ";
        }
        cout << endl;
    }
}

