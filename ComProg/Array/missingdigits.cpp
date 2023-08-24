#include<iostream>
#include<string>
using namespace std;

int main(){
    string text;
    getline(cin,text);
    char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    string answer;
    for(int i=0;i<text.length();i++){
        for(int j=0;j<10;j++){
            if(text[i]==num[j]&&text[i]!=' '){
                num[j]=' ';
                break;
            }
        }
    }
    for(int i=0;i<10;i++){
        if(num[i]!=' '){
            answer+=num[i];
            answer+=",";
        }
    }
    if(answer.length()!=0){
        cout << answer.substr(0,answer.length()-1);
    }else{
        cout << "None";
    }
    
}