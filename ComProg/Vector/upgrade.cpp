#include<bits/stdc++.h>
using namespace std;

string update(string in){
    // if(in == "A"){
    //     return "A";
    // }else if(in=="B+"){
    //     return "A";
    // }else if(in=="B"){
    //     return "B+";
    // }else if(in=="C+"){
    //     return "B";
    // }else if(in=="C"){
    //     return "C+";
    // }else if(in=="D+"){
    //     return "C";
    // }else if(in=="D"){
    //     return "D+";
    // }else if(in=="F"){
    //     return "D";
    // }else{
    //     return "F";
    // }
    vector<string> grades = {"A","B+","B","C+","C","D+","D","F"};
    for(int i=0;i<grades.size();i++){
        if(grades[i]==in){
            if(in=="A"){
                return "A";
            }else{
                return grades[i-1];
            }
        }
    }
}
int main(){
    string id,grade;
    vector<pair<string,string>> table;
    while(cin >> id){
        if(id=="q"){
            break;
        }
        cin >> grade;
        table.push_back(make_pair(id,grade));
    }
    string upgrade;
    while(cin >> upgrade){
        for(int i=0;i<table.size();i++){
            if(upgrade==table[i].first){
                table[i].second = update(table[i].second);
            }
        }
    }
    for(int i=0;i<table.size();i++){
        cout << table[i].first << " " << table[i].second << endl;
    }
}