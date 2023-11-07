#include<iostream>
using namespace std;

int main(){
    string input;
    getline(cin,input);
    int i=0;
    while(i<input.length()){
        if(input[i]=='('){
            input[i] = '[';
        }else if(input[i]=='['){
            input[i] = '(';
        }else if(input[i]==')'){
            input[i] = ']';
        }else if(input[i]==']'){
            input[i] = ')';
        }
        i++;
    }

    cout << input;
}