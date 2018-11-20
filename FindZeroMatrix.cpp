//
// Created by 曾钧麟 on 2018/10/25.
//
#include "iostream"
#include "vector"
using namespace std;
typedef pair<int,int> II;
const vector<II> changes={{-1,0},{1,0},{0,1},{0,-1}};
class Solution{
public:
    void findZeroMatrix1(vector<vector<int>>& matrix){
        for(int iter=0;iter<matrix.size();++iter){
            for(int jter=0;jter<matrix[0].size();++jter){
                if(matrix[iter][jter]==0){
                    cout << iter << " " << jter << endl;
                    int _iter=iter+1,_jter=jter+1;
                    while(_iter<matrix.size() && matrix[_iter][jter]==0)_iter++;
                    while(_jter<matrix[0].size() && matrix[iter][_jter]==0)_jter++;
                    cout << _iter-iter <<" "<<_jter-jter << endl;
                    return;
                }
            }
        }
    }
    void findZeroMatrix2(vector<vector<int>>& matrix){
        for(int iter=0;iter<matrix.size();++iter){
            for(int jter=0;jter<matrix[0].size();++jter){
                if(matrix[iter][jter]==0){
                    cout << iter << " " << jter << endl;
                    int _iter=iter+1,_jter=jter+1;
                    while(_iter<matrix.size() && matrix[_iter][jter]==0)_iter++;
                    while(_jter<matrix[0].size() && matrix[iter][_jter]==0)_jter++;
                    cout << _iter-iter <<" "<<_jter-jter << endl;
                    for(int x=iter;x<=_iter-1;++x){
                        for(int y=jter;y<=_jter-1;++y){
                            matrix[x][y]=1;
                        }
                    }
                }
            }
        }
    }
    vector<vector<II>> findZeroMatrix3(vector<vector<int>>& matrix){
        vector<vector<II>> ans;
        for(int iter=0;iter<matrix.size();++iter){
            for(int jter=0;jter<matrix[0].size();++jter){
                if(matrix[iter][jter]==0){
                    vector<II> tmp;
                    setMatrix(matrix,iter,jter,tmp);
                    ans.push_back(tmp);
                }
            }
        }
    }
    void setMatrix(vector<vector<int>>& matrix, int x, int y, vector<II>& line){
        if(matrix[x][y]==0){
            matrix[x][y]=1;
            line.push_back({x,y});
        }
        else return;
        for(auto item:changes){
            int _x=x+item.first,_y=y+item.second;
            if(_x>=0 && _x<matrix.size() && _y>=0 && _y<matrix[0].size())
                setMatrix(matrix,x+item.first,y+item.second,line);
        }
    }
};
int main(){
    vector<vector<int>> testMatrix={{1,1,1,1,1},{1,1,0,0,1},{1,1,0,0,1},{0,0,1,1,1},{0,0,1,1,1}};
    Solution().findZeroMatrix3(testMatrix);
}


