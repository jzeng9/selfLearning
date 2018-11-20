#include <iostream>
#include <vector>
#include <map>
//
// Created by 曾钧麟 on 2018/11/1.
//
using namespace std;
int concate(string A, string B){
    map<char,vector<int>> m;
    for(int iter=0;iter<B.length();++iter){
        m[B[iter]].push_back(iter);
    }
    int cnt=1;
    int indexB=-1;
    for(int iter=0;iter<A.length();++iter){
        while(true){
            int mid=0;
            int l=1,r=m[A[iter]].size()-1;
            if(indexB < m[A[iter]][0]){
                indexB = m[A[iter]][0];
                break;
            }
            while(l<=r){
                mid = (l+r)/2;
                if(m[A[iter]][mid]>indexB && m[A[iter]][mid-1]<=indexB) break;
                else if(m[A[iter]][mid]<=indexB) l=mid+1;
                else r=mid-1;
            }
            if(m[A[iter]][mid]>indexB && m[A[iter]][mid-1]<=indexB){
                indexB = m[A[iter]][mid];
                break;
            }
            else{
                cnt++; indexB=-1;
            }
        }
    }
    return cnt;
}

int main(){
    cout << concate("zabaz","azb") << endl;
}

