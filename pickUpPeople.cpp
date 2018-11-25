//
// Created by 曾钧麟 on 2018/11/22.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<pair<int,int>,int> III;
typedef pair<int,int> II;
// people 2 building 1 drive way 0
const vector<pair<int,int>> changes={{-1,0},{1,0},{0,1},{0,-1}};
int howMany(vector<vector<int>>& matrix, int x, int y, int k){
    vector<vector<int>> tmpMatrix = matrix;
    queue<III> q; q.push({{x,y},0});
    int ans=0;
    while (!q.empty()){
        III tmp = q.front(); q.pop();
        if(tmp.second <= k){
            if(tmpMatrix[tmp.first.first][tmp.first.second] == 2) ans++;
            tmpMatrix[tmp.first.first][tmp.first.second]=-1;
            for(auto item:changes){
                int _x = item.first + tmp.first.first, _y = item.second + tmp.first.second;
                if(_x>=0 && _x<tmpMatrix.size() && _y>=0 && _y<tmpMatrix[0].size()
                   && (tmpMatrix[_x][_y] == 0 || tmpMatrix[_x][_y] == 2)){
                    q.push({{_x,_y},tmp.second+1});
                }
            }
        }
    }
    return ans;
}
void DFS(vector<vector<int>> matrix, int x, int y, int count, int k, vector<II> path, vector<II>& ans, int& ansCount){
    if(matrix[x][y] == 2) count++;
    // cout << x << " " << y << " " << matrix[x][y] << endl;
    // cout << path.size() << endl;
    matrix[x][y]=-1;
    path.push_back({x,y});
    if(count > ansCount){
        ans = path;
        ansCount = count;
    }
    if(path.size() == k) return;
    for(auto item:changes){
        int _x = item.first + x, _y = item.second + y;
        if(_x>=0 && _x<matrix.size() && _y>=0 && _y<matrix[0].size()
           && (matrix[_x][_y] == 0 || matrix[_x][_y] == 2)){
            DFS(matrix,_x,_y,count,k,path,ans,ansCount);
        }
    }
}
vector<II> pickUpMost(vector<vector<int>>& matrix, int x, int y, int k){
    vector<vector<int>> tmpMatrix=matrix;
    vector<II> ans;
    vector<II> tmp;
    int ansCount=0;
    DFS(tmpMatrix,x,y,0,k,tmp,ans,ansCount);
    cout << ansCount << endl;
    for(auto item:ans){
        cout << item.first << " " << item.second << endl;
    }
}
int main(){
    vector<vector<int>> matrix={{0,0,2,1},{0,0,1,2},{0,0,2,1},{0,0,0,0}};
    pickUpMost(matrix,0,0,20);
    // cout << howMany(matrix,0,0,4) << endl;
}

