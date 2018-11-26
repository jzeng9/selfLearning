//
// Created by 曾钧麟 on 2018/11/25.
//
#include <vector>
#include <iostream>
using namespace std;
class Solutions{
public:
    bool helper(int x, int y, vector<vector<char>>& matrix, vector<vector<bool>>& visited){
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()) return true;
        if(matrix[x][y] == 'x') return true;
        if(matrix[x][y] == ' ') return false;
        if(matrix[x][y] == 'o') return visited[x][y] || dfs(x,y,matrix,visited);
    }
    bool dfs(int x, int y, vector<vector<char>>& matrix, vector<vector<bool>>& visited){
        if(matrix[x][y] != 'o') return false;
        visited[x][y] = true;
        bool b1 = helper(x-1,y,matrix,visited);
        bool b2 = helper(x+1,y,matrix,visited);
        bool b3 = helper(x,y-1,matrix,visited);
        bool b4 = helper(x,y+1,matrix,visited);
        return b1 && b2 && b3 && b4;
    }
    bool isCaptured(vector<vector<char>>& matrix, int x, int y){
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        return helper(x,y,matrix,visited);
    }
};
int main(){
    vector<vector<char>> inputs = {{'o','x','x',' '},{'x','o','o','x'},{' ','x',' ',' '}};
    if(Solutions().isCaptured(inputs,1,1)) cout << "yes" << endl;
    else cout << "no" << endl;
}

