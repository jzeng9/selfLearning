//
// Created by 曾钧麟 on 2018/10/26.
//
#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "queue"
using namespace std;
class Solution{
public:
    void findCommon(vector<vector<string>>& courseList){
        map<string,set<string>> coursePair;
        for(int iter=0;iter<courseList.size();++iter){
            coursePair[courseList[iter][0]].insert(courseList[iter][1]);
        }
        for(auto item1:coursePair){
            for(auto item2:coursePair){
                if(item1.first < item2.first){
                    cout << item1.first << " " << item2.first << endl;
                    for(auto course1:item1.second){
                        if(item2.second.find(course1)!=item2.second.end()){
                            cout << course1 << endl;
                        }
                    }
                }
            }
        }
    }
    void findCommon2(vector<vector<string>>& courseList){
        map<string,vector<string>> coursePair;
        map<string,int> VectIn;
        queue<string> ZeroIn;
        vector<string> ans;
        for(auto item:courseList){
            coursePair[item[0]].push_back(item[1]);
            VectIn[item[1]]++;
            if(coursePair.find(item[1])==coursePair.end()){
                coursePair[item[1]] = vector<string>();
            }
        }
        for(auto item:coursePair)
            if(VectIn[item.first]==0)
                ZeroIn.push(item.first);
        while(!ZeroIn.empty()){
            string course = ZeroIn.front(); ZeroIn.pop();
            ans.push_back(course);
            for(auto item:coursePair[course]){
                VectIn[item]--;
                if(VectIn[item]==0){
                    ZeroIn.push(item);
                }
            }
        }
        for(auto item:ans)
            cout << item << endl;
    }
    void findCommon3(vector<vector<string>>& courseList){
        map<string,vector<string>> coursePair;
        map<string,int> VectIn;
        vector<char> ans;
        for(auto item:courseList){
            coursePair[item[0]].push_back(item[1]);
            VectIn[item[1]]++;
            if(VectIn.find(item[0])==VectIn.end()){
                VectIn[item[0]]=0;
            }
        }
        for(auto item:VectIn){
            if(item.second == 0){
                string tmp = item.first;
                DFS(coursePair, tmp , ans, item.first);
            }
        }
        for(auto item:ans){
            cout << item << endl;
        }
        return;
    }
    void DFS(map<string,vector<string>>& coursePair, string tmp, vector<char>& ans, string now){
        if(coursePair[now].size()==0){
            cout << tmp << endl;
            ans.push_back(tmp[(tmp.length()-1)/2]);
            return;
        }
        for(auto item:coursePair[now]){
            DFS(coursePair,tmp+item,ans,item);
        }
    }
};
int main(){
    vector<vector<string>> input = {{"1","A"},{"2","B"},{"5","E"},{"1","B"},{"2","A"},{"2","E"}};
    vector<vector<string>> input2 = {{"A", "C"}, {"B", "D"}, {"D", "A"},  {"G", "E"}, {"C", "F"}, {"E", "B"}};
    vector<vector<string>> input3 = {{"A", "B"}, {"B", "D"}, {"E","B"},  {"E","C"}, {"C","F"}, {"E","F"}};
    Solution().findCommon3(input3);
}