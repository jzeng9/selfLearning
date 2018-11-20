//
// Created by 曾钧麟 on 2018/10/27.
//
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Cell{
    int value;
    int level;
    Cell(int v, int l){
        value=v;
        level=l;
    }

};

class Solution{
public:
    void findParents(vector<vector<int>> pairs){
        map<int,vector<int>> m;
        for(auto item:pairs){
            m[item[1]].push_back(item[0]);
        }
        for(auto item:m){
            if(item.second.size() == 0 || item.second.size() == 1) cout << item.first << endl;
        }
    }
    void findParents2(vector<vector<int>> pairs, int x,int y){
        queue<int> q;
        map<int,bool> xvisit,yvisit;
        map<int,vector<int>> m;
        for(auto item:pairs){
            m[item[1]].push_back(item[0]);
        }
        q.push(x);
        while(!q.empty()){
            int temp = q.front(); q.pop();
            xvisit[temp]=true;
            for(int item:m[temp]){
                if(!xvisit[item]){
                    q.push(item);
                }
            }
        }
        q.push(y);
        while(!q.empty()){
            int temp = q.front(); q.pop();
            yvisit[temp]=true;
            if(xvisit[temp]) cout << temp << endl;
            else{
                for(int item:m[temp]){
                    if(xvisit[item]) cout << item << endl;
                    if(!yvisit[item]){
                        q.push(item);
                    }
                }
            }
        }
        return;
    }
    void findParents3(vector<vector<int>> pairs, int x){
        queue<Cell> q;
        // map<int,bool> xvisit,yvisit;
        map<int,vector<int>> m;
        for(auto item:pairs){
            m[item[1]].push_back(item[0]);
        }
        int maxLevel=0,value=0;
        Cell tmp(x,0);
        q.push(tmp);
        while(!q.empty()){
            Cell now = q.front(); q.pop();
            if(now.level > maxLevel){
                maxLevel = now.level;
                value = now.value;
            }
            for(int item:m[now.value]){
                Cell next(item,now.level+1);
                q.push(next);
            }
        }
        cout << value << endl;
        return;
    }
};
int main(){
    vector<vector<int>> input={{1,4},{1,5},{3,6},{6,7},{2,5},{10,2},{10,3}};
    Solution().findParents3(input,4);
}

