//
// Created by 曾钧麟 on 2018/10/27.
//
#include <iostream>
#include <vector>
using namespace std;
class sparseVector{
private:
    vector<double> v;
public:
    sparseVector(){}
    sparseVector(int size):v(size,0){}
    void set(int index, double val){
        if(index >= v.size()){
            throw "IndexOutOfBoundsException";
        } else{
            v[index]=val;
        }
    }
    double get(int index){
        if(index >= v.size()){
            throw "IndexOutOfBoundsException";
        } else{
            return v[index];
        }
    }
    double& operator[](int index){
        if(index >= v.size()){
            throw "IndexOutOfBoundsException";
        } else{
            return v[index];
        }
    }
};
int main(){
    sparseVector v(100);
    v.set(0, 1.0);
    v.set(3, 2.0);
    v.set(80,-4.5);

    cout << v[80] << endl;

    try {

        v.get(101); //
    } catch (const char* t) {
        cout << t << endl;
    }
}
