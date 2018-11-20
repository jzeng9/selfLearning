//
// Created by 曾钧麟 on 2018/10/26.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution{
public:
    void longestCommonArray(vector<string> num1, vector<string> num2){
        vector<vector<vector<string>>> dp_array(num1.size()+1,vector<vector<string>>(num2.size()+1,vector<string>()));
        vector<string> ans;
        for(int iter=1;iter<=num1.size();++iter){
            for(int jter=1;jter<=num2.size();++jter){
                if(num1[iter-1]==num2[jter-1]){
                    vector<string> tmp=dp_array[iter-1][jter-1];
                    tmp.push_back(num1[iter-1]);
                    dp_array[iter][jter]=tmp;
                    if(ans.size() < dp_array[iter][jter].size()) ans=dp_array[iter][jter];
                }
            }
        }
        for(auto item:ans)
            cout << item << endl;
    }
};
int main(){
    vector<string> num1={"1","3","2","3","1"};
    vector<string> num2={"4","2","3","1","4"};
    Solution().longestCommonArray(num1,num2);
}

