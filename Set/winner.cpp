#include<bits/stdc++.h>
using namespace std;

int main(){
    string win;
    string lose;
    set<string> winner;
    set<string> loser;
    string answer="";
    while(cin >> win){
        cin >> lose;
        winner.insert(win);
        loser.insert(lose);
    }
    for(auto itr=winner.begin();itr!=winner.end();itr++){
        //if(*itr=="Liverpool"){
        //     continue;
        // }else
        if(loser.find(*itr)==loser.end()){
            answer = answer + *itr + " ";
        }
    }
    if(answer.length()==0){
        cout << "None";
    }else{
        cout << answer;
    }
}