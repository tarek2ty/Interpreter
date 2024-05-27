#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool exists(string c, vector<string> v){
    for(string s:v){
        if(s==c) return true;
    }
    return false;
}
vector<string> tokenize(string line){
    vector<string> special = {"=","+","-","*","/"};
    vector<string> tokens;
    int index=0;
    int i=0;
    string num;
    string l = "";
    for(char c : line){
        l=c;
        if(i==line.length()-1){
            num=line;
            num=num.substr(index,i-index+1);
            //cout<<num<<endl;
            tokens.push_back(num);
        }
        else if(exists(l,special)){
            num=line;
            num=num.substr(index,i-index);
            //cout<<num<<endl;
            tokens.push_back(num);
            tokens.push_back(l);
            index=i+1;
        }
        i++;
    }
    return tokens;
}
int main(){
    string line;
    getline(cin,line);
    //vector<string> special = {"=","+","-","*"};
    vector<string> t = tokenize(line);
    //string l = "";
    //for(char s:line){
    //    l =+ s;
    //    if(exists(l,special))
    //    cout<<l<<endl;}
    for(string tt:t) cout<<tt<<endl;
    return 0;
}
