#include<iostream>
using namespace std;

int main(){
    string key,answer;
    int score=0,i=0;

    getline(cin,key);
    getline(cin,answer);
    if(key.length()==answer.length()){
        while(i<key.length()){
            if(answer[i]==key[i]){
                score++;
            }
            i++;
        }
        cout << score;
        
    }else{
        cout << "Incomplete answer";
    }
}