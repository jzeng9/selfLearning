//
// Created by 曾钧麟 on 2018/10/25.
//
#include "iostream"
#include "vector"
#include "queue"
using namespace std;
const vector<pair<int,int>> changes = {{-1,0},{1,0},{0,1},{0,-1}};
struct Node{
    int x;
    int y;
    int count;
    Node(int x,int y, int count){
        this->x=x;
        this->y=y;
        this->count=count;
    }
};
class Solution{
public:
    bool zeroMap(vector<vector<int>>& matrix, int x, int y){
        int count = 0;
        for(int iter=0;iter<matrix.size();++iter){
            for(int jter=0;jter<matrix[0].size();++jter){
                if(matrix[iter][jter]==0) count++;
            }
        }
        int _count = 0;
        DFS(matrix,x,y,_count);
        return _count == count;
    }
    void DFS(vector<vector<int>>& matrix, int x, int y, int& count){
        if(matrix[x][y]==0){
            count++;
            matrix[x][y]=-1;
        }
        for(auto item:changes){
            int _x = x+item.first, _y = y+item.second;
            if(_x>=0 && _x<matrix.size() && _y>=0 && _y<matrix[0].size())
                if(matrix[_x][_y]==0)
                    DFS(matrix,_x,_y,count);
        }
    }
    void zeroMap3(vector<vector<int>>& matrix, int x, int y){
        int maxNow=0;
        int ansX=x,ansY=y;
        Node n(x,y,0);
        queue<Node> q;
        q.push(n);
        while(!q.empty()){
            Node now = q.front(); q.pop();
            matrix[now.x][now.y]=-1;
            if(now.count > maxNow){
                ansX=now.x; ansY=now.y;
                maxNow = now.count;
            }
            for(auto item:changes){
                int _x = now.x+item.first,_y = now.y+item.second;
                cout << _x << " "<< _y << endl;
                if(_x>=0 && _x<matrix.size() && _y >=0 && _y<matrix[0].size()){
                    if(matrix[_x][_y]==0){
                        Node tmp(_x,_y,now.count+1);
                        q.push(tmp);
                        cout << _x << endl;
                    }
                }
            }
        }
        cout << ansX << " " << ansY<<endl;
    }
    void zeroMap2(vector<vector<int>>& matrix, int x, int y, int _x, int _y){
        int sum = 0;
        for(int iter=0;iter<matrix.size();++iter)
            for(int jter=0;jter<matrix[0].size();++jter)
                if(matrix[iter][jter]==1) sum++;
        int ans=matrix.size()*matrix[0].size();
        DFS2(matrix,x,y,0,ans,_x,_y,sum,-1);
    }
    void DFS2(vector<vector<int>> matrix, int x, int y, int count, int& _max, int _x, int _y, int target, int path){
        path++;
        if(matrix[x][y]==1)
            count++;
        if(x==_x && y==_y && count==target){
            _max = min(path,_max);
            return;
        }
        matrix[x][y]=-1;
        for(auto item:changes){
            int new_x=x+item.first,new_y=y+item.second;
            if(new_x>=0 && new_x<matrix.size() && new_y>=0 && new_y<matrix[0].size() && matrix[new_x][new_y]!=-1)
                DFS2(matrix,new_x,new_y,count,_max,_x,_y,target,path);
        }
    }
};
int main(){
    vector<vector<int>> matrix={{0,1,-1, 0},{0,1,-1,0},{0,1,-1,0}};
    vector<vector<int>> matrix2={{0,0,-1, 0},{0,0,-1,0},{0,0,-1,0}};
    Solution().zeroMap3(matrix2,0,0);
}

