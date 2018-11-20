#include <iostream>
#include <map>
#include <stack>
using namespace std;
struct Node{
    int sign;
    int number;
    map<string,int> expressionM;
    Node(){
        sign=1; number=0;
    }
};
class Solution {
public:
    string basicCalculatorIV(string expression, map<string,int>& dict) {
        expression = this->Simplify(expression,dict);
        int number=0;
        int results=0;
        int sign=1;
        stack<Node> s;
        map<string,int> expressionM;
        for(int iter=0;iter<expression.length();++iter){
            if(this->isDigit(expression[iter]))
                number = number * 10 + (expression[iter]-'0');
            else if(expression[iter]=='+'){
                results+=sign*number;
                sign=1;
                number=0;
            }
            else if(expression[iter]=='-'){
                results+=sign*number;
                sign=-1;
                number=0;
            }
            else if(this->isChar(expression[iter])){
                int ends=iter+1;
                while(ends<expression.length() && this->isChar(expression[ends])) ends++;
                string tmp=expression.substr(iter,ends-iter);
                expressionM[tmp]=sign;
                iter=ends-1;
            }
            else if(expression[iter]=='('){
                Node n=Node();
                n.sign=sign;
                n.number=results;
                n.expressionM = map<string,int>(expressionM.begin(),expressionM.end());
                s.push(n);
                sign=1;
                results=0;
                number=0;
                expressionM = map<string,int>();
            }
            else if(expression[iter]==')'){
                results+=sign*number;
                number=0;
                sign=1;
                Node n=s.top(); s.pop();
                results = results*n.sign + n.number;
                for(auto item:expressionM)
                    item.second = item.second==1?-1:1;
                for(auto item:n.expressionM)
                    expressionM[item.first]=item.second;
            }
        }
        results+=sign*number;
        string ans=to_string(results);
        for(auto item:expressionM){
            if(item.second==1) ans+="+";
            else ans+="-";
            ans+=item.first;
        }
        return ans;
    }
    string Simplify(string experssion, map<string,int>& dict){
        string ans;
        for(int iter=0;iter<experssion.length();++iter){
            if(this->isChar(experssion[iter])){
                int ends=iter+1;
                while(ends<experssion.length() && this->isChar(experssion[ends])) ends++;
                string tmp=experssion.substr(iter,ends-iter);
                if(dict.find(tmp)!=dict.end())
                    ans+=to_string(dict[tmp]);
                else ans+=tmp;
                iter=ends-1;
            }
            else ans+=experssion[iter];
        }
        return ans;
    }
    bool isChar(char c){
        return c>='a' && c<='z';
    }
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
};

int main(){
    string inputStr = "(e+8)-pressure+3-temperature";
    map<string,int> inputM;
    inputM["e"]=1;
    inputM["temperature"]=5;
    cout << Solution().basicCalculatorIV(inputStr,inputM) << endl;
}