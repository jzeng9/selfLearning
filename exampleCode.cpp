//
// Created by 曾钧麟 on 2018/11/1.
//
#include <iostream>
using namespace std;
int f(int a){
    int t1[] = {-1,0};
    int* t2 = t1 + 1;
    cout << t
    int b = a >> (sizeof(a)*8 - 1);
    cout <<
    cout << b << endl;
    cout << t2[-1]<<endl;
    return (t2[b]^a) - t2[b];
}
int main(){
    cout << f(-8) << endl;
}


